#include <list>
#include "AssignNode.h"
using namespace std;

class AssignmentList
{
private:
	list<AssignNode> assigned;
	list<AssignNode> completed;
public:
	void addAssignment(AssignNode A);
	void completeAssignment(Date D);
	void sortByDueDate(list<AssignNode> L);
	AssignNode getAssignedItem(Date D);
	AssignNode getCompletedItem(Date D);
	int getLateCount();
};