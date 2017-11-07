# Local background notification

By default the SDK (from version 0.9.33) gives you local iOS notification when your app is in background.

When the user tap the notification you need to react and handle the local notification to show the right content for the user.

Rememeber to ask for the notification permissions.

## Handle local notification from iOS 10

First you need to set the delegate for the `UNUserNotificationCenter`, with the code below you can react to a notification tap.

<div class="code-swift">
func userNotificationCenter(_ center: UNUserNotificationCenter, didReceive response: UNNotificationResponse, withCompletionHandler completionHandler: @escaping () -> Void) {
    let userInfo = response.notification.request.content.userInfo
    let isNear = manager.processRecipe(userInfo) { (content, recipe, error) in
        if let content = content, let recipe = recipe {
            self.handleNearContent(content: content, recipe: recipe)
        }
    }
    print("Is a Near local notification: \(isNear)");
    completionHandler()
}
</div>
<div class="code-objc">
- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void (^)())completionHandler {
    NSDictionary *userInfo = response.notification.request.content.userInfo;
    BOOL isNear = [manager processRecipeWithUserInfo:response completionHandler:^(id  _Nullable content, NITRecipe * _Nullable recipe, NSError * _Nullable error) {
        if (content != nil && recipe != nil) {
            [self handleNearContentWithContent:content recipe:recipe];
        }
    }];
    NSLog(@"Is a Near local notification: %d", isNear);
    completionHandler();
}
</div>

The result of `handleLocalNotificationResponse` means if a notification is from Near (true) or not (false).

## Handle local notification for iOS 9

In iOS 9 you only need to implement the `didReceiveLocalNotification` (`didReceive` in Swift) to handle the tap on a notification.

<div class="code-swift">
func application(_ application: UIApplication, didReceive notification: UILocalNotification) {
    if let userInfo = notification.userInfo {
        let isNear = manager.processRecipe(userInfo) { (content, recipe, error) in
        if let content = content, let recipe = recipe {
            self.handleNearContent(content: content, recipe: recipe)
        }
        print("Is a Near local notification: \(isNear)");
    }
}
</div>
<div class="code-objc">
- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification {
    BOOL isNear = [manager processRecipeWithUserInfo:notification.userInfo completionHandler:^(id  _Nullable content, NITRecipe * _Nullable recipe, NSError * _Nullable error) {
        if (content != nil && recipe != nil) {
            [self handleNearContentWithContent:content recipe:recipe];
        }
    }];

    NSLog(@"Is a Near local notification: %d", isNear);
}
</div>

The result of `handleLocalNotification` means if a notification is from Near (true) or not (false).

## How to disable local background notification

You need to set "false" the property `showBackgroundNotification` in the Near Manager instance.
