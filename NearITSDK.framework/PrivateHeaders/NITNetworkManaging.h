//
//  NITNetworkManaging.h
//  NearITSDK
//
//  Created by Francesco Leoni on 10/04/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

@class NITJSONAPI;

@protocol NITNetworkManaging <NSObject>

- (void)makeRequestWithURLRequest:(NSURLRequest* _Nonnull)request jsonApicompletionHandler:(void (^_Nonnull)(NITJSONAPI * _Nullable json, NSError * _Nullable error))completionHandler;

@end
