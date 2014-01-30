//
//  PS3SixAxis.h
//  PS3SixAxis
//
//  Created by Tobias Wetzel on 04.05.10.
//  Copyright 2010 Outcut. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IOKit/hid/IOHIDLib.h>
#import <IOBluetooth/objc/IOBluetoothHostController.h>


@protocol PS3SixAxisDelegate <NSObject>
@optional

- (void) onDeviceConnected;
- (void) onDeviceDisconnected;
- (void) onDeviceConnectionError:(NSInteger)error;

- (void) onAxisX:(NSInteger)x Y:(NSInteger)y Z:(NSInteger)z;

- (void) onLeftStick:(NSPoint)axis pressed:(BOOL)isPressed;
- (void) onRightStick:(NSPoint)axis pressed:(BOOL)isPressed;

- (void) onNorthButton:(BOOL)state;
- (void) onEastButton:(BOOL)state;
- (void) onSouthButton:(BOOL)state;
- (void) onWestButton:(BOOL)state;

- (void) onNorthButtonWithPressure:(NSInteger)value;
- (void) onEastButtonWithPressure:(NSInteger)value;
- (void) onSouthButtonWithPressure:(NSInteger)value;
- (void) onWestButtonWithPressure:(NSInteger)value;

- (void) onTriangleButton:(BOOL)state;
- (void) onCircleButton:(BOOL)state;
- (void) onCrossButton:(BOOL)state;
- (void) onSquareButton:(BOOL)state;

- (void) onTriangleButtonWithPressure:(NSInteger)value;
- (void) onCircleButtonWithPressure:(NSInteger)value;
- (void) onCrossButtonWithPressure:(NSInteger)value;
- (void) onSquareButtonWithPressure:(NSInteger)value;

- (void) onL1Button:(BOOL)state;
- (void) onL2Button:(BOOL)state;
- (void) onR1Button:(BOOL)state;
- (void) onR2Button:(BOOL)state;

- (void) onL1ButtonWithPressure:(NSInteger)value;
- (void) onL2ButtonWithPressure:(NSInteger)value;
- (void) onR1ButtonWithPressure:(NSInteger)value;
- (void) onR2ButtonWithPressure:(NSInteger)value;

- (void) onSelectButton:(BOOL)state;
- (void) onStartButton:(BOOL)state;
- (void) onPSButton:(BOOL)state;

@end


@interface PS3SixAxis : NSObject {
@private
	id<PS3SixAxisDelegate> delegate;
	BOOL useBuffered;
	IOHIDManagerRef hidManagerRef;
	IOHIDDeviceRef hidDeviceRef;
    
    BOOL isConnected;
    
    BOOL isLeftStickDown, preIsLeftStickDown;
    BOOL isRightStickDown, preIsRightStickDown;
    BOOL isTriangleButtonDown, preIsTriangleButtonDown;
    BOOL isCircleButtonDown, preIsCircleButtonDown;
    BOOL isCrossButtonDown, preIsCrossButtonDown;
    BOOL isSquareButtonDown, preIsSquareButtonDown;
    BOOL isL1ButtonDown, preIsL1ButtonDown;
    BOOL isL2ButtonDown, preIsL2ButtonDown;
    BOOL isR1ButtonDown, preIsR1ButtonDown;
    BOOL isR2ButtonDown, preIsR2ButtonDown;
    
    BOOL isNorthButtonDown, preIsNorthButtonDown;
    BOOL isEastButtonDown, preIsEastButtonDown;
    BOOL isSouthButtonDown, preIsSouthButtonDown;
    BOOL isWestButtonDown, preIsWestButtonDown;
    
    BOOL isSelectButtonDown, preIsSelectButtonDown;
    BOOL isStartButtonDown, preIsStartButtonDown;
    BOOL isPSButtonDown, preIsPSButtonDown;
    
    int preLeftStickX, preLeftStickY;
    int preRightStickX, preRightStickY;
    
    unsigned int mx, my, mz;
}

+ (id) sixAixisController;
+ (id) sixAixisControllerWithDelegate:(id<PS3SixAxisDelegate>)aDelegate;
- (id) initSixAixisControllerWithDelegate:(id<PS3SixAxisDelegate>)aDelegate;

- (void)connect:(BOOL)enableBluetooth;
- (void)disconnect;

- (void)setDelegate:(id<PS3SixAxisDelegate>)aDelegate;
- (id<PS3SixAxisDelegate>)delegate;

- (void)setUseBuffered:(BOOL)doUseBuffered;
- (BOOL)useBuffered;

@end
