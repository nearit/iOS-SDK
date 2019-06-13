//
//  NITLogger.h
//  NearITSDK
//
//  Created by Francesco Leoni on 13/04/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

@protocol NITLogger <NSObject>

@required
- (void)verboseWithTag:(NSString* _Nonnull)tag message:(NSString* _Nonnull)message;
- (void)debugWithTag:(NSString* _Nonnull)tag message:(NSString* _Nonnull)message;
- (void)infoWithTag:(NSString* _Nonnull)tag message:(NSString* _Nonnull)message;
- (void)warningWithTag:(NSString* _Nonnull)tag message:(NSString* _Nonnull)message;
- (void)errorWithTag:(NSString* _Nonnull)tag message:(NSString* _Nonnull)message;

@end
