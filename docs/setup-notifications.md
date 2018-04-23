## Notification Setup

This setup allows NearIT to show notifications automatically.<br>
When an user taps on a notification, an "**handleNearContent**" method will be called to let you manage in-app content presentation.

___
**Warning**: Remember to request **notification permission** (like in the sample code below), otherwise you will not receive any notification.
___

### iOS10+
If your app is closed or in background, a system notification will be added to the Notification Center.
If your app is in foreground, the notification will be shown inside the app.

<div class="code-swift">
// AppDelegate
func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
    ...
    UNUserNotificationCenter.current().requestAuthorization(options:[.badge, .alert, .sound]) { (granted, error) in
        // Enable or disable features based on authorization.
    }
    UNUserNotificationCenter.current().delegate = self
}

...
@available(iOS 10.0, *)
extension AppDelegate : UNUserNotificationCenterDelegate {
    
    func userNotificationCenter(_ center: UNUserNotificationCenter, willPresent notification: UNNotification, withCompletionHandler completionHandler: @escaping (UNNotificationPresentationOptions) -> Void) {
        completionHandler(.alert)
    }
    
    func userNotificationCenter(_ center: UNUserNotificationCenter, didReceive response: UNNotificationResponse, withCompletionHandler completionHandler: @escaping () -> Void) {
        let userInfo = response.notification.request.content.userInfo
        let isNearNotification = NearManager.shared.processRecipe(userInfo) { (content, trackingInfo, error) in
            if let content = content, let trackingInfo = trackingInfo {
                self.handleNearContent(content: content)
            }
        }
        completionHandler()
    }
}
</div>
<div class="code-objc">
// Declare a UNUserNotificationCenterDelegate
@interface AppDelegate ()&lt;UNUserNotificationCenterDelegate&gt;

@end

// Set the delegate in didFinishLaunching
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [UNUserNotificationCenter currentNotificationCenter].delegate = self;
    [[UNUserNotificationCenter currentNotificationCenter] requestAuthorizationWithOptions:UNAuthorizationOptionAlert | UNAuthorizationOptionBadge | UNAuthorizationOptionSound completionHandler:^(BOOL granted, NSError * _Nullable error) {
        // Enable or disable features based on authorization.
    }];
    return YES;
}

// UNUserNotificationCenterDelegate implementation
- (void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler {
    completionHandler(UNNotificationPresentationOptionAlert);
}

- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void (^)(void))completionHandler {
    NSDictionary *userInfo = response.notification.request.content.userInfo;
    BOOL isNearNotification = [[NITManager defaultManager] processRecipeWithUserInfo:userInfo completion:^(NITReactionBundle * _Nullable content, NITTrackingInfo * _Nullable trackingInfo, NSError * _Nullable error) {
        if (content) {
            [self handleNearContent:content];
        }
    }];
}

</div>

<br>

### iOS9
If your app is closed or in background, a system notification will be added to the Notification Center.
If your app is in foreground, an alert will be shown.

<div class="code-swift">
// AppDelegate
func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
    ...
    let settings = UIUserNotificationSettings(types: [.sound, .alert, .badge], categories: nil)
    application.registerUserNotificationSettings(settings)
}

// Manage tap on remote notifications
func application(_ application: UIApplication, didReceiveRemoteNotification userInfo: [AnyHashable : Any]) {
    let isNearNotification = NearManager.shared.processRecipe(userInfo, completion: { (content, trackingInfo, error) in
        if let content = content {
            self.handleNearContent(content: content)
        }
    })
}

// Manage tap on local notifications
func application(_ application: UIApplication, didReceive notification: UILocalNotification) {
    if let userInfo = notification.userInfo {
        let isNearNotification = NearManager.shared.processRecipe(userInfo, completion: { (content, trackingInfo, error) in
            if let content = content {
                self.handleNearContent(content: content)
            }
        })
    }
}

// Manage tap on iOS9 in-app alert
extension AppDelegate: NearManagerDelegate {

    func manager(_ manager: NearManager, alertWantsToShowContent content: Any) {
        ...
        handleNearContent(content: content)
    }

}
</div>
<div class="code-objc">
// AppDelegate
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    ...
    [application registerUserNotificationSettings:[UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeAlert | UIUserNotificationTypeBadge | UIUserNotificationTypeSound categories:nil]];
}

// Manage tap on remote notifications
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
    BOOL isNearNotification = [[NITManager defaultManager] processRecipeWithUserInfo:userInfo completion:^(NITReactionBundle * _Nullable content, NITTrackingInfo * _Nullable trackingInfo, NSError * _Nullable error) {
        if (content) {
            [self handleNearContent:content];
        }
    }];
}

// Manage tap on local notifications
- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification {
    BOOL isNearNotification = [[NITManager defaultManager] processRecipeWithUserInfo:notification.userInfo completion:^(NITReactionBundle * _Nullable content, NITTrackingInfo * _Nullable trackingInfo, NSError * _Nullable error) {
        if (content) {
            [self handleNearContent:content];
        }
    }];
}

// NITManagerDelegate implementation
- (void)manager:(NITManager *)manager alertWantsToShowContent:(id)content {
    [self handleNearContent:content];
}

</div>

<br>If you want to customize your notifications, see this [section](customize-notifications.md).

<br>
## Trackings
NearIT allows to track user engagement events on recipes. Any recipe has at least two default events:

  - **Received**: the user *received* a notification
  - **Opened**: the user *tapped* on the notification
  
Usually the SDK tracks those events automatically, but if you write custom code to show notification or content please make sure that at least the "**received**" event is tracked.
<br>**Warning:** Failing in tracking this event cause some NearIT features to not work.


You can track **default or custom events** using the "**sendTracking**" method:
 
<div class="code-swift">
// received - notification received
manager.sendTracking(trackingInfo, event: NearRecipeTracking.received.rawValue)

// opened - notification tapped
manager.sendTracking(trackingInfo, event: NearRecipeTracking.opened.rawValue)

// custom recipe event
manager.sendTracking(trackingInfo, event: "my awesome custom event")
</div>
<div class="code-objc">
// received - notified received
[manager sendTrackingWithTrackingInfo:trackingInfo event:NITRecipeReceived];

// opened - notification tapped
[manager sendTrackingWithTrackingInfo:trackingInfo event:NITRecipeOpened];

// custom recipe event
[manager sendTrackingWithTrackingInfo:trackingInfo event:@"my awesome custom event"];
</div>

### Content CTA conversion trackings

When manually dealing with *CTA* objects from the **Content with attachments** you can add this custom trigger on the recipe to track the click conversions on the link:

<div class="code-swift">
manager.sendTracking(trackingInfo, event: NearRecipeTracking.ctaTapped.rawValue)
</div>
<div class="code-objc">
[manager sendTrackingWithTrackingInfo:trackingInfo event:NITRecipeCtaTapped];
</div>
