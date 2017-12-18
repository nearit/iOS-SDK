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

## Auto update
To keep your app up to date even if a user is not using the app, you have to call the sdk method developed to support the iOS feature called **background fetch**.

First thing to do is to enable the feature **background fetch** in the capabilities section of your app project.

![capabilities](images/backgroundfetch_capabilities.png "")

In your code you need to call the method *application:performFetchWithCompletionHandler* of the Near manager in your AppDelegate, inside the iOS method *application:performFetchWithCompletionHandler*.

<div class="code-swift">
// Call the method application(_ application: UIApplication, performFetchWithCompletionHandler completionHandler: @escaping (UIBackgroundFetchResult) -> Void) on the Near manager instance
func application(_ application: UIApplication, performFetchWithCompletionHandler completionHandler: @escaping (UIBackgroundFetchResult) -> Void) {
    nearManager.application(application) { (fetchResult) in
        completionHandler(fetchResult)
    }
}
</div>
<div class="code-objc">
- (void)application:(UIApplication *)application performFetchWithCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
    [nearManager application:application performFetchWithCompletionHandler:^(UIBackgroundFetchResult result) {
        completionHandler(result);
    }];
}
</div>

Then in the `application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool` method of your AppDelegate class, set the minimun background fetch interval (2 hours is recommended):

<div class="code-swift">
func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
    ...
    application.setMinimumBackgroundFetchInterval(7200) // 2 hours
    ...
}
</div>
<div class="code-objc">
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    ...
    [application setMinimumBackgroundFetchInterval:7200]; // 2 hours
    ...
}
</div>
