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


	//Status get/set
	assignStatus getStatus(){ return status; }
	void setStatus(assignStatus theStatus){ status = theStatus; }

	//String get/set
	string getDescript(){ return description; }
	void setDescript(string theDescription){ description = theDescription; }

	//dueDate get/set
	Date getDueDate(){ return dueDate; }
	void setDueDate(string theDueDate){ dueDate = Date(theDueDate); }

	//assignedDate get/set
	Date getAssignedDate(){ return assignedDate; }
	void setAssignedDate(string theAssignedDate){ assignedDate = Date(theAssignedDate); }



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
