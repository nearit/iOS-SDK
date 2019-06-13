//
//  NITFeedback.h
//  NearITSDK
//
//  Created by Francesco Leoni on 30/03/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

#import "NITReactionBundle.h"

@class NITTrackingInfo;

@interface NITFeedback : NITReactionBundle<NSCoding>

@property (nonatomic, strong) NSString* _Nonnull question;
@property (nonatomic, strong) NSString* _Nonnull recipeId DEPRECATED_ATTRIBUTE;
@property (nonatomic, strong) NITTrackingInfo* _Nonnull trackingInfo;

@end
