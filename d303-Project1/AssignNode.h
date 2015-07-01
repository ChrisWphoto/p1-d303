#pragma once

#include <iostream>
#include "Date.h"
#include "StringTokenizer.h"
#include <string>


enum assignStatus{ assigned, completed, late };

class AssignNode {

private:
	Date dueDate;
	string description;
	Date assignedDate;
	assignStatus status;
	

public:
	
	//default constructor
	AssignNode(assignStatus theStatus = assignStatus::assigned ) :status(theStatus) {
		//set safe values for dates
		dueDate = Date("2-1-2000", DateFormat::US);
		assignedDate = Date("1-1-2000", DateFormat::US);
	}


	//Status get/set
	assignStatus getStatus(){ return status; }
	void setStatus(assignStatus theStatus){ status = theStatus; }

	//String get/set
	string getDescript(){ return description; }
	void setDescript(string theDescription){ description = theDescription; }

	//dueDate get/set
	Date getDueDate(){ return dueDate; }
	void setDueDate(string theDueDate){ 
		//DueDate must come after assigned date
		Date tempDueDate = Date(theDueDate, DateFormat::US);
		

		if (tempDueDate > assignedDate)
			dueDate = Date(theDueDate, DateFormat::US);
		else
			cout << "Input Error: Due Date must come after the Assigned Date: "<< assignedDate.toString() << endl;
	
	}

	//assignedDate get/set
	Date getAssignedDate(){ return assignedDate; }
	void setAssignedDate(string theAssignedDate){ 
		//AssignedDate must come before DueDate date
		Date tempAssignedDate = Date(theAssignedDate, DateFormat::US);

		if (tempAssignedDate < dueDate)
			assignedDate = Date(theAssignedDate, DateFormat::US);
		else
			cout << "Input Error: Assigned Date must come before Due Date: " << dueDate.toString() <<endl;
		
	
	}
	
	
	//overloaded input operator for assignments
	friend istream &operator>>(istream  &input, AssignNode &node)
	{
		string line;
		getline(input, line);

		//tokenize line
		String_Tokenizer st(line, ",");

		//vars to hold each value
		string theDueDate, theDescription, assignedDate, theStatus;

		theDueDate = st.next_token();
		theDescription = st.next_token();
		assignedDate = st.next_token();
		theStatus = st.next_token();

		//stripping white from assigned date and status
		String_Tokenizer st2(assignedDate);
		assignedDate = st2.next_token();

		//assigning values
		node.setDueDate(theDueDate);
		node.setAssignedDate(assignedDate);
		node.setDescript(theDescription);

		String_Tokenizer st3(theStatus);
		theStatus = st3.next_token();

		//converting string of status to enum		
		if (theStatus == "assigned")
			node.status = assignStatus::assigned;
		else if (theStatus == "completed")
			node.status = assignStatus::completed;
		else if (theStatus == "late")
			node.status = assignStatus::late;
		else
			input.setstate(std::ios_base::failbit);


		return input;
	}

	//overloaded output operator
	friend ostream &operator<<(ostream &output, AssignNode &node)
	{
		output << "Due Date: " << node.getDueDate().toString() << endl << "Description: "
			<< node.getDescript() << endl << "Assigned Date: " << node.getAssignedDate().toString() << endl << "Status: ";
		
		assignStatus S = node.getStatus(); //Print Status as text 
		
		switch (S) {
			case assigned: output << "assigned";    break;
			case completed: output << "completed"; break;
			case late: output << "late";  break;
			default: output.setstate(std::ios_base::failbit);
		}			
		cout << endl << endl;
		return output;
	}

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
