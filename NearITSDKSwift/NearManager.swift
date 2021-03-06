//
//  NearManager.swift
//  NearITSDK
//
//  Created by Francesco Leoni on 27/03/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

import UIKit
import NearITSDK
import UserNotifications

public enum NearRecipeTracking : String {
    case received = "notified"
    case opened = "engaged"
    case ctaTapped = "cta_opened"
}

public protocol NearManagerDelegate {
    func manager(_ manager: NearManager, eventWithContent content: Any, trackingInfo: NITTrackingInfo);
    func manager(_ manager: NearManager, eventFailureWithError error: Error);
    func manager(_ manager: NearManager, alertWantsToShowContent content: Any, trackingInfo: NITTrackingInfo);
}

public protocol NearManagerNotificationDelegate {
    func manager(_ manager: NearManager, updatedHistoryWith items: [NITHistoryItem]?)
}

public final class NearManager: NSObject, NITManagerDelegate, NITNotificationUpdateDelegate {
    private var manager: NITManager!
    public var delegate: NearManagerDelegate?
    
    public var notificationDelegate: NearManagerNotificationDelegate? {
        didSet {
            // only add an instance as a notif delegate to avoid refresh on start ups
            NearManager.shared.manager.notificationDelegate = self
        }
    }
    
    @available(*, deprecated, message: "Use profileId(completionHandler) instead.")
    public var profileId: String? {
        get {
            return manager.profileId()
        }
    }
    
    public var showBackgroundNotification: Bool {
        get {
            return manager.showBackgroundNotification
        }
        set(show) {
            manager.showBackgroundNotification = show
        }
    }
    public var showForegroundNotification: Bool {
        get {
            return manager.showForegroundNotification
        }
        set(show) {
            manager.showForegroundNotification = show
        }
    }
    public static let shared: NearManager = {
        let nearManager = NearManager()
        nearManager.manager = NITManager.default()
        nearManager.manager.delegate = nearManager
        return nearManager
    }()
    
    public class func setup(apiKey: String) {
        NITManager.setup(withApiKey: apiKey)
    }
    
    public func start() {
        manager.start()
    }
    
    public func stop() {
        manager.stop()
    }
    
    public func setDeviceToken(_ token: Data) {
        manager.setDeviceTokenWith(token)
    }
    
    @available(*, deprecated, message: "Use background fetch feature for optimized data refresh.")
    public func refreshConfig(completionHandler: ((Error?) -> Void)?) {
        manager.refreshConfig(completionHandler: completionHandler)
    }
    
    public func processRecipeSimple(_ userInfo: [AnyHashable : Any]) -> Bool {
        if let ui = userInfo as? [String : Any] {
            return manager.processRecipeSimple(userInfo: ui)
        }
        return false
    }
    
    @available(iOS 10.0, *)
    public func userNotificationCenter(_ center: UNUserNotificationCenter, willPresent notification: UNNotification, withCompletionHandler completionHandler: @escaping (UNNotificationPresentationOptions) -> Void) {
        manager.userNotificationCenter(center, willPresent: notification) { (options) in
            completionHandler(options)
        }
    }
    
    @available(iOS 10.0, *)
    public func getContentFrom(_ response: UNNotificationResponse, completion: ((NITReactionBundle?, NITTrackingInfo?, Error?) -> Void)?) -> Bool {
        let userInfo = response.notification.request.content.userInfo
        return self.getContentFrom(userInfo: userInfo, completion: completion)
    }
    
    public func getContentFrom(userInfo: [AnyHashable: Any], completion: ((NITReactionBundle?, NITTrackingInfo?, Error?) -> Void)?) -> Bool {
        if let _ = userInfo as? [String : Any] {
            return manager.getContentFromUserInfo(userInfo, completion: { (content, trackingInfo, error) in
                if completion != nil {
                    completion!(content, trackingInfo, error)
                }
            })
        }
        return false
    }
    
    @available(iOS, introduced: 10.0, deprecated, renamed: "getContent")
    public func processRecipeFrom(_ response: UNNotificationResponse, completion: ((NITReactionBundle?, NITTrackingInfo?, Error?) -> Void)?) -> Bool {
        return getContentFrom(response, completion: completion)
    }
    
    @available(*, deprecated, renamed: "getContent")
    public func processRecipe(_ userInfo: [AnyHashable : Any], completion: ((NITReactionBundle?, NITTrackingInfo?, Error?) -> Void)?) -> Bool {
        return self.getContentFrom(userInfo: userInfo, completion: completion)
    }
    
    public func sendTracking(_ trackingInfo: NITTrackingInfo?, event: String?) {
        manager.sendTracking(with: trackingInfo, event: event)
    }
    
    @available(*, deprecated, message: "Use setUserData(key:value:) instead.")
    public func setUserData(_ key: String, value: String?, completionHandler: ((Error?) -> Void)?) {
        manager.setUserDataWithKey(key, value: value, completionHandler: completionHandler)
    }
    
