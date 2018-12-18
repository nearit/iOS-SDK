//
//  NITTrackingInfo.h
//  NearITSDK
//
//  Created by francesco.leoni on 11/08/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

#import <Foundation/Foundation.h>
#define KEY_DELIVERY_ID @"delivery_id"

@interface NITTrackingInfo : NSObject<NSCoding>

- (BOOL)addExtraWithObject:(id<NSCoding> _Nonnull)object key:(NSString* _Nonnull)key;
- (NSString * _Nullable)recipeId;
- (void)setRecipeId:(NSString * _Nonnull)recipeId;
- (NSDictionary* _Nonnull)extrasDictionary;
- (BOOL)existsExtraForKey:(NSString* _Nonnull)key;
- (BOOL)hasDeliveryID;
- (NSString* _Nullable)deliveryID;

+ (NITTrackingInfo* _Nonnull)trackingInfoFromRecipeId:(NSString* _Nonnull)recipeId;
+ (NITTrackingInfo* _Nonnull)trackingInfoFromRecipeId:(NSString* _Nonnull)recipeId deliveryId:(NSString* _Nullable)deliveryId;
+ (NITTrackingInfo* _Nonnull)trackingInfoFromRecipeId:(NSString* _Nonnull)recipeId extras:(NSDictionary<NSString*, id> *)extras;

@end
