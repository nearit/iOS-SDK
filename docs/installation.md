# Installation #

Minimum Requirements: **Deployment target iOS 9**

To start using the SDK, include this in your app *Podfile*

<div class="code-swift">
pod 'NearITSDKSwift' // For Swift
</div>
<div class="code-objc">
pod 'NearITSDK' // For Objective-C
</div>
 
In the `application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool` method of your AppDelegate class, set the API token to the SDK a String


<div class="code-swift">
import NearITSDKSwift

func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
	...
    NearManager.setup(apiKey: "&lt;your API token here&gt;")
	let manager = NearManager.shared
	...
}
</div>
<div class="code-objc">
#import &lt;NearITSDK/NearITSDK.h&gt;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    ...
    [NITManager setupWithApiKey:@"&lt;your API token here&gt;"];
    NITManager *manager = [NITManager defaultManager];
    ...
}
</div>

You can find the API key on <a href="https://go.nearit.com/" target="_blank">**NearIT web interface**</a>, under the "**Settings> SDK Integration**" section.

<br>
##Manual Configuration Refresh##

The SDK **initialization is done automatically** and handles the task of syncing the recipes with our servers when your app starts up.
<br>However, if you need to sync the recipes configuration more often, you can call this method:

<div class="code-swift">
manager.refreshConfig(completionHandler: { (error) in
    ...
})
</div>
<div class="code-objc">
[manager refreshConfigWithCompletionHandler:^(NSError* error) {
    ...
}];
</div>

If the refreshConfig has succeeded, 'error' is nil.
