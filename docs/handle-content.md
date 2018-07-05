# Handle In-app content

If you followed the instruction inside [Notification Setup](setup-notifications.md) closely, every tap on notification should be leading to a "**handleNearContent**" method.<br>
You should implement your handleNearContent method, inside it, you would typically check the content type and handle presentation.

In the next chapter you will find a reference for any NearIT content.

## Recipe and content objects

When `eventWithContent` gets called or inside `processRecipe` callback you will obtain the content and the tracking info as arguments. 

Content can have several class types:

- `NITSimpleNotification` instance representing the simple notification
- `NITContent` instance representing the rich content if any
- `NITCustomJSON` instance representing the custom object if any
- `NITCoupon` instance representig the coupon if any
- `NITFeedback` instance representing the feedback request if any

## Content classes

- `NITSimpleNotification` for the simple notification, with the following attributes:
    - `message` returns the notification message

- `NITContent` for the notification with content, with the following attributes:
    - `title` returns the title
    - `content` returns the text content, without processing the html
    - `image` returns a *NITImage* object containing the source link of the image uploaded on NearIT if any
    - `link` returns a *NITContentLink* object with a label and url if any
    
- `NITFeedback` with the following getters:
    - `question` returns the feedback request string
To give a feedback call this method:

<div class="code-swift">
// rating must be an integer between 0 and 5, and you can set a comment string.
manager.sendEvent(feedbackEvent, completionHandler: { (error) in
    ...
})
</div>
<div class="code-objc">
// rating must be an integer between 0 and 5, and you can set a comment string.
[manager sendEventWithEvent:event completionHandler:^(NSError * _Nullable error) {
    ...
}];
</div>

    
- `NITCoupon` with the following getters:
    - `title` returns the coupon title
    - `couponDescription` returns the description
    - `value` returns the value string
    - `expires` returns the expiring date
    - `redeemable` returns the redeemable date, it's a start date of when you can reedem the coupon
    - `icon` returns an *Image* object containing the source links for the icon
    - `claims` returns a list of *NITClaim* which are the actual instances for the current profile
    - a `NITClaim` is composed by:
        - `serialNumber` the unique number assigned to the coupon instance
        - `claimed` a date representing when the coupon has been claimed
        - `redeemed` a date representing when the coupon has ben used

    
- `NITCustomJSON` with the following getters:
    - `content` returns the json content as a *[String: AnyObject]* (*[NSString**, id] in Objective-C)

## Fetch current user coupon

We handle the complete emission and redemption coupon cycle in our platform, and we deliver a coupon content only when a coupon is emitted (you will not be notified of recipes when a profile has already received the coupon, even if the coupon is still valid).
You can ask the library to fetch the list of all the user current coupons with the method:

<div class="code-swift">
manager?.coupons({ (coupons, error) in
    //Put your code here
})
</div>
<div class="code-objc">
[manager couponsWithCompletionHandler:^(NSArray<NITCoupon *> *coupons, NSError *error) {
    //Put your code here
}];
</div>

The method will also return already redeemed coupons so you get to decide to filter them if necessary.

## Content Delegate
You can extract the right content for you though an object that implement the  `NITContentDelegate` protocol.<br/>
When you have a **content** and its **trackingInfo** (e.g. in the didReceive method) you can call the `parseContent` method and pass the reference to your content delegate.
<div class="code-swift">
manager.parseContent(content, trackingInfo: trackingInfo, contentDelegate: contentDelegate)
</div>
<div class="code-objc">
[manager couponsWithCompletionHandler:^(NSArray<NITCoupon *> *coupons, NSError *error) {
//Put your code here
}];
</div>
