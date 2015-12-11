//
//  FirstViewController.m
//  Adi
//
//  Created by Amit Admin on 7/18/15.
//  Copyright (c) 2015 Amit Jha. All rights reserved.
//

#import "FirstViewController.h"

@interface FirstViewController ()

@end

@implementation FirstViewController



- (void)viewDidLoad {
    [super viewDidLoad];
    self.leftButtonPrefix = @"<< ";
    self.rightButtonPrefix = @" >>";
    self.reverseButtonPrefix = @" vv";
    self.forwardButtonPrefix = @"^^ ";
    [[NSUserDefaults standardUserDefaults] setValue:@"http://192.168.1.112/cgi-bin/controller.pl" forKey:@"ADI_URL"];
    
    [self setStepperValueList:[NSArray arrayWithObjects:@"1",@"2",@"3",@"4",@"5",@"6",nil]];
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
    
    [self.revereseButton setTitle:newTitle forState:UIControlStateNormal];
}

- (IBAction)forwardButtonPressed:(UIButton *)sender {
    NSString *count = [[self forwardStepperButton] currentTitle];
    
    
    NSString *urlString = [[NSUserDefaults standardUserDefaults] stringForKey:@"ADI_URL"];
    //append param to base url
    NSString *requstString= [NSString stringWithFormat:@"%@?action=%@&count=%@",urlString,@"forward",count];
    
    
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
    
    //NSLog(@"%@", [request description]);
    
    
    //NSLog([data JSONRe])
    
    //NSLog(@"step=%@&count=%d",@"forward",count);
}


- (IBAction)haltButtonPressed:(id)sender {


    NSString *count = @"1";
    NSString *urlString = [[NSUserDefaults standardUserDefaults] stringForKey:@"ADI_URL"];
    //append param to base url
    NSString *requstString= [NSString stringWithFormat:@"%@?action=%@&count=%@",urlString,@"halt",count];
    
    
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
    


}

- (IBAction)rightButtonPressed:(UIButton *)sender {
    NSString *count = [[self rightStepperButton] currentTitle];
    NSString *urlString = [[NSUserDefaults standardUserDefaults] stringForKey:@"ADI_URL"];
    //append param to base url
    NSString *requstString= [NSString stringWithFormat:@"%@?action=%@&count=%@",urlString,@"right",count];
    
    
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
    
    
}

- (IBAction)stepperButtonPressed:(UIButton *)sender {
    
    long index = [[self stepperValueList] indexOfObject:[sender currentTitle]];
                
                
    if(index == [[self stepperValueList] count]-1){
        [sender setTitle:[[self stepperValueList] objectAtIndex:0 ] forState:UIControlStateNormal];
    }else{
        [sender setTitle:[[self stepperValueList] objectAtIndex:index+1] forState:UIControlStateNormal];
    }
    
}



- (IBAction)reverseButtonPressed:(UIButton *)sender {
    NSString *count = [[self reverseStepperButton] currentTitle];
    NSString *urlString = [[NSUserDefaults standardUserDefaults] stringForKey:@"ADI_URL"];
    //append param to base url
    NSString *requstString= [NSString stringWithFormat:@"%@?action=%@&count=%@",urlString,@"reverse",count];
    
    
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
}


- (IBAction)leftButtonPressed:(UIButton *)sender {
    NSString *count = [[self leftStepperButton] currentTitle];
    NSString *urlString = [[NSUserDefaults standardUserDefaults] stringForKey:@"ADI_URL"];
    //append param to base url
    NSString *requstString= [NSString stringWithFormat:@"%@?action=%@&count=%@",urlString,@"left",count];
    
    
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
}


@end
