#import <Cordova/CDV.h>
#import "DownloadManager.h"

//@interface IonicUpdate : CDVPlugin <NSURLConnectionDataDelegate>
@interface IonicUpdate : CDVPlugin

@property (strong, nonatomic) DownloadManager *downloadManager;

- (void) initialize:(CDVInvokedUrlCommand *)command;

- (void) check:(CDVInvokedUrlCommand *)command;

- (void) download:(CDVInvokedUrlCommand *)command;

- (void) extract:(CDVInvokedUrlCommand *)command;

- (void) redirect:(CDVInvokedUrlCommand *)command;

- (NSDictionary *) httpRequest:(NSString *) endpoint;

- (bool) checkForUpdates;

- (void) downloadUpdate:(NSString *) download_url;

- (void) unzip;

- (void) doRedirect;

- (NSMutableArray *) getMyVersions;

- (bool) hasVersion:(NSString *) uuid;

- (void) saveVersion:(NSString *) uuid;

- (void) cleanupVersions;

- (void) removeVersion:(NSString *) uuid;

@end