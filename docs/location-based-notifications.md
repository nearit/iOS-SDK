# Location Based Notifications

Before you start:

* You must add the `NSLocationAlwaysUsageDescription` or `NSLocationWhenInUseUsageDescription` in the project Info.plist
* For iOS 11 you must add the `NSLocationAlwaysAndWhenInUseUsageDescription` in the project Info.plist
* You will need to get `Always authorization`  from an instance of  `CLLocationManager`
___
When you want to start the radar for **geofences and beacons**, call the ```start``` method.
<br>Typically, you would start the radar right after you get authorization:

<div class="code-swift">
func requestAuthorization() {
    ...
    locationManager.delegate = self
    locationManager.requestAlwaysAuthorization()
    ...
}

// MARK: Location manager delegate

func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
    if status == .authorizedAlways {
        nearManager.start()
    } else {
        nearManager.stop()
    }
}
</div>
<div class="code-objc">
- (void)requestAuthorization {
    ...
    locationManager.delegate = self;
    [locationManager requestAlwaysAuthorization];
    ...
}

// MARK: Location manager delegate

- (void)locationManager:(CLLocationManager *)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status {
    if (status == kCLAuthorizationStatusAuthorizedAlways) {
        [nearManager start];
    } else {
        [nearManager stop];
    }
}
</div>

To learn how to deal with in-app content see this [section](handle-content.md).
