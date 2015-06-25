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
			//bool inserted = false; // tracking whether or not node has been inserted yet -CW
			
		//DR	// Do we need the bool? we can just add the push back function after the for loop. 
			// It won't reach there unless it's at the end of the list.

			for (list<AssignNode>::iterator itr = assigned.begin(); itr != assigned.end(); ++itr)
			{
				if ((*itr).getDueDate() > A.getDueDate()) // If the assignment's due date is before the current one
				{
					assigned.insert(itr, A); // Insert it before the current one
				/	//inserted = true;
					return;
				}
			}
			// When itr reaches the end of the list the itr->dueDate becomes a large negative number so the above condition will never be true. 
			//so if we have not inserted yet and we are at the end of the list then we should insert at the end. -CW
		//DR	//if (inserted == false){
			assigned.push_back(A);
		//DR	//}
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

	AssignNode& getAssignedItem(Date D)
	{
		if (assigned.empty())
		{
			cout << "List is empty!" << endl;
		}
		for (list<AssignNode>::iterator itr = assigned.begin(); itr != assigned.end(); ++itr)
		{
			if ((*itr).getAssignedDate() == D)
				return *itr;
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



};

#endif
