# Push Notifications

<br>
### 1) Enable push capabilities

Inside Xcode, navigate to the “**Capabilities**” tab of your app. You will need to enable “**Push Notifications**”.

![capabilities](push_help/capabilities.png "")

<br>
### 2) Generating a Certificate Request

2.1) Launch the “**Keychain Access**” app on your Mac.

2.2) Select “**Keychain Access> Certificate Assistant> Request a Certificate From a Certificate Authority**”.

![keychain_request](push_help/pushtutorial00.png "")

2.3) Enter your e-mail, select “**Save to disk**” and press “**Continue**”. You should get a .certSigningRequest file.

![save_request](push_help/pushtutorial01.png "")


<br>
### 3) Get the Certificate

3.1 Open <a href="https://developer.apple.com/account/ios/identifier/bundle" target="_blank">**developer.apple.com**</a>, select your app and press “**Edit**”.

![edit_app](push_help/pushtutorial02.gif "")

3.2 Scroll down the page and enable Push Notifications. Press “**Create Certificate**” (Usually you would want to create a *production* certificate).

![enable_push](push_help/pushtutorial03.gif "")

3.3 You should find yourself in the “Add iOS Certificate” wizard. Press “**Continue**”.

![add_certificate](push_help/pushtutorial04.png "")

3.4 Press “**Choose File**” and upload the .certSigningRequest file you generated previously (chapter 2.3)

![add_certificate](push_help/pushtutorial05.png "")

3.5 Your certificate is ready. Press “**Download**” to get the .cer file.

![get_certificate](push_help/pushtutorial06.png "")


<br>
### 4) Upload a .p12 Key to NearIT

4.1 Click on the .cer certificate you generated previously (chapter 3.5). It will open the “**Keychain Access**” app on your mac.


4.2 Find your certificate, click on it and select “**Export**”. Enter a password, you will get a .p12 file.

![export_p12](push_help/pushtutorial08.png "")


4.3 Open [NearIT](https://go.nearit.com), select your app and navigate to “**Settings> Push Settings**”. Upload your .p12 under the “**Setup iOS push notifications**” block. You will be prompted to enter the password you have chosen previously (chapter 4.2)

![export_p12](push_help/09.gif "")


<br>
### 5) Get the device token

In your app code, ask for the token:

<div class="code-swift">
func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool
    application.registerForRemoteNotifications()
    // ...
}
</div>
<div class="code-objc">
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [application registerForRemoteNotifications];
    // ...
}
</div>

When you get the token, just give it to the SDK:

<div class="code-swift">
func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
    manager.setDeviceToken(token)
}
</div>
<div class="code-objc">
- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    [manager setDeviceTokenWithData:token];
}
</div>

To learn how to deal with in-app content see this [section](handle-content.md).
