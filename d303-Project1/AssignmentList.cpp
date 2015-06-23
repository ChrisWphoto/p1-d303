#include "AssignmentList.h"

void AssignmentList::addAssignment(AssignNode A)
{
	assigned.push_back(A);
}

void AssignmentList::completeAssignment(Date D)
{
	for (list<AssignNode>::iterator itr = assigned.begin(); itr != assigned.end(); ++itr)
	{
		if ((*itr).getAssignedDate() == D)
		{
			AssignNode A(*itr);
			completed.push_back(A);
			assigned.remove(*itr);
		}
	}
}

void AssignmentList::sortByDueDate(list<AssignNode> L)
{
	if (L.size() == 0)
	{
		cout << "List is empty" << endl;
		return;
	}
	if (L.size() == 1)
		return;

	list<AssignNode>::iterator itr = L.begin();
	while (itr != L.end())
	{
		list<AssignNode>::iterator itrNext = itr++;
		if ((*itr).getDueDate() > (*itrNext).getDueDate())
		{
			AssignNode temp = *itr;
			*itr = *itrNext;
			*itrNext = temp;
		}
		++itr;
	}
	return;
}

AssignNode AssignmentList::getAssignedItem(Date D)
{
	for (list<AssignNode>::iterator itr = assigned.begin(); itr != assigned.end(); ++itr)
	{
		if ((*itr).getAssignedDate() == D)
			return *itr;
	}
}

AssignNode AssignmentList::getCompletedItem(Date D)
{
	for (list<AssignNode>::iterator itr = completed.begin(); itr != completed.end(); ++itr)
	{
		if ((*itr).getAssignedDate() == D)
			return *itr;
	}
}

int AssignmentList::getLateCount()
{
	int lateCount = 0;
	for (list<AssignNode>::iterator itr = assigned.begin(); itr != assigned.end(); ++itr)
	{
		if ((*itr).getStatus() == "late")
			lateCount++;
	}
	return lateCount;
}