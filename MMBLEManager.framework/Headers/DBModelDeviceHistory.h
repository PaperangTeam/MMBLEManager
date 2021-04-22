//
//  DBModelDeviceHistory.h
//  Paperang
//
//  Created by 李育洋 on 2017/6/13.
//  Copyright © 2017年 Hoho. All rights reserved.
//

//#import "WYDatabase/WYDatabase.h"
//#import <WYDatabase/WYDatabase.h>
#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    DeviceTimeModeUnknow,
    DeviceTimeMode24,
    DeviceTimeMode12,
} DeviceTimeMode;

typedef enum : NSUInteger {
    DeviceStatusUnknow,
    DeviceStatusClose,
    DeviceStatusOpen,
} DeviceStatus;

@class MMBluetoothDeviceModel;

@interface DBModelDeviceHistory : NSObject
@property (nonatomic,copy) NSString *name;
@property (nonatomic,copy) NSString *alias;
@property (nonatomic,copy) NSString *identifier;
@property (nonatomic,copy) NSString *date;
@property (nonatomic,copy) NSString *mac;
@property (nonatomic,copy) NSString *guid;
@property (nonatomic,copy) NSString *paperInfo;
@property (nonatomic,copy) NSString *density;
@property (nonatomic,copy) NSString *version;
@property (nonatomic,copy) NSString *offTime;
@property (nonatomic,copy) NSString *deviceType;

@property (nonatomic,copy) NSString *paperId;//选中纸
@property (nonatomic,assign) NSInteger paperType;//纸张类型

//new
//@property (nonatomic,copy) NSString *ram;
//@property (nonatomic,copy) NSString *rom;
//@property (nonatomic,assign) BOOL hasWifi;
//@property (nonatomic,assign) BOOL hasEthernet;
//@property (nonatomic,copy) NSString *bindInfo;
//

- (instancetype)initWithBluetoothModel:(MMBluetoothDeviceModel *)bluetoothModel;

+ (NSArray *)selectBySQLConditions:(NSString *)sqlCondition values:(NSArray *)array NS_UNAVAILABLE;
+ (BOOL)executeUpdateSQL:(NSString *)sql paramater:(NSArray *)paramater NS_UNAVAILABLE;

/**
 从本地数据库筛选
 */
+ (NSArray *)fetchDataFromDatabaseWithIdentifier:(NSString *)identifier;

/**
 从本地数据库删除
 */
+ (BOOL)deleteDataWithIdentifier:(NSString *)identifier;

/**
 更新数据
 */
+ (BOOL)updateDeviceHistoryWithModel:(MMBluetoothDeviceModel *)model;

+ (MMBluetoothDeviceModel *)getBlueModelWithIdentifier:(NSString *)identifier;

/**
 更新昵称
 */
+ (BOOL)updateDeviceAliasWithIdentifier:(NSString *)identifier alias:(NSString *)alias;
+ (BOOL)updateDeviceAliasWithSN:(NSString *)sn alias:(NSString *)alias;

/**
 根据guid删除
 */
+ (BOOL)deleteDeviceHistoryDataWithGUID:(NSString *)guid;

/**
 插入新历史
 */
+ (BOOL)insertWithBluetoothModel:(MMBluetoothDeviceModel *)model;

@end

