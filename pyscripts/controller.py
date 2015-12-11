#!/usr/bin/python
'''
* Controller to handle incoming http request.
* The controller decodes the action and steps from the request and delegates call to appropriate actual script to do the job.
*
'''



import cgitb
import cgi






cgitb.enable()
form = cgi.FieldStorage()


print "Content-Type: text/html"  
print


if form.has_key("count"):
	print form.getvalue("count")

if form.has_key("action"):
	print form.getvalue("action")

#doForward(form.getvalue("count"))

print "Done Done!!";

