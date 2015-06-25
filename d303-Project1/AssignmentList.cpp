/*
#include "AssignmentList.h"

void AssignmentList::addAssignment(AssignNode A)
{
	if (assigned.empty())
	{
		assigned.push_back(A);
		return;
	}
	for (list<AssignNode>::iterator itr = assigned.begin(); itr != assigned.end(); ++itr)
	{
		if ((*itr).getDueDate() > A.getDueDate()) // If the assignment's due date is before the current one
		{
			assigned.insert(itr, A); // Insert it before the current one
			return;
		}
	}
}

void AssignmentList::completeAssignment(Date D)
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

AssignNode AssignmentList::getAssignedItem(Date D)
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

AssignNode AssignmentList::getCompletedItem(Date D)
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

int AssignmentList::getLateCount()
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

list<AssignNode> AssignmentList::getAssignedList()
{
	return assigned;
}

list<AssignNode> AssignmentList::getCompletedList()
{
	return completed;
}
*/