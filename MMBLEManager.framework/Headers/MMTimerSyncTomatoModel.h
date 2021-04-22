//
//  MMTimerSyncTomatoModel.h
//  Paperang
//
//  Created by 王明阳 on 2019/6/14.
//  Copyright © 2019 Hoho. All rights reserved.
//  番茄同步

//#import "WYDatabase/WYDatabase.h"
#import "MMBLEDefines.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MMTimerSyncTomatoModel : NSObject

@property (nonatomic,copy) NSString *sn;

@property (nonatomic,copy) NSString *synDateString;

@property (nonatomic,copy) NSString *dateFormat;

UN_AVAILABLE_SYSTEM_INIT

- (instancetype)initWithSn:(NSString*)sn
                     synDateString:(NSString*)synDateString
                        dateFormat:(NSString *)dateFormat;

@end

NS_ASSUME_NONNULL_END
