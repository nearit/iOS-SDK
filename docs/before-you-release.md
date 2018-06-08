# NearIT Version

We encourage you to use the latest SDK version for all your supported platforms. If you are using a deprecated method from our library, search in the documentation for the suggested method. We only support the latest major release with bug fixes.

## Switch environment

As a general practice, we encourage the use of different environments (eg. staging and production). With that comes the managing of different api keys and certificates. If you are preparing your build for production, be sure to switch the NearIT API key to the one for your production NearIT app. Also switch the `CFBundleURLSchemes` for the test device feature in the `Info.plist` file.
Your NearIT production app should also have the push certificate set to *Production*, even if your app is distributed with TestFlight.

You can check that everything is setup correctly by trying the test device feature on your production build, distributed with the store or TestFlight. Install the app, enroll your device to the test devices, and send a test push from the “**Settings> Push Settings**” section of the panel, directly to your device. If your app receives a notification, you have your certificates and API key correctly setup.