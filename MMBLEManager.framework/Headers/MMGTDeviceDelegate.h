//
//  MMGTDeviceDelegate.h
//  Paperang
//
//  Created by hoho on 2019/7/10.
//  Copyright © 2019 Hoho. All rights reserved.
//

#import "MMDeviceDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface MMGTDeviceDelegate : MMDeviceDelegate <PaperangGTSerialProtocol>

@property (strong, nonatomic) NSMutableArray *packages;

@property (assign, nonatomic) NSInteger packageSize;

@property (strong, nonatomic) NSTimer *timeoutTimer;

@property (assign, nonatomic) NSInteger timeoutCount;

@property (copy, nonatomic) void (^timeoutBlock)(MMDeviceManagerOpModel * m);

@end

NS_ASSUME_NONNULL_END
