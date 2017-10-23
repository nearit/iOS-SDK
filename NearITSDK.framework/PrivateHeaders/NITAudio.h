//
//  NITAudio.h
//  NearITSDK
//
//  Created by Francesco Leoni on 13/04/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

#import "NITResource.h"

@interface NITAudio : NITResource<NSCoding>

@property (nonatomic, strong) NSDictionary<NSString*, NSString*>* _Nonnull audio;

- (NSURL* _Nullable)url;

@end
