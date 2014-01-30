//
//  YLAppDelegate.m
//  RacerFan
//
//  Created by Yung-Luen Lan on 1/31/14.
//  Copyright (c) 2014 Yung-Luen Lan. All rights reserved.
//

#import "YLAppDelegate.h"


@implementation YLAppDelegate

- (void) applicationDidFinishLaunching: (NSNotification *)aNotification
{
    self.dualShock = [PS3SixAxis sixAixisControllerWithDelegate: self];
    [self.dualShock connect: YES];
    [NSTimer scheduledTimerWithTimeInterval: 1.0 / 30 target: self selector: @selector(update:) userInfo: nil repeats: YES];
}

- (void) update: (NSTimer *)timer
{
    CGFloat MaxVelocity = 60;
    _velocity -= 0.75;
    _velocity = MAX(0, _velocity);
    _velocity = MIN(MaxVelocity, _velocity);
    
    if (_direction > 1) _direction = 1;
    if (_direction < -1) _direction = -1;

    CGFloat leftVelocity = _velocity * (1 - _direction * 0.6) / 1.6;
    CGFloat rightVelocity = _velocity * (1 + _direction * 0.6) / 1.6;

    self.roadView.distance += _velocity / 2.5;
    [self.roadView setNeedsDisplay: YES];
    
    if (_velocity > 0.5) {
        NSRect carFrame = self.carView.frame;
        carFrame.origin.x += _direction * 2;
        if (carFrame.origin.x < 0) carFrame.origin.x = 0;
        if (carFrame.origin.x > self.roadView.frame.size.width - carFrame.size.width) carFrame.origin.x = self.roadView.frame.size.width - carFrame.size.width;
        self.carView.frame = carFrame;
    }
    
    self.rightFan.frameCenterRotation += rightVelocity;
    self.leftFan.frameCenterRotation += leftVelocity;
    self.handleBar.frameCenterRotation = _direction * -80;
}

- (void) onL2ButtonWithPressure: (NSInteger)value
{
    self.fuelLevel.integerValue = value;
    _velocity += (value / 255.0 * 1.5);
}

- (void) onEastButtonWithPressure: (NSInteger)value
{
    _direction += value / 255.0 * 0.5;
}

- (void) onWestButtonWithPressure: (NSInteger)value
{
    _direction -= value / 255.0 * 0.5;
}

- (void) onLeftStick: (NSPoint)axis pressed: (BOOL)isPressed
{
    _direction = (axis.x - 127.5) / 127.5;
}

@end
