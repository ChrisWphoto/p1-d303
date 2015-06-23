#include <iostream>
#include "Date\Date.h"
#include "AssignNode.h"
#include "Date\StringTokenizer.h"
#include <string>
#include <fstream>
using namespace std;

int main() {

	ifstream fin("input.txt");

	
										//create node
	AssignNode n; 
	
	/*
	cout << n.getStatus() << endl;		//print default status

	n.setStatus(late);					//test setters

	cout << n.getStatus() << endl;

	n.setDueDate("2114-5-1");           //date is passed in as a string

	cout << n.getDueDate().toString() << endl; //print set date

	n.setAssignedDate("2011-1-1");

	cout << n.getAssignedDate().toString() << endl;
	*/

	
	
	fin >> n; 

	cout << n; 
	

	

	

	system("pause");
	return 0; 
}