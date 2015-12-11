//
//  SecondViewController.m
//  Adi
//
//  Created by Amit Admin on 7/18/15.
//  Copyright (c) 2015 Amit Jha. All rights reserved.
//

#import "SecondViewController.h"

@interface SecondViewController ()

@end

@implementation SecondViewController



- (void)viewDidLoad {
    [super viewDidLoad];
    self.leftButtonPrefix = @"<< ";
    self.rightButtonPrefix = @" >>";
    self.reverseButtonPrefix = @" vv";
    self.forwardButtonPrefix = @"^^ ";
    
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)forwardStepperPressed:(UIStepper *)sender {
    

    
    NSString *newTitle = [NSString stringWithFormat:@"%@ %d",self.forwardButtonPrefix,(int)sender.value ];
    
    [self.forwardButton setTitle:newTitle forState:UIControlStateNormal];
}
- (IBAction)rightStepperPressed:(UIStepper *)sender {
    NSString *newTitle = [NSString stringWithFormat:@"%@ %d",self.rightButtonPrefix,(int)sender.value ];
    
    [self.rightButton setTitle:newTitle forState:UIControlStateNormal];
    
}

- (IBAction)leftStepperPressed:(UIStepper *)sender {
    
    NSString *newTitle = [NSString stringWithFormat:@"%@ %d",self.leftButtonPrefix,(int)sender.value ];
    
    [self.leftButton setTitle:newTitle forState:UIControlStateNormal];
    
}
- (IBAction)reverseStepperPressed:(UIStepper *)sender {
    
    
    NSString *newTitle = [NSString stringWithFormat:@"%@ %d",self.reverseButtonPrefix,(int)sender.value ];
    
    [self.reverseButton setTitle:newTitle forState:UIControlStateNormal];
}

- (IBAction)forwardButtonPressed:(UIButton *)sender {
    int count = (int)[[self forwardStepper] value];
    NSLog(@"step=%@&count=%d",@"forward",count);
}

- (IBAction)rightButtonPressed:(UIButton *)sender {
    int count = (int)[[self rightStepper] value];
    NSLog(@"step=%@&count=%d",@"right",count);
}


- (IBAction)reverseButtonPressed:(UIButton *)sender {
    int count = (int)[[self reverseStepper] value];
    NSLog(@"step=%@&count=%d",@"reverse",count);
}


- (IBAction)leftButtonPressed:(UIButton *)sender {
    int count = (int)[[self leftStepper] value];
    NSLog(@"step=%@&count=%d",@"left",count);
}


@end
