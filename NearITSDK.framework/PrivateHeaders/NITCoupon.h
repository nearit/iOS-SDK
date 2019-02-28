//
//  NITCoupon.h
//  NearITSDK
//
//  Created by Francesco Leoni on 30/03/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

#import "NITReactionBundle.h"

@class NITClaim;
@class NITImage;

@interface NITCoupon : NITReactionBundle<NSCoding>

@property (nonatomic, strong) NSString *couponDescription;
@property (nonatomic, strong) NSString *value;
@property (nonatomic, strong) NSString *expiresAt;
@property (nonatomic, strong) NSString *redeemableFrom;
@property (nonatomic, strong) NSArray<NITClaim*> *claims DEPRECATED_ATTRIBUTE DEPRECATED_MSG_ATTRIBUTE("You should get claim info directly from coupon getters");
@property (nonatomic, strong) NITImage *icon;
@property (nonatomic, readonly) NSDate *expires;
@property (nonatomic, readonly) NSDate *redeemable;
@property (nonatomic, readonly) NSString *title;
@property (nonatomic, readonly) NSString *serial;
@property (nonatomic, readonly) NSString *claimedAt;
@property (nonatomic, readonly) NSDate *claimed;
@property (nonatomic, readonly) NSString *redeemedAt;
@property (nonatomic, readonly) NSDate *redeemed;


- (BOOL)hasContentToInclude;

@end
