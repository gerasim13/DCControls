//
//  DCControl.h
//
//  Copyright 2011 Domestic Cat. All rights reserved.
//

#define	kDCControlIsPhone (UI_USER_INTERFACE_IDIOM() != UIUserInterfaceIdiomPad)
#define kDCControlDegreesToRadians(x) (M_PI * (x) / 180.0)
#define kDCControlRadiansToDegrees(x) ((x) * 180.0 / M_PI)

@protocol DCControlDelegate <NSObject>

@required

- (void)controlValueDidChange:(float)value sender:(id)sender;

@end

@interface DCControl : UIView
{
	BOOL mTracking;
}
@property (nonatomic, unsafe_unretained) IBOutlet id delegate;
@property (nonatomic, strong) UIColor *color;	      		// default: black
@property (nonatomic, assign) CGFloat backgroundColorAlpha; // default: 0.3

@property (nonatomic, strong) UIFont  *labelFont;		// default: bold, system, 12.5
@property (nonatomic, strong) UIColor *labelColor;		// default: use self.color
@property (nonatomic, assign) CGPoint labelOffset;		// default: CGPointZero

@property (nonatomic, assign) CGFloat min;				// default: 0.0
@property (nonatomic, assign) CGFloat max;				// default: 1.0
@property (nonatomic, assign) CGFloat value;			// default: 0.0

@property (nonatomic, assign) BOOL displaysValue;		// default: YES
@property (nonatomic, assign) BOOL allowsGestures;		// default: YES

- (id)initWithDelegate:(id)aDelegate;

@property(nonatomic,readonly,getter=isTracking) BOOL tracking;

/////////////////////
// Drawing Methods //
/////////////////////

- (void)context:(CGContextRef)context addRoundedRect:(CGRect)rect cornerRadius:(float)cornerRadius;

@end
