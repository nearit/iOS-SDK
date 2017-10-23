//
//  NITTrackingInfo.h
//  NearITSDK
//
//  Created by francesco.leoni on 11/08/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NITTrackingInfo : NSObject<NSCoding>

- (BOOL)addExtraWithObject:(id<NSCoding> _Nonnull)object key:(NSString* _Nonnull)key;
- (NSString * _Nullable)recipeId;
- (void)setRecipeId:(NSString * _Nonnull)recipeId;
- (NSDictionary* _Nonnull)extrasDictionary;
- (BOOL)existsExtraForKey:(NSString* _Nonnull)key;

+ (NITTrackingInfo* _Nonnull)trackingInfoFromRecipeId:(NSString* _Nonnull)recipeId;

@end
