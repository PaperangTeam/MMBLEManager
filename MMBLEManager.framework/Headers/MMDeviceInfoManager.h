//
//  MMDeviceInfoManager.h
//  Paperang
//
//  Created by 王明阳 on 2019/4/9.
//  Copyright © 2019 Hoho. All rights reserved.
//  设备类型管理

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MMBLENormalManager.h"

//切换到不同的设备类型通知
#define MMDeviceTypeChangeNotification @"MMDeviceTypeChangeNotification"

/// 此枚举按百宝箱体验设备类型进行区分(别处不建议使用, 具体可MMDeviceDelegateGenerator枚举)
typedef NS_ENUM(NSUInteger, MMDeviceType) {
    MMDeviceTypeMiaoMiaoJi,///< p1,p2,d1等
    MMDeviceTypeTTJ,///< 条条机
    MMDeviceTypeMax,///< c1等
    MMDeviceTypeP2S, ///< p2s
    MMDeviceTypeBang, ///< 帮帮机
    MMDeviceTypeP3,   ///< P3
    MMDeviceTypeX2,   ///< 小盒子
};

NS_ASSUME_NONNULL_BEGIN

@interface MMDeviceInfoManager : NSObject

/**
 当前使用的设备,与是否真实连接无关,如果连接设备必然改变
 */
@property (nonatomic,assign,readonly) MMDeviceType currentDeviceType;

/**
 初始化

 @return return value description
 */
+ (instancetype)manager NS_SWIFT_NAME(shared());

/**
 切换设备类型

 @param newType newType description
 */
- (void)changeDeviceTypeToType:(MMDeviceType)newType;

/// 根据设备型号转换
/// @param str str description
- (void)changeDeviceTypeWithStr: (NSString *)str;

/**
 切换使用设备类型
 */
- (void)changeDeviceTypeWithModel:(MMBluetoothDeviceModel*)deviceModel;

/**
 获得当前设备类型名称

 @return return value description
 */
- (NSString *)getCurrentDeviceName;

/// 获取所有设备的名称
- (NSSet<NSString *> *)getAllDeviceName;

/// 通过设备类型获取设备名称
- (NSString *)getDeviceNameWithType:(MMDeviceType)deviceType;

/**
 开始监听当前设备类型
 */
- (void)beginObserveDeviceType;

/**
 处理是否需要展示切换设备类型动画

 @param isForever 是否永久展示，需主动结束动画，默认为NO，动画时间为默认2秒
 @return 返回是否需要处理
 */
- (BOOL)handleShowAnimationViewIfNeedAfterConnectDeviceIsForever:(BOOL)isForever;

- (CGFloat)currentDeviceImageWidth;

- (CGFloat)deviceImageWidthWithDeviceType:(MMDeviceType)deviceType;

- (BOOL)currentIsRegularPaper;

/// 同步检查设备类型,登录后使用
//- (void)checkHistoryDeviceType;

@end

NS_ASSUME_NONNULL_END
