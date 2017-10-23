//
//  NITClaim.h
//  NearITSDK
//
//  Created by Francesco Leoni on 30/03/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

#import <NearITSDK/NearITSDK.h>

@class NITCoupon;

@interface NITClaim : NITResource<NSCoding>

@property (nonatomic, strong) NSString * _Nonnull serialNumber;
@property (nonatomic, strong) NSString * _Nonnull claimedAt;
@property (nonatomic, strong) NSString * _Nullable redeemedAt;
@property (nonatomic, strong) NSString * _Nonnull recipeId;
@property (nonatomic, strong) NITCoupon * _Nonnull coupon;
@property (nonatomic, readonly) NSDate * _Nonnull claimed;
@property (nonatomic, readonly) NSDate * _Nullable redeemed;

@end
