
#include "Date.h"

int main(){


	Date date_1(2014, 5, 1); //add a date with the standard format (the default). The date is: May 1, 2014
	Date date_2(2014, 5, 1, DateFormat::US); //add a date with the US format(mm-dd-yyy). The date is May 1, 2014
	Date date_3("5-1-2014", DateFormat::US); //add a date with the US format(mm-dd-yyyy), the date is May 1, 2014
	Date date_4("1-5-2014"); //add a date with the standard format(yyyy-mm--dd), the date is May 1, 2014
	date_1.add_days(5); //add 5 days to date_1
	bool larger = date_1 > date_2; //compare if date_1 > date_2
	bool smaller = date_1 == date_2; //compare if date_1 == date_2
	string text = date_1.toString(); //conver date_1 to string (the string will be made based on the format

	return 0;

}

