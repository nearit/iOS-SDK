# Customize Notifications

## Custom content notifications

If you want to customize the default notifications behavior you need to set  `showBackgroundNotification` and  `showForegroundNotification` properties of the NearManager to  `false`.<br/>
Whenever you receive a content, you should handle it in the  `NearManagerDelegate`.

<div class="code-swift">
{
    ...
    manager.delegate = &lt;NearManagerDelegate&gt;
    ...
}

class NearSDKManager : NearManagerDelegate {
    func manager(_ manager: NearManager, eventWithContent content: Any, trackingInfo: NITTrackingInfo) {
    // Handle the content
    }

    func manager(_ manager: NearManager, eventFailureWithError error: Error) {
    // handle errors (only for information purpose)
    }
}
</div>
<div class="code-objc">
{
    ...
    manager.delegate = &lt;NearManagerDelegate&gt;
    ...
}

class NearSDKManager<NITManagerDelegate> {
    - (void)manager:(NITManager*)manager eventWithContent:(id)content trackingInfo:(NITTrackingInfo*)trackingInfo {
        // Handle the content
    }

    - (void)manager:(NITManager* _Nonnull)manager eventFailureWithError:(NSError* _Nonnull)error {
        // handle errors (only for information purpose)
    }
}
</div>

**Warning:** please remember to track the "notified" event to NearIT, otherwise some NearIT features might not work.

## Custom text for content notifications (iOS 9)

Whenever the Near SDK provide a content, automatically in iOS 9 you will see an alert with two buttons: "Close" and "OK".<br/>
To customize the text for the buttons you have to insert two keys in your `Localizable.strings` file:

* `NIT_content_alert_close` for the "Close" button
* `NIT_content_alert_ok` for the "OK" button

