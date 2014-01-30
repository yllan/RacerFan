//
//  YLRoadView.m
//  RacerFan
//
//  Created by Yung-Luen Lan on 1/31/14.
//  Copyright (c) 2014 Yung-Luen Lan. All rights reserved.
//

#import "YLRoadView.h"

@implementation YLRoadView

- (id) initWithFrame: (NSRect)frame
{
    self = [super initWithFrame: frame];
    if (self) {
        // Initialization code here.
    }
    return self;
}

- (id) initWithCoder: (NSCoder *)aDecoder
{
    self = [super initWithCoder: aDecoder];
    if (self) {
        
    }
    return self;
}



- (void) drawRect: (NSRect)dirtyRect
{
	[super drawRect: dirtyRect];
    NSImage *roadBackground = [NSImage imageNamed: @"road"];
    for (; _distance >= self.bounds.size.height; _distance -= self.bounds.size.height);
    int d = (int)_distance;
    [roadBackground drawInRect: NSMakeRect(0, -d, self.bounds.size.width, self.bounds.size.height)];
    [roadBackground drawInRect: NSMakeRect(0, -d + self.bounds.size.height, self.bounds.size.width, self.bounds.size.height)];
    
}

@end
