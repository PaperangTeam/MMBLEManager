//
//  MMTimerManager.h
//  PaperangInternational
//
//  Created by 王明阳 on 2019/7/23.
//  Copyright © 2019 Hoho. All rights reserved.
//  喵喵Timer管理类

#import <Foundation/Foundation.h>
#import "MMTimerModel.h"
#import "MMTimerNoteModel.h"

@interface MMTimerManager : NSObject

/**
 当前使用的配置
 */
@property (nonatomic,strong,nullable) MMTimerModel *currentModel;

/**
 当前用户的所有配置
 */
//@property (nonatomic,strong,nullable) NSMutableArray<MMTimerModel*> * allModelArray;

/**
 是否正在设置中
 */
@property (nonatomic,assign) BOOL isSetting;

/**
 获得单例

 @return return value description
 */
+ (instancetype _Nullable)share;

/**
 获得所有的配置,最新逻辑是同步机器的数据过来,completion已无用

 @param userId userId description
 */
- (void)requestAllDataWithUserId:(NSString * _Nullable)userId completion:(void (^_Nullable)(MMTimerManager * _Nullable manager))completion;

/**
 更新配置，仅仅更新“同步手机时间”与“自定义时间与当前时间的间隔”
 */
- (void)updateDataWithModel:(MMTimerModel *)model completion: (void (^_Nullable)(MMTimerManager * _Nullable manager))completion;

/**
 切换设备

 @param snCode snCode description
 */
- (void)changeCurrentModelWithSnCode:(NSString *_Nullable)snCode;

/**
 切换用户
 */
- (void)changeToUserId:(NSString *_Nullable)userId;


- (BOOL)isCanSendData;

/**
 开始设置纸张

 @param image image description
 @param noteType noteType description
 @return return value description
 */
- (BOOL)startSettingNoteImageWithImage:(UIImage  * _Nullable )image
                              noteType:(MMTimerNoteType)noteType;

@property (nonatomic,strong,nonnull)NSMutableArray *notePackages;

- (BOOL)sendPackageIfNeed;
- (void)clearAllPackages;

@property (nonatomic,strong) NSMutableArray<MMAlarmInfoModel*> *alarmArray;
@property (nonatomic,strong) NSMutableArray<MMTomatoInfoModel*> *tomatoArray;

@end


