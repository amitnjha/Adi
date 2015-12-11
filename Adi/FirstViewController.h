//
//  FirstViewController.h
//  Adi
//
//  Created by Amit Admin on 7/18/15.
//  Copyright (c) 2015 Amit Jha. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface FirstViewController : UIViewController

@property (weak, nonatomic) IBOutlet UIStepper *forwardStepper;
@property (weak, nonatomic) IBOutlet UIButton *forwardButton;
@property (weak, nonatomic) IBOutlet UIStepper *reverseStepper;
@property (weak, nonatomic) IBOutlet UIButton *revereseButton;
@property (weak, nonatomic) IBOutlet UIStepper *rightStepper;
@property (weak, nonatomic) IBOutlet UIButton *rightButton;
@property (weak, nonatomic) IBOutlet UIStepper *leftStepper;
@property (weak, nonatomic) IBOutlet UIButton *leftButton;

@property NSArray *stepperValueList ;


@property NSString *leftButtonPrefix;// =@"<<";
@property NSString *rightButtonPrefix;
@property NSString *reverseButtonPrefix;
@property NSString *forwardButtonPrefix;

@property (weak, nonatomic) IBOutlet UIButton *forwardStepperButton;
@property (weak, nonatomic) IBOutlet UIButton *leftStepperButton;
@property (weak, nonatomic) IBOutlet UIButton *rightStepperButton;
@property (weak, nonatomic) IBOutlet UIButton *reverseStepperButton;

@end

