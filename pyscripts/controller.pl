#!/usr/bin/perl
use CGI;
my $q = CGI->new;
my $action = $q->param("action");
my $count = $q->param("count");


print "Content-type: text/html\n\n";
print "sudo ./robotcontrol.py $action $count" ;
system("sudo ./robotcontrol.py $action $count");
print("Hello World");
print(@action);



