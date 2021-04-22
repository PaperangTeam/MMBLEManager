//
//  MMTimerNoteSelectModel.h
//  PaperangInternational
//
//  Created by 王明阳 on 2019/7/26.
//  Copyright © 2019 Hoho. All rights reserved.
//  (游客)纸条的选中信息

//#import "WYDatabase/WYDatabase.h"
#import "MMTimerNoteModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface MMTimerNoteSelectModel : NSObject

@property (nonatomic,copy) NSString *userId;
@property (nonatomic,copy) NSString *paperId;
@property (nonatomic,copy) NSString *snCode;
@property (nonatomic,assign) MMTimerNoteType noteType;
@property (nonatomic,copy) NSString *paperTitle;

+ (instancetype)getCurrentModelWithNoteType:(MMTimerNoteType)type;

@end

NS_ASSUME_NONNULL_END
