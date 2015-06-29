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
				(*itr).setStatus(assignStatus::completed);
				AssignNode A(*itr);
				completed.push_back(A);
	/*DR*/		cout << "Assignment completed: " << A.getDescript() << endl << endl;
				assigned.erase(itr);
				return;
			}
		}
		cout << "Assignment not found!" << endl;
		return;
	}

	AssignNode* findAssignment(Date D, bool isAssigned, bool searchBoth)
	{
		if (assigned.empty() && completed.empty())
		{
			AssignNode* node = new AssignNode();
			return node;
		}

		// check both lists
		if (searchBoth)
		{
			// first search assigned list
			for (list<AssignNode>::iterator itr = assigned.begin(); itr != assigned.end(); ++itr)
			{
				if ((*itr).getAssignedDate() == D)
				{
					AssignNode* node = &(*itr);
					return node;
				}
			}
			// then search completed list
			for (list<AssignNode>::iterator itr = completed.begin(); itr != completed.end(); ++itr)
			{
				if ((*itr).getAssignedDate() == D)
				{
					AssignNode* node = &(*itr);
					return node;
				}
			}
			// item not found, return empty assignment
			cout << "Assignment not found" << endl;
			AssignNode* node = new AssignNode();
			return node;
		}
		else // check only one of the lists
		{
			// check assigned List 
			if (isAssigned)
			{
				for (list<AssignNode>::iterator itr = assigned.begin(); itr != assigned.end(); ++itr)
				{
					if ((*itr).getAssignedDate() == D)
					{
						AssignNode* node = &(*itr);
						return node;
					}
				}
			}
			// check completed list
			else
			{
				for (list<AssignNode>::iterator itr = completed.begin(); itr != completed.end(); ++itr)
				{
					if ((*itr).getAssignedDate() == D)
					{
						AssignNode* node = &(*itr);
						return node;
					}
				}
			}

			// item not found, return empty assignment
			cout << "Assignment not found" << endl;
			AssignNode* node = new AssignNode();
			return node;
		}
	}

	//return ptr to AssignNode for editing
	AssignNode* getAssignedItem(Date D)
	{
		return findAssignment(D, true, false);
	}

	AssignNode* getCompletedItem(Date D)
	{
		return findAssignment(D, false, false);
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
