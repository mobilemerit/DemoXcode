//  LocalyticsUploader+Protected.h
//  Copyright (C) 2013 Char Software Inc., DBA Localytics
//
//  This code is provided under the Localytics Modified BSD License.
//  A copy of this license has been distributed in a file called LICENSE
//  with this source code.
//
//  Please visit www.localytics.com for more information.

#import "LocalyticsUploader.h"

@interface LocalyticsUploader (Protected)

- (NSMutableURLRequest *)createRequestWithURL:(NSURL *)URL installId:(NSString *)installId libraryVersion:(NSString *)libraryVersion;
- (NSMutableURLRequest *)createPostRequestWithURL:(NSURL *)URL installId:(NSString *)installId libraryVersion:(NSString *)libraryVersion requestData:(NSData *)requestData;

@end
