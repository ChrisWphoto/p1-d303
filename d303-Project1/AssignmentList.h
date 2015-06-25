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
			bool inserted = false; // tracking whether or not node has been inserted yet -CW

			for (list<AssignNode>::iterator itr = assigned.begin(); itr != assigned.end(); ++itr)
			{
				if ((*itr).getDueDate() > A.getDueDate()) // If the assignment's due date is before the current one
				{
					assigned.insert(itr, A); // Insert it before the current one
					inserted = true;
					return;
				}
			}
			// When itr reaches the end of the list the itr->dueDate becomes a large negative number so the above condition will never be true. 
			//so if we have not inserted yet and we are at the end of the list then we should insert at the end. -CW
			if (inserted == false){
				assigned.push_back(A);
			}
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
				assigned.erase(itr);
				return;
			}
		}
		cout << "Assignment not found!" << endl;
		return;
	}

	AssignNode getAssignedItem(Date D)
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

	AssignNode getCompletedItem(Date D)
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
	void printAssignedList(){
		for (list<AssignNode>::iterator itr = assigned.begin(); itr != assigned.end(); ++itr)
		{
			cout << *itr; 
		}
	}

	//Print Completed List - CW
	void printCompletedList(){
		for (list<AssignNode>::iterator itr = completed.begin(); itr != completed.end(); ++itr)
		{
			cout << *itr;
		}
	}

	//adding from file -CW
	void addFromFile(string theName, AssignmentList &theList){
		ifstream fin(theName);

		while (!fin.eof()){
			AssignNode temp; 
			fin >> temp;

			theList.addAssignment(temp);
		}
	}



};

#endif