//
//  NITImage.h
//  NearITSDK
//
//  Created by Francesco Leoni on 27/03/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

#import "NITResource.h"

@interface NITImage : NITResource<NSCoding>

@property (nonatomic, strong) NSDictionary<NSString*, id> * _Nullable image;

- (NSURL* _Nullable)smallSizeURL;
- (NSURL* _Nullable)url;

@end
