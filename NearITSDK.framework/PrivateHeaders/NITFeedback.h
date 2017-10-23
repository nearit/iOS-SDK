//
//  NITFeedback.h
//  NearITSDK
//
//  Created by Francesco Leoni on 30/03/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

#import "NITReactionBundle.h"

@interface NITFeedback : NITReactionBundle<NSCoding>

@property (nonatomic, strong) NSString* _Nonnull question;
@property (nonatomic, strong) NSString* _Nonnull recipeId;

@end
