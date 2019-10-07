//
//  AppDelegate.swift
//  NearSample
//
//  Created by francesco.leoni on 13/11/17.
//  Copyright © 2017 Near Srl. All rights reserved.
//

import UIKit
import UserNotifications
import NearITSDKSwift
import NearUIBinding

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        let apiKey = "eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJwcGVHSGthM0U2dExWT0pSNzFJNUJQSXJCbVc0YXN1ZVQtcGFxRlBhTnQ0PSIsImlhdCI6MTUxNzM5NjMwOSwiZXhwIjoxODMyOTc1OTk5LCJkYXRhIjp7ImFjY291bnQiOnsiaWQiOiJkNjQzZmMzNi0xMzQ1LTRkZjQtOWVkYy0xYzFhZmJlZTczMTYiLCJyb2xlX2tleSI6ImFwcCJ9fX0.5Br6s69VA7PtONNYG3YoYKsRp9JcPujyTPvoQKR-sD0"
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
    
    func application(_ app: UIApplication, open url: URL, options: [UIApplication.OpenURLOptionsKey : Any] = [:]) -> Bool {
        // setup test device
        return NearManager.shared.application(app, open: url, options: options)
    }
    
    func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
        // send push token to NearIT servers
        NearManager.shared.setDeviceToken(deviceToken)
    }
    
    
}

extension AppDelegate: UNUserNotificationCenterDelegate {
    
    func userNotificationCenter(_ center: UNUserNotificationCenter, willPresent notification: UNNotification, withCompletionHandler completionHandler: @escaping (UNNotificationPresentationOptions) -> Void) {
        NearManager.shared.userNotificationCenter(center, willPresent: notification, withCompletionHandler: completionHandler)
    }
    
    func userNotificationCenter(_ center: UNUserNotificationCenter, didReceive response: UNNotificationResponse, withCompletionHandler completionHandler: @escaping () -> Void) {
        let isNearNotification = NearManager.shared.showContentFrom(response) { (content, trackingInfo, error) in
            if let error = error {
                // there was an error
            }
        }
        completionHandler()
    }
}
