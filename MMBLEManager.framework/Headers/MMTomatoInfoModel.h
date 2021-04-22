//
//  MMTomatoInfoModel.h
//  Paperang
//
//  Created by 王明阳 on 2019/5/30.
//  Copyright © 2019 Hoho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
@interface MMTomatoInfoModel : NSObject
@property (nonatomic,assign) NSInteger month;
@property (nonatomic,assign) NSInteger day;
@property (nonatomic,assign) NSInteger year;
@property (nonatomic,assign) NSInteger count;

- (NSDate *)tomatoDate;

@end

NS_ASSUME_NONNULL_END
