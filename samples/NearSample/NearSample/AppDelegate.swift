//
//  AppDelegate.swift
//  NearSample
//
//  Created by francesco.leoni on 13/11/17.
//  Copyright © 2017 Near Srl. All rights reserved.
//

import UIKit
import NearITSDKSwift
import UserNotifications
import NearUIBinding

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?


    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        
        let apiKey = "your-api-key"
        NearManager.setup(apiKey: apiKey)
        
        // enable NearIT logs
        NITLog.setLogEnabled(true)
        
        // set auto-update fetch interval
        application.setMinimumBackgroundFetchInterval(7200) // 2 hours
        
        // request device token
        application.registerForRemoteNotifications()
        
        UNUserNotificationCenter.current().delegate = self
        
        return true
    }

    func application(_ application: UIApplication, performFetchWithCompletionHandler completionHandler: @escaping (UIBackgroundFetchResult) -> Void) {
        // setup auto-update
        NearManager.shared.application(application) { (fetchResult) in
            completionHandler(fetchResult)
        }
    }
    
    func application(_ app: UIApplication, open url: URL, options: [UIApplicationOpenURLOptionsKey : Any] = [:]) -> Bool {
        return NearManager.shared.application(app, open: url, options: options)
    }
    
    func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
        NearManager.shared.setDeviceToken(deviceToken)
    }
    
    func handleNearContent(_ content: Any, trackingInfo: NITTrackingInfo? = nil) {
        if let content = content as? NITContent {
            let contentVC = NITContentViewController(content: content)
            contentVC.show()
        } else if let feedback = content as? NITFeedback {
            let feedbackVC = NITFeedbackViewController(feedback: feedback)
            feedbackVC.show()
        } else if let coupon = content as? NITCoupon {
            let couponVC = NITCouponViewController(coupon: coupon)
            couponVC.show()
        } else if let simple = content as? NITSimpleNotification {
            // there's no content attached to the system notification that was just pressed
        } else if let customJson = content as? NITCustomJSON {
            // handle your custom json
        }
    }
    
}

extension AppDelegate: UNUserNotificationCenterDelegate {
    
    func userNotificationCenter(_ center: UNUserNotificationCenter, willPresent notification: UNNotification, withCompletionHandler completionHandler: @escaping (UNNotificationPresentationOptions) -> Void) {
        completionHandler(.alert)
    }
    
    func userNotificationCenter(_ center: UNUserNotificationCenter, didReceive response: UNNotificationResponse, withCompletionHandler completionHandler: @escaping () -> Void) {
        let isNearNotification = NearManager.shared.processRecipeFrom(response) { (content, trackingInfo, error) in
            if let content = content, let trackingInfo = trackingInfo {
                self.handleNearContent(content, trackingInfo: trackingInfo)
            }
        }
        completionHandler()
    }
}
