//
//  MMPaperModel.h
//  Paperang
//
//  Created by 王明阳 on 2019/4/17.
//  Copyright © 2019 Hoho. All rights reserved.
//  纸张模型

#import <Foundation/Foundation.h>
#import "MMPaperHoleModel.h"
#import "MMDeviceInfoManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface MMPaperModel : NSObject

/**
 类型
 */
@property (nonatomic,assign,readonly) MMDeviceType deviceType;

/**
 总宽度,单位毫米
 */
@property (nonatomic,assign,readonly) CGFloat width_mm;

/**
 显示宽度,单位毫米
 */
@property (nonatomic,assign,readonly) CGFloat contentWidth_mm;

/**
 展示宽度，可能与实际不一样,单位毫米
 */
@property (nonatomic,assign,readonly) CGFloat showWidth_mm;

/**
 上部留白高度,单位毫米
 */
@property (nonatomic,assign,readonly) CGFloat topBlankHeight_mm;

/**
 下部留白高度,单位毫米
 */
@property (nonatomic,assign,readonly) CGFloat bottomBlankHeight_mm;


/**
 分割线之间距离，有装订孔，单位毫米(仅C1)
 */
@property (nonatomic,assign,readonly) CGFloat separatorLineSpaceWithHole_mm;

/**
 分割线之间距离，无装订孔，单位毫米(仅C1)
 */
@property (nonatomic,assign,readonly) CGFloat separatorLineSpace_mm;

/**
 装订孔参数，单位毫米(仅C1)
 */
@property (nonatomic,strong) MMPaperHoleModel *holeModel;

/**
 初始化

 @param deviceType deviceType description
 @return return value description
 */
- (instancetype)initWithDeviceType:(MMDeviceType)deviceType;

/// 根据系列获得模型
/// @param serial serial description
- (instancetype)initWithDeviceSerial:(MMDeviceSerial)serial;

/**
 当前纸张模型

 @return return value description
 */
+ (instancetype)currentPaperModel;

@end

NS_ASSUME_NONNULL_END
