//
//  LoginModel.h
//  wisdomNeighbor
//
//  Created by Lin Li on 2019/9/22.
//  Copyright © 2019 Lin Li. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LoginModelUsers :NSObject
@property (nonatomic , copy) NSString              * userId;
@property (nonatomic , copy) NSString              * createuserid;
@property (nonatomic , copy) NSString              * createtime;
@property (nonatomic , copy) NSString              * phone;
@property (nonatomic , copy) NSString              * enterercode;
@property (nonatomic , copy) NSString              * logintime;
@property (nonatomic , copy) NSString              * friendscirclelastuser;
@property (nonatomic , copy) NSString              * friendsremindnum;
@property (nonatomic , copy) NSString              * likes;
@property (nonatomic , copy) NSString              * belonghouse;
@property (nonatomic , copy) NSString              * nowuseestates;
@property (nonatomic , copy) NSString              * sex;
@property (nonatomic , copy) NSString              * password;
@property (nonatomic , copy) NSString              * icon;
@property (nonatomic , copy) NSString              * truename;
@property (nonatomic , copy) NSString              * usertype;
@property (nonatomic , copy) NSString              * nickname;
@property (nonatomic , copy) NSString              * dislikes;
@property (nonatomic , copy) NSString              * status;

@end

@interface LoginModelEstates :NSObject
@property (nonatomic , copy) NSString              * isopen;
@property (nonatomic , copy) NSString              * totleperson;
@property (nonatomic , copy) NSString              * longitude;
@property (nonatomic , copy) NSString              * estatesId;
@property (nonatomic , copy) NSString              * locationstring;
@property (nonatomic , copy) NSString              * latitude;
@property (nonatomic , copy) NSString              * jointime;
@property (nonatomic , copy) NSString              * name;

@end

@interface LoginModelHouses :NSObject
@property (nonatomic , copy) NSString              * housesId;
@property (nonatomic , copy) NSString              * belongestates;
@property (nonatomic , copy) NSString              * createtime;
@property (nonatomic , strong) LoginModelEstates              * estates;
@property (nonatomic , copy) NSString              * inestateslocation;

@end

@interface LoginModelData :NSObject
@property (nonatomic , strong) LoginModelUsers              * users;
@property (nonatomic , copy) NSArray<LoginModelHouses *>              * houses;

@end

@interface LoginModel :NSObject
@property (nonatomic , copy) NSString              * returnCode;
@property (nonatomic , strong) LoginModelData              * data;
@property (nonatomic , copy) NSString              * errorMessage;

/**房屋id*/
@property(nonatomic, copy) NSString *currentHouseId;
@property(nonatomic, copy) NSString *currentHouseName;


/**取得当前用户*/
+ (LoginModel *)currentUser;

/**同步当前用户至userDefault 以便下次程序启动有值*/
#define XKUserSynchronize [LoginModel synchronizeUser];
+ (void)synchronizeUser;

/**保存用户至单例 并且存至userDefult*/
+ (void)saveCurrentUser:(LoginModel *)user;

/**请空user*/
+ (void)cleanUser;
@end


NS_ASSUME_NONNULL_END