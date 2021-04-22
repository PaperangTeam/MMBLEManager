//
//  MMAlarmInfoModel.h
//  Paperang
//
//  Created by 王明阳 on 2019/5/30.
//  Copyright © 2019 Hoho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "DBModelDeviceHistory.h"

@interface MMAlarmInfoModel : NSObject

@property (nonatomic,assign) UInt32 alarmId;
@property (nonatomic,assign) int hour;
@property (nonatomic,assign) int minute;
@property (nonatomic,assign) int mmCycle;//一个字节
@property (nonatomic,assign) BOOL isOpen;

/// 开关 + 序号
@property (nonatomic,assign) uint8_t openAndOrder;

@property (nonatomic,copy) NSString *identifier;

@property (nonatomic,assign) int bellsType;
@property (nonatomic,assign) BOOL isDelayAlarm;
@property (nonatomic,copy) NSString *name;

- (instancetype)initWithHour:(int)hour
                      minute:(int)minute
                     mmCycle:(int)mmCycle
                      isOpen:(BOOL)isOpen
                  identifier:(NSString *)identifier
                   bellsType:(int)bellsType
                isDelayAlarm:(bool)isDelayAlarm
                        name:(NSString *)name
                openAndOrder:(uint8_t)openAndOrder;

- (instancetype)initWithID:(UInt32)alarmId
                      Hour:(int)hour
                    minute:(int)minute
                   mmCycle:(int)mmCycle
                    isOpen:(BOOL)isOpen
                identifier:(NSString *)identifier
                 bellsType:(int)bellsType
              isDelayAlarm:(bool)isDelayAlarm;

+ (NSString *)getFormatStringWithNumber:(int)number;

@end

