//
//  MMDeviceDelegateGenerator.h
//  Paperang
//
//  Created by hoho on 2019/7/10.
//  Copyright © 2019 Hoho. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class MMDeviceDelegate;

@interface MMDeviceDelegateGenerator : NSObject

//+ (MMDeviceDelegate *)generateDeviceDelegateWithSerial:(MMDeviceSerial)serial
//                                                  type:(MMDeviceSubType)type;

//+ (MMDeviceDelegate *)generateDeviceDelegateWithName:(NSString *)name;

+ (Class)generateDeviceDelegateClassWithName:(NSString *)name;


@end

NS_ASSUME_NONNULL_END
