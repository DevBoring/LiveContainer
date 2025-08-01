#import <Foundation/Foundation.h>
#import "LCMachOUtils.h"

typedef NS_ENUM(NSInteger, Store){
    SideStore = 0,
    AltStore = 1,
    ADP = 2,
    Unknown = -1
};

void refreshFile(NSString* execPath);
int dyld_get_program_sdk_version(void);

@interface PKZipArchiver : NSObject

- (NSData *)zippedDataForURL:(NSURL *)url;

@end

@interface LCUtils : NSObject

+ (void)validateJITLessSetupWithCompletionHandler:(void (^)(BOOL success, NSError *error))completionHandler;
+ (NSURL *)archiveIPAWithBundleName:(NSString*)newBundleName error:(NSError **)error;
+ (NSData *)certificateData;
+ (NSString *)certificatePassword;

+ (BOOL)launchToGuestApp;
+ (BOOL)launchToGuestAppWithURL:(NSURL *)url;
+ (void)launchMultitaskGuestApp:(NSString *)displayName completionHandler:(void (^)(NSError *error))completionHandler API_AVAILABLE(ios(16.0));
+ (NSString*)getContainerUsingLCSchemeWithFolderName:(NSString*)folderName;

+ (NSProgress *)signAppBundleWithZSign:(NSURL *)path completionHandler:(void (^)(BOOL success, NSError *error))completionHandler;
+ (NSString*)getCertTeamIdWithKeyData:(NSData*)keyData password:(NSString*)password;
+ (int)validateCertificateWithCompletionHandler:(void(^)(int status, NSDate *expirationDate, NSString *error))completionHandler;

+ (BOOL)isAppGroupAltStoreLike;
+ (Store)store;
+ (NSString *)teamIdentifier;
+ (NSString *)appGroupID;
+ (NSString *)appUrlScheme;
+ (NSURL *)appGroupPath;
+ (NSString *)storeInstallURLScheme;
+ (NSString *)getVersionInfo;
@end

@interface NSUserDefaults(LiveContainer)
+ (bool)sideStoreExist;
@end
