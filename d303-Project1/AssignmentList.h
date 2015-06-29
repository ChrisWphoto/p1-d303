#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "AssignNode.h"
#include <fstream>
#include <list>
using namespace std;


class AssignmentList
{
private:
	list<AssignNode> assigned;
	list<AssignNode> completed;

public:
	void addAssignment(AssignNode A)
	{
		if (assigned.empty())
		{
			assigned.push_back(A);
			return;
		}
		else {

			for (list<AssignNode>::iterator itr = assigned.begin(); itr != assigned.end(); ++itr)
			{
				if ((*itr).getDueDate() > A.getDueDate()) // If the assignment's due date is before the current one
				{
					assigned.insert(itr, A); // Insert it before the current one
				
					return;
				}
			}
			
			assigned.push_back(A); //insert in last postition
		
		}
	}

	void completeAssignment(Date D)
	{
		if (assigned.empty())
		{
			cout << "List is empty!" << endl;
			return;
		}
		for (list<AssignNode>::iterator itr = assigned.begin(); itr != assigned.end(); ++itr)
		{
			if ((*itr).getAssignedDate() == D)
			{
				AssignNode A(*itr);
				completed.push_back(A);
	/*DR*/			cout << "Assignment completed: " << A.getDescript() << endl << endl;
				assigned.erase(itr);
				return;
			}
		}
		cout << "Assignment not found!" << endl;
		return;
	}

	//return ptr to AssignNode for editing
	AssignNode* getAssignedItem(Date D)
	{
		if (assigned.empty()) 
		{
			cout << "List is empty" << endl;
		}
		for (list<AssignNode>::iterator itr = assigned.begin(); itr != assigned.end(); ++itr)
		{
			if ((*itr).getAssignedDate() == D){
				//return *itr;
				AssignNode* node = &(*itr); // return a pointer node being edited -CW
				return node;
			}
		}
		cout << "Assignment not found" << endl;
	}

	AssignNode& getCompletedItem(Date D)
	{
		if (completed.empty())
		{
			cout << "List is empty!" << endl;
		}
		for (list<AssignNode>::iterator itr = completed.begin(); itr != completed.end(); ++itr)
		{
			if ((*itr).getAssignedDate() == D)
				return *itr;
		}
		cout << "Assignment not found" << endl;
	}

	int getLateCount()
	{
		int lateCount = 0;
		if (completed.empty())
			return lateCount;
		for (list<AssignNode>::iterator itr = completed.begin(); itr != completed.end(); ++itr)
		{
			if ((*itr).getStatus() == assignStatus::late)
				lateCount++;
		}
		return lateCount;
	}

	list<AssignNode> getAssignedList()
	{
		return assigned;
	}

	list<AssignNode> getCompletedList()
	{
		return completed;
	}

	//Print Assigned List - CW
	void displayAssignedList(){
		if (assigned.empty()) // added by DR
		{
			cout << "ASSIGNED LIST: Empty!" << endl << endl;
			return;
		}
		cout << "ASSIGNED LIST: " << endl; // added by DR
		for (list<AssignNode>::iterator itr = assigned.begin(); itr != assigned.end(); ++itr)
		{
			cout << *itr; 
		}
		return; // DR
	}

	//Print Completed List - CW
	void displayCompletedList(){
		if (completed.empty()) // added by DR
		{
			cout << "COMPLETED LIST: Empty!" << endl << endl;
			return;
		}
		cout << "COMPLETED LIST: " << endl; // added by DR
		for (list<AssignNode>::iterator itr = completed.begin(); itr != completed.end(); ++itr)
		{
			cout << *itr;
		}
		return; // DR
	}

	//adding from file -CW
	void addFromFile(string theName, AssignmentList &theList){ 
		ifstream fin(theName); 

		while (!fin.eof()){
			AssignNode temp; 
			fin >> temp;

			theList.addAssignment(temp);
		}
		return; // DR
	}

	//logic portion of printing to file --JW
	void printToFile(string Name)
	{
		ofstream fout(Name);

		//start with assigned list to print
		if (!assigned.empty())
		{
			for (list<AssignNode>::iterator itr = assigned.begin(); itr != assigned.end(); ++itr)
			{
				// due date, description, assigned date, status
				fout << itr->getDueDate().toString() << ", " << itr->getDescript() << ", " << itr->getAssignedDate().toString() << ", " << itr->getStatus() << endl;
			}
		}
		//then print completed list
		if (!completed.empty())
		{
			for (list<AssignNode>::iterator itr = completed.begin(); itr != completed.end(); ++itr)
			{
				// due date, description, assigned date, status
				fout << itr->getDueDate().toString() << ", " << itr->getDescript() << ", " << itr->getAssignedDate().toString() << ", " << itr->getStatus() << endl;
			}
		}
		

	}

};

#endif
