//
//  YLAppDelegate.h
//  RacerFan
//
//  Created by Yung-Luen Lan on 1/31/14.
//  Copyright (c) 2014 Yung-Luen Lan. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface YLAppDelegate : NSObject <NSApplicationDelegate>

@property (assign) IBOutlet NSWindow *window;
@property (weak) IBOutlet NSImageView *leftFan;
@property (weak) IBOutlet NSImageView *rightFan;
@property (weak) IBOutlet NSImageView *handleBar;
@property (weak) IBOutlet NSLevelIndicator *fuelLevel;

@end
