//
//  YLAppDelegate.h
//  RacerFan
//
//  Created by Yung-Luen Lan on 1/31/14.
//  Copyright (c) 2014 Yung-Luen Lan. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "PS3SixAxis.h"
#import "YLRoadView.h"

@interface YLAppDelegate : NSObject <NSApplicationDelegate, PS3SixAxisDelegate>

@property (assign) IBOutlet NSWindow *window;
@property (weak) IBOutlet NSImageView *leftFan;
@property (weak) IBOutlet NSImageView *rightFan;
@property (weak) IBOutlet NSImageView *handleBar;
@property (weak) IBOutlet NSLevelIndicator *fuelLevel;
@property (weak) IBOutlet YLRoadView *roadView;
@property (weak) IBOutlet NSImageView *carView;

@property (strong, nonatomic) PS3SixAxis *dualShock;

@property CGFloat velocity;
@property CGFloat direction;

@end
