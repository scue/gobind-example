// Objective-C API for talking to github.com/scue/gobind-example/hello Go package.
//   gobind -lang=objc github.com/scue/gobind-example/hello
//
// File is generated by gobind. Do not edit.

#ifndef __Hello_H__
#define __Hello_H__

@import Foundation;
#include "Universe.objc.h"


@class HelloCounter;
@class HelloRequest;
@protocol HelloPrinter;
@class HelloPrinter;

@protocol HelloPrinter <NSObject>
- (void)print:(NSString*)s;
@end

@interface HelloCounter : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (long)value;
- (void)setValue:(long)v;
- (void)dec;
- (void)inc;
@end

@interface HelloRequest : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init:(NSString*)command background:(BOOL)background timeout:(long)timeout;
- (long)uid;
- (void)setUid:(long)v;
// skipped field Request.Command with unsupported type: []string

- (BOOL)background;
- (void)setBackground:(BOOL)v;
- (long)timeout;
- (void)setTimeout:(long)v;
- (int64_t)timestamp;
- (void)setTimestamp:(int64_t)v;
- (NSString*)jsonEncode;
@end

FOUNDATION_EXPORT NSString* HelloGreeting(NSString* nick);

FOUNDATION_EXPORT HelloCounter* HelloNewCounter(void);

FOUNDATION_EXPORT HelloRequest* HelloNewRequest(NSString* command, BOOL background, long timeout);

FOUNDATION_EXPORT void HelloPrintHello(id<HelloPrinter> p0);

@class HelloPrinter;

@interface HelloPrinter : NSObject <goSeqRefInterface, HelloPrinter> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)print:(NSString*)s;
@end

#endif