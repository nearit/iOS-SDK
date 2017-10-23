//
//  NITReactionBundle.h
//  NearITSDK
//
//  Created by francesco.leoni on 12/09/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

#import "NITResource.h"

@interface NITReactionBundle : NITResource<NSCoding>

@property (nonatomic, strong) NSString *notificationMessage;

@end
