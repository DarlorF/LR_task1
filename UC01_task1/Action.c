Action()
{
	
lr_think_time(5);

lr_start_transaction("UC01_TR01_mainPage_Open");

	web_url("{host}:{port}", 
		"URL=http://{host}:{port}/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t123.inf", 
		"Mode=HTML", 
		LAST);
		
lr_end_transaction("UC01_TR01_mainPage_Open",LR_AUTO);

	lr_think_time(10);

	/*	web_reg_save_param_attrib(
		"ParamName=csrfmiddlewaretoken",
		"TagName=input",
		"Extract=value",
		"Name=csrfmiddlewaretoken",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);
*/		

	web_reg_save_param_regexp(
		"ParamName=csrfmiddlewaretoken",
		"RegExp=csrfmiddlewaretoken\" value=\"(.*?)\">",
		"Ordinal=1",
		LAST);
		
		
	lr_start_transaction("UC01_TR02_AdminLogIn");
	
/*Correlation comment - Do not change!  Original value='7zMHHtarZrl6ZP3KUgml41sjuxqKn4wjq2Is9CJhXJgArm15c1hIH20b9YmFWMWC' Name ='csrfmiddlewaretoken' Type ='ResponseBased'*/

	web_url("login", 
		"URL=http://{host}:{port}/login/?next=/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/", 
		"Snapshot=t140.inf", 
		"Mode=HTML", 
		LAST);
		

	web_reg_find("Text=Query Results",
        "Fail=NotFound",LAST);
             
	web_submit_data("login_2",
		"Action=http://{host}:{port}/login/",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{host}:{port}/login/?next=/",
		"Snapshot=t141.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=username", "Value={username}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=next", "Value=/", ENDITEM,
		"Name=csrfmiddlewaretoken", "Value={csrfmiddlewaretoken}", ENDITEM,
		LAST);

	web_url("eyJmaWx0ZXJpbmciOiB7InN0YXR1c19faW4iOiBbMSwgMl19LCAic29ydGluZyI6ICJjcmVhdGVkIiwgInNlYXJjaF9zdHJpbmciOiAiIiwgInNvcnRyZXZlcnNlIjogZmFsc2V9", 
		"URL=http://{host}:{port}/datatables_ticket_list/eyJmaWx0ZXJpbmciOiB7InN0YXR1c19faW4iOiBbMSwgMl19LCAic29ydGluZyI6ICJjcmVhdGVkIiwgInNlYXJjaF9zdHJpbmciOiAiIiwgInNvcnRyZXZlcnNlIjogZmFsc2V9?draw=1&columns%5B0%5D%5Bdata%5D=id&columns%5B0%5D%5Bname%5D=&columns%5B0%5D%5Bsearchable%5D=true&columns%5B0%5D%5Borderable%5D=false&columns%5B0%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B0%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B1%5D%5Bdata%5D=ticket&columns%5B1%5D%5Bname%5D=&columns%5B1%5D%5Bsearchable%5D=true&"
		"columns%5B1%5D%5Borderable%5D=true&columns%5B1%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B1%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B2%5D%5Bdata%5D=priority&columns%5B2%5D%5Bname%5D=&columns%5B2%5D%5Bsearchable%5D=true&columns%5B2%5D%5Borderable%5D=true&columns%5B2%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B2%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B3%5D%5Bdata%5D=queue&columns%5B3%5D%5Bname%5D=&columns%5B3%5D%5Bsearchable%5D=true&columns%5B3%5D%5Borderable%5D=true&columns%5B3%5D%5Bsearch%5D%5Bvalue%5D=&"
		"columns%5B3%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B4%5D%5Bdata%5D=status&columns%5B4%5D%5Bname%5D=&columns%5B4%5D%5Bsearchable%5D=true&columns%5B4%5D%5Borderable%5D=true&columns%5B4%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B4%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B5%5D%5Bdata%5D=created&columns%5B5%5D%5Bname%5D=&columns%5B5%5D%5Bsearchable%5D=true&columns%5B5%5D%5Borderable%5D=true&columns%5B5%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B5%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B6%5D%5Bdata%5D=due_date"
		"&columns%5B6%5D%5Bname%5D=&columns%5B6%5D%5Bsearchable%5D=true&columns%5B6%5D%5Borderable%5D=true&columns%5B6%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B6%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B7%5D%5Bdata%5D=assigned_to&columns%5B7%5D%5Bname%5D=&columns%5B7%5D%5Bsearchable%5D=true&columns%5B7%5D%5Borderable%5D=true&columns%5B7%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B7%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B8%5D%5Bdata%5D=submitter&columns%5B8%5D%5Bname%5D=&columns%5B8%5D%5Bsearchable%5D=true&"
		"columns%5B8%5D%5Borderable%5D=true&columns%5B8%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B8%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B9%5D%5Bdata%5D=time_spent&columns%5B9%5D%5Bname%5D=&columns%5B9%5D%5Bsearchable%5D=true&columns%5B9%5D%5Borderable%5D=true&columns%5B9%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B9%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B10%5D%5Bdata%5D=kbitem&columns%5B10%5D%5Bname%5D=&columns%5B10%5D%5Bsearchable%5D=true&columns%5B10%5D%5Borderable%5D=true&"
		"columns%5B10%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B10%5D%5Bsearch%5D%5Bregex%5D=false&order%5B0%5D%5Bcolumn%5D=0&order%5B0%5D%5Bdir%5D=asc&start=0&length=25&search%5Bvalue%5D=&search%5Bregex%5D=false&_=1687789623118", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host}:{port}/tickets/", 
		"Snapshot=t142.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR02_AdminLogIn",LR_AUTO);
	
	
      lr_think_time(15);

	lr_start_transaction("UC01_TR03_logout");

	web_url("Logout", 
		"URL=http://{host}:{port}/logout/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/tickets/2/", 
		"Snapshot=t145.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR03_logout",LR_AUTO);

	lr_think_time(5);

lr_start_transaction("UC01_TR04_mainPage_Open");

	web_url("{host}:{port}", 
		"URL=http://{host}:{port}/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t123.inf", 
		"Mode=HTML", 
		LAST);
		
lr_end_transaction("UC01_TR04_mainPage_Open",LR_AUTO);
	
	
	return 0;
}