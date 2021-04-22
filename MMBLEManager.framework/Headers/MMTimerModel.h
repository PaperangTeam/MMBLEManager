//
//  MMTimerModel.h
//  Paperang
//
//  Created by 王明阳 on 2019/7/18.
//  Copyright © 2019 Hoho. All rights reserved.
//

//#import <WYDatabase/WYDatabase.h>
#import "MMAlarmInfoModel.h"
#import "MMTomatoInfoModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface MMTimerModel : NSObject
/**
 串号
 */
@property (nonatomic,copy) NSString *snCode;

/**
 用户id
 */
@property (nonatomic,copy) NSString *userId;
/**
 工作时间
 */
@property (nonatomic,assign) NSInteger workMinute;

/**
 休息时间
 */
@property (nonatomic,assign) NSInteger breakMinute;

/**
 是否是24小时制
 */
@property (nonatomic,assign) BOOL is24Hour;

/**
 是否自动同步时间
 */
@property (nonatomic,assign) BOOL isAutoUpdateTime;

/**
 自定义时间与手机时间的时间差，单位秒
 */
@property (nonatomic,assign) NSInteger customTime;

/**
 按键音是否打开
 */
@property (nonatomic,assign) BOOL isKeySoundOpen;

/**
 番茄音是否打开
 */
@property (nonatomic,assign) BOOL isTomatoSoundOpen;

/**
 番茄音
 */
@property (nonatomic,assign) int tomatoBell;

/**
 计时音打开
 */
@property (nonatomic,assign) BOOL isCountdownSoundOpen;

/**
 计时音
 */
@property (nonatomic,assign) int countdownBell;

/**
 熄屏时间，单位秒
 */
@property (nonatomic,assign) NSInteger suspendSecond;

/**
 番茄纸条开关
 */
@property (nonatomic,assign) BOOL isTomatoNoteOpen;

/**
 闹钟纸条开关
 */
@property (nonatomic,assign) BOOL isAlarmNoteOpen;

/// 关机闹钟开关
@property (nonatomic,assign) BOOL isPowerOffAlarm;

/**
 是否已经更新
 */
@property (nonatomic,assign) BOOL isUpload;

/**
 获得默认对象

 @return MMTimerModel
 */
+ (instancetype)defaultModelWithUserId:(NSString *)userId sn:(NSString *)sn;

/**
 根据文本获得对象
 */
+ (instancetype)getModelWithText:(NSString *)text;

/**
 转换为json文本，用于上传服务器
 */
- (NSString *)switchToString;


@end

NS_ASSUME_NONNULL_END
