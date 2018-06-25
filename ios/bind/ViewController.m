// Copyright 2015 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#import "ViewController.h"
#import "SysPrinter.h"
@import Hello;  // Gomobile bind generated framework

@interface ViewController ()
@end

@implementation ViewController

@synthesize textLabel;

- (void)loadView {
    [super loadView];
    
    // Call go func and return a message
    NSString *greeting = HelloGreeting(@"gopher");
    
    // Passing Go objects to objc
    HelloCounter *counter = HelloNewCounter();
    [counter inc];
    NSLog(@"counter value %ld", counter.value);
    
    textLabel.text = [NSString stringWithFormat:@"greeting: %@, counter value %ld",
                      greeting, [counter value]];
    
    // Passing objc objects to Go
    SysPrinter* printer = [[SysPrinter alloc] init];
    HelloPrintHello(printer);
    
    NSLog(@"current time unix: %f", NSDate.date.timeIntervalSince1970);
    
}

@end
