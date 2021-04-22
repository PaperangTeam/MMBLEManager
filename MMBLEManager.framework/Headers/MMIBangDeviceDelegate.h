//
//  MMIBangDeviceDelegate.h
//  Paperang
//
//  Created by hoho on 2019/7/24.
//  Copyright © 2019 Hoho. All rights reserved.
//  帮帮机

#import "MMDeviceDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface MMIBangDeviceDelegate : MMDeviceDelegate <PaperangIBangProtocol>

- (NSArray <NSData *> *)setDensity:(BangDensity)density;

@end

NS_ASSUME_NONNULL_END
