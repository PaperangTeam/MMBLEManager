//
//  MMP2SDeviceDelegate.h
//  Paperang
//
//  Created by hoho on 2019/7/19.
//  Copyright © 2019 Hoho. All rights reserved.
//

#import "MMP2DeviceDelegate.h"
#import "MMAlarmInfoModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface MMP2SDeviceDelegate : MMP2DeviceDelegate<PaperangP2SProtocol>

@property (nonatomic,assign) NSInteger alarmNameMaxLength;

@property (nonatomic,assign) NSInteger todayTomatoCount;
/**
 设置时间
 */
- (NSArray <NSData*> *)setTimeWithYear:(NSUInteger)year
                                 month:(NSUInteger)month
                                   day:(NSUInteger)day
                                  hour:(NSUInteger)hour
                                minute:(NSUInteger)minute
                                second:(NSUInteger)second;

/**
 设置小时制
 */
- (NSArray <NSData*> *)setTimeModeWithIs24Hour:(BOOL)is24Hour;


/**
 获得小时制
 */
- (NSArray <NSData*> *)getTimeMode;

/**
 设置番茄时钟提醒纸条开关
 */
- (NSArray <NSData*> *)setTomatoNoteOn:(BOOL)isOn;

/**
 获得番茄时钟提醒纸条开关状态
 */
- (NSArray <NSData*> *)getTomatoNoteOn;

/**
 设置番茄时钟提醒纸条数据
 */
- (NSArray <NSData*> *)setTomatoNoteDataWithImage:(UIImage *)image;

/**
 设置闹钟提醒纸条开关
 */
- (NSArray <NSData*> *)setAlarmNoteOn:(BOOL)isOn;

/**
 获得闹钟提醒纸条开关
 */
- (NSArray <NSData*> *)getAlarmNoteOn;

/**
 设置闹钟提醒纸条数据
 */
- (NSArray <NSData*> *)setAlarmNoteWithImage:(UIImage *)image;

/// 纸条预先包
- (NSArray <NSData*> *)getSetNotePreActionDatas;
/**
 设置按键音
 */
- (NSArray <NSData*> *)setKeySoundOn:(bool)isOn;

/**
 获得按键音
 */
- (NSArray <NSData*> *)getKeySoundOn;

/**
 设置计时提示音
 */
- (NSArray <NSData*> *)setTimerSoundIsOn:(BOOL)isOn;

/**
 获得计时提示音开关
 */
- (NSArray <NSData*> *)getTimerSoundOn;

/**
 设置闹钟提示音
 */
- (NSArray <NSData*> *)setAlarmSoundOn:(BOOL)isOn;

/**
 获得闹钟提示音状态
 */
- (NSArray <NSData*> *)getAlarmSoundOn;

/**
 设置闹钟延时提醒开关
 */
- (NSArray <NSData*> *)setAlarmDelayOn:(BOOL)isOn;

/**
 获得闹钟延时提醒开关状态
 */
- (NSArray <NSData*> *)getAlarmDelayOn;

/**
 设置闹钟延时提醒时间,单位为分钟
 */
- (NSArray <NSData*> *)setAlarmDelayTimeWithMinutes:(NSInteger)minutes;

/**
 获得闹钟延时提醒时间
 */
- (NSArray <NSData*> *)getAlarmDelayTime;

/**
 设置番茄时钟提示音
 */
- (NSArray <NSData*> *)setTomatoSoundIsOpen:(BOOL)isOpen;

/**
 获得番茄时钟提示音
 */
- (NSArray <NSData*> *)getTomatoSoundStatus;

/**
 设置熄屏时间,单位为秒
 */
- (NSArray <NSData*> *)setSuspendTimeSecond:(NSInteger)second;

/**
 获得熄屏时间,单位为秒
 */
- (NSArray <NSData*> *)getSuspendTime;


- (NSArray <NSData*> *)setTomatoWorkTimeMinutes:(NSInteger)minutes restTimeMinutes:(NSInteger)rest;
/**
 设置番茄时钟工作时间,单位为分钟
 */
- (NSArray <NSData*> *)setTomatoWorkTimeMinutes:(NSInteger)minutes;

/**
 获得番茄时钟工作时间,单位为分钟
 */
- (NSArray <NSData*> *)getTomatoWorkTime;

/**
 设置番茄时钟休息时间,单位为分钟
 */
- (NSArray <NSData*> *)setTomatoBreakTimeMinutes:(NSInteger)minutes;

/**
 获得番茄时钟休息时间,单位为分钟
 */
- (NSArray <NSData*> *)getTomatoBreakTime;

/**
 新增闹钟时间
 */
- (NSArray <NSData*> *)addAlarmTimeHour:(int)hour
                                 minute:(int)minute
                                  cycle:(uint8_t)cycle
                                 isOpen:(BOOL)isOpen
                               bellType:(int)bellType
                                isDelay:(BOOL)isDelay
                                   name:(NSString *)name
                           openAndOrder:(uint8_t)openAndOrder;

/// 删除闹钟
/// @param model model description
- (NSArray <NSData*> *)deleteAlarm:(MMAlarmInfoModel *)model;

/// 更新闹钟
/// @param model model description
- (NSArray <NSData*> *)updateAlarm:(MMAlarmInfoModel *)model;

/// 获得关机闹钟开关
- (NSArray <NSData *> *)getPowerOffAlarm;

/// 设置关机闹钟开关
/// @param isOpen 是否打开
- (NSArray <NSData *> *)setPowerOffAlarm:(BOOL)isOpen;

/**
 设置屏幕闪烁开关
 */
- (NSArray <NSData*> *)setScreenFlashIsOpen:(BOOL)isOpen;

/**
 获得屏幕闪烁开关状态
 */
- (NSArray <NSData*> *)getScreenFlashStatus;

/**
 获取番茄钟计数数据
 */
- (NSArray <NSData*> *)getTomatoCount;

/**
 获取闹钟数据
 */
- (NSArray <NSData*> *)getAlarmTime;

/**
 获得番茄钟铃声
 */
- (NSArray <NSData*> *)getTomatoSoundType;

/**
 获得计时铃声
 */
- (NSArray <NSData*> *)getCountDownSoundType;

/**
 设置番茄钟铃声
 */
- (NSArray <NSData*> *)setTomatoSoundType:(uint8_t)newType;
/**
 设置计时铃声
 */
- (NSArray <NSData*> *)setCountDownSoundType:(uint8_t)newType;

/**
 播放铃声
 */
- (NSArray <NSData*> *)playSoundWithType:(int)type;

/**
 停止播放铃声
 */
- (NSArray <NSData*> *)stopPlaySound;


@end

NS_ASSUME_NONNULL_END
