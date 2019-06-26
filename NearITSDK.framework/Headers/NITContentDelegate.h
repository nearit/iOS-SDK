//
//  NITContentDelegate.h
//  NearITSDK
//
//  Created by francesco.leoni on 04/12/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

@class NITSimpleNotification;
@class NITContent;
@class NITCoupon;
@class NITFeedback;
@class NITCustomJSON;
@class NITTrackingInfo;

@protocol NITContentDelegate <NSObject>

- (void)gotSimpleNotification:(NITSimpleNotification* _Nonnull)notification trackingInfo:(NITTrackingInfo* _Nonnull)trackingInfo;
- (void)gotContent:(NITContent* _Nonnull)content trackingInfo:(NITTrackingInfo* _Nonnull)trackingInfo;
- (void)gotCoupon:(NITCoupon* _Nonnull)coupon trackingInfo:(NITTrackingInfo* _Nonnull)trackingInfo;
- (void)gotFeedback:(NITFeedback* _Nonnull)feedback trackingInfo:(NITTrackingInfo* _Nonnull)trackingInfo;
- (void)gotCustomJSON:(NITCustomJSON* _Nonnull)customJson trackingInfo:(NITTrackingInfo* _Nonnull)trackingInfo;

@end