    @available(*, deprecated, message: "use setUserData(\"MY_KEY\", value:\"MY_VALUE\") for each value")
    public func setBatchUserData(_ valuesDictionary : [String : Any], completionHandler: ((Error?) -> Void)?) {
        manager.setBatchUserDataWith(valuesDictionary, completionHandler: completionHandler)
    }
    
    @available(*, deprecated, renamed: "setUserData(key:value:)")
    public func setDeferredUserData(_ key: String, value: String?) {
        self.setUserData(key, value: value)
    }
    
    public func setUserData(_ key: String, value: String?) {
        manager.setUserDataWithKey(key, value: value)
    }
  
    public func setUserData(_ key: String, multiValue: [String : Bool]?) {
        if let multiValue = multiValue {
            var numberMultiValue = [String: NSNumber]()
            multiValue.forEach { (arg: (key: String, value: Bool)) in
                let (key, value) = arg
                numberMultiValue[key] = NSNumber.init(booleanLiteral: value)
            }
            manager.setUserDataWithKey(key, multiValue: numberMultiValue)
        } else {
            manager.setUserDataWithKey(key, multiValue: nil)
        }
    }
    
    public func getUserData(_ completionHandler: (([String: Any]?, Error?) -> Void)?) {
        guard let handler = completionHandler else { return }
        manager.getUserData(completionHandler: handler)
    }
    
    public func sendEvent(_ event: NITEvent, completionHandler: ((Error?) -> Void)?) {
        manager.sendEvent(with: event, completionHandler: completionHandler)
    }
    
    public func coupons(_ completionHandler: (([NITCoupon]?, Error?) -> Void)?) {
        manager.coupons(completionHandler: completionHandler)
    }
    
    @available(*, deprecated, message: "Use resetProfile(completionHandler:) instead.")
    public func resetProfile() {
        manager.resetProfile()
    }
    
    public func resetProfile(completionHandler: @escaping (String?, Error?) -> Void) {
        manager.resetProfile { (profileId, error) in
            completionHandler(profileId, error)
        }
    }
    
    public func profileId(completionHandler: @escaping (String?, Error?) -> Void) {
        manager.profileId { (profileId, error) in
            completionHandler(profileId, error)
        }
    }
    
    public func setProfile(id: String) {
        manager.setProfileId(id)
    }
    
    public func recipes(_ completionHandler:(([NITRecipe]?, Error?) -> Void)?) {
        manager.recipes { (recipes, error) in
            if let handler = completionHandler {
                handler(recipes, error)
            }
        }
    }
    
    public func processRecipe(id: String) {
        manager.processRecipe(withId: id)
    }
    
    public func optOut(_ completionHandler: @escaping (Bool) -> Void) {
        manager.optOut { (success) in
            completionHandler(success)
        }
    }
    
    @available(*, deprecated, renamed: "triggerInAppEvent(key:)")
    public func processCustomTrigger(_ key: String) {
        self.triggerInAppEvent(key)
    }
    
    public func triggerInAppEvent(_ key: String) {
        manager.triggerInAppEvent(withKey: key)
    }
    
    public func notificationHistory(_ completion: @escaping ([NITHistoryItem]?, Error?) -> Void) {
        manager.history { (items, error) in
            completion(items, error)
        }
    }
    
    public func application(_ application: UIApplication, performFetchWithCompletionHandler completionHandler: @escaping (UIBackgroundFetchResult) -> Void) {
        manager.application(application) { (result) in
            completionHandler(result)
        }
    }
    
    public func application(_ app: UIApplication, open url: URL, options: [UIApplication.OpenURLOptionsKey : Any] = [:]) -> Bool {
        return manager.application(app, open: url, options: options)
    }
    
    public func parseContent(_ content: Any, trackingInfo: NITTrackingInfo, contentDelegate: NITContentDelegate) {
        manager.parseContent(content, trackingInfo: trackingInfo, contentDelegate: contentDelegate)
    }
    
    public func manager(_ manager: NITManager, eventFailureWithError error: Error) {
        delegate?.manager(self, eventFailureWithError: error);
    }
    
    public func manager(_ manager: NITManager, eventWithContent content: Any, trackingInfo: NITTrackingInfo) {
        delegate?.manager(self, eventWithContent: content, trackingInfo: trackingInfo)
    }
    
    public func manager(_ manager: NITManager, alertWantsToShowContent content: Any, trackingInfo: NITTrackingInfo) {
        delegate?.manager(self, alertWantsToShowContent: content, trackingInfo: trackingInfo)
    }
    
    public func historyUpdated(with items: [NITHistoryItem]?) {
        self.notificationDelegate?.manager(self, updatedHistoryWith: items)
    }
    
    public func markNotficationHistoryAsOld() {
        manager.markNotificationHistoryAsOld()
    }
    
    @available(iOS 10.0, *)
    public func update(with notification: UNNotification) {
        manager.update(with: notification)
    }
}
