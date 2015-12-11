//
//  ThirdViewController.m
//  Adi
//
//  Created by Amit Admin on 7/18/15.
//  Copyright (c) 2015 Amit Jha. All rights reserved.
//

#import "ThirdViewController.h"

@interface ThirdViewController ()

@end

@implementation ThirdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    NSString *url = [[NSUserDefaults standardUserDefaults] objectForKey:@"ADI_URL"];
    self.urlText.delegate = self;
    
    [[self urlText] setText:url];
    
    
    // Do any additional setup after loading the view.
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    [textField resignFirstResponder];
    return NO;
}


- (IBAction)testAndSave:(UIButton *)sender {
    
    NSString *newUrl = [[self urlText] text];
    [[NSUserDefaults standardUserDefaults] setValue:newUrl forKey:@"ADI_URL"];
    
    //test url
    
    
    
    NSString *count = @"1";
    NSString *urlString = [[NSUserDefaults standardUserDefaults] stringForKey:@"ADI_URL"];
    //append param to base url
    NSString *requstString= [NSString stringWithFormat:@"%@?action=%@&count=%@",urlString,@"test",count];
    
    
    NSURL *url  = [NSURL URLWithString:requstString];
    //NSURLQueryItem *item1 = [NSURLQueryItem new];
    //[item1 setValue:@"forward" forKey:@"step"];
    //NSURLQueryItem *item2 = [NSURLQueryItem new];
    //[item1 setValue:[NSString stringWithFormat:@"%d",count] forKey:@"count"];
    
    //NSURLComponents *c = [NSURLComponents comp];
    //NSArray *queryArray = [NSArray arrayWithObjects:item1,item2, nil];
    //[c setQueryItems:queryArray];
    
    
    //[url set]
    NSURLRequest *request = [NSURLRequest requestWithURL:url];
    [NSURLConnection sendAsynchronousRequest:request queue:[NSOperationQueue mainQueue] completionHandler:^(NSURLResponse *response, NSData *data, NSError *connectionError) {
        //NSLog(@"%@",data);
        NSString *strData = [[NSString alloc]initWithData:data encoding:NSUTF8StringEncoding];
        NSLog(@"%@",strData);
        //
    }];
    
    
    
    
    //save in NSUser Degfaults
    
    
    
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
