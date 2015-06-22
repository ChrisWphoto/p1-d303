#pragma once

#include <iostream>
#include "Date\Date.h"
#include <string>


enum assignStatus{assigned, completed, late}; 

class AssignNode {

private:
	Date dueDate;
	string description;
	Date assignedDate;
	assignStatus status; 

public:

	AssignNode(assignStatus theStatus = assignStatus::assigned) :status(theStatus){}


	//getters and setters
	assignStatus getStatus(){ return status; }



};


//ENUM Overloaded << operator. '<<' Prints word instead of int  
//code modified from http://en.cppreference.com/w/cpp/language/enum
std::ostream& operator<<(std::ostream& os, assignStatus s)
{
	switch (s) {
	case assigned: os << "assigned";    break;
	case completed: os << "completed"; break;
	case late: os << "late";  break;
	default: os.setstate(std::ios_base::failbit);
	}
	return os;
}
