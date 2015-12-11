//
//  ThirdViewController.h
//  Adi
//
//  Created by Amit Admin on 7/18/15.
//  Copyright (c) 2015 Amit Jha. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ThirdViewController : UIViewController <UITextFieldDelegate>
@property (weak, nonatomic) IBOutlet UITextField *urlText;
@property (weak, nonatomic) IBOutlet UIButton *testAndSave;

@end
