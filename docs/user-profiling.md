# User profiling & Opt-out

NearIT creates an anonymous profile for every user of your app. You can choose to add data to user profile. This data will be available inside recipes to allow the creation of user targets.

## Add User-data to NearIT

You can set user data with this method, it can be called multiple times to set several user data:
<div class="code-swift">
manager.setDeferredUserData("gender", value: "m")
</div>
<div class="code-objc">
[manager setDeferredUserDataWithKey:@"gender" value:@"m"];
</div>

If you want to set a **date** as a value, you have to use the format "MM-DD-YYYY".

Please remember: you will need to use the "**Settings> Data Mapping**" section of <a href="https://go.nearit.com/" target="_blank">**NearIT**</a> to configure the data fields to be used inside recipes.



## Save the Profile ID!

If you can, we recommend you to **store the NearIT profileID** in your CRM database for two main reasons:

- it allows you to link our analytics to your users
- it allows to associate all the devices of an user to the same NearIT profile.

You probably have a **sign in** system in your app, you should request the profile ID from NearIT before the user signs in: 
<div class="code-swift">
manager.profileId { (profileId, error) in
    // Code for store the profileId in your CRM
}
</div>
<div class="code-objc">
[manager profileIdWithCompletionHandler:^(NSString * _Nullable profileId, NSError * _Nullable error) {
    // Code for store the profileId in your CRM
}];
</div>

If you detect that your user already has a NearIT profile ID in your CRM database (i.e. after a sign in), you should pass the profile ID to NearIT:
<div class="code-swift">
manager.setProfile(id: "your remote NearIT profile ID")
</div>
<div class="code-objc">
[manager setProfileId:@"your remote NearIT profile ID"];
</div>

Whenever a users **signs out** from your app, you should reset the NearIT profileID:
<div class="code-swift">
manager.resetProfile { (profileId, error) in
    // ...
}
</div>
<div class="code-objc">
[manager resetProfileWithCompletionHandler:^(NSString * _Nullable profileId, NSError * _Nullable error) {
    // ...
}];
</div>

## Opt-out

You can opt-out a profile and its device:
<div class="code-swift">
manager.optOut { (success) in
    // ...
}
</div>
<div class="code-objc">
[manager optOutWithCompletionHandler:^(BOOL success) {
    // ...
}];
</div>
If the opt-out call is successful all the **user-data** and **trackings** will be deleted and the **SDK will cease to work** (the user's devices will not receive further notifications).
