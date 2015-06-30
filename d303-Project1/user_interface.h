#ifndef USER_INTERFACE_H_
#define USER_INTERFACE_H_

#include <string>
#include <iostream>
#include "AssignmentList.h"
#include "AssignNode.h"
using namespace std;

class user_interface
{
public:
	user_interface()
	{
		file_change = false;
	}

	void process_orders()
		//main menu for interface, displays orders and user selects option. Continues until exit is selected.
	{
		bool again = true; //always start loop over until exit is selected

		add_assign_from_file();//to fulfill the "initially load from file to fill lists

		string orders[] = {
			"Display Assignments",
			"Manually Add Assignment",
			"Add Assignments from .txt file",
			"Edit a Specific Assignment",
			"Complete an Assignment",
			"Number of Late Assignments",
			"Save",
			"Exit" };

		const int num_of_orders = 8;
		while (again)
		{
			int choice = num_of_orders;

			cout << "Enter the number you would like to perform:\n";
			for (int i = 0; i < num_of_orders; i++)
			{
				cout << i+1 << ": " << orders[i] << endl;
			}
			cin >> choice;
			while (choice < 1 || choice > 9)//error check
			{
				cout << "Invalid choice, please select again: ";
				cin >> choice;
			}

			--choice;//changed number sequence for asthetics reasons--JW

			cout << endl;
			switch (choice)
			{
			case 0:
				display_assignments();
				break;
			case 1:
				add_assignment();
				break;
			case 2: //added -CW
				add_assign_from_file();
				break; 
			case 3:
				edit_assignment();
				break;
			case 4:
				complete_assignment();
				break;
			case 5:
				list_late();
				break;
			case 6:case 7: 
				save_lists(choice);//save list, and exit depending on the user's choice--JW
				break;

			}
		}
	}


	void display_assignments()
		//gives choice of either displaying each list individually or list both
	{
		string displayLists[] = {
			"Assigned List",
			"Completed List",
			"Both Lists"
		};
		int display;
		cout << "Which list would you like to display?\n";
		for (int i = 0; i < 3; ++i)
		{
			cout << i+1 << ": " << displayLists[i] << endl;
		}
		cin >> display;
		while (display < 1 || display > 3) //error check
		{
			cout << "Invalid choice, please select again: ";
			cin >> display;
		}
		--display;//changed design for asthetic reasons, still same value--JW
		switch (display)
		{
		case 0:
			cout << endl;
			assignment.displayAssignedList();
			break;
		case 1:
			cout << endl;
			assignment.displayCompletedList();
			break;
		case 2://print both lists
			cout << endl;
			assignment.displayAssignedList();
			cout << endl;
			assignment.displayCompletedList();
			break;
		};
	}

	void add_assignment()
		//adds new assignment, one line each parameter separated by a comma
	{
		AssignNode new_assign;

		cin.ignore();
		cout << "Enter in the new assignment details on one line, separated by commas. \n[Due Date], [Description], [Assigned Date], [Status]\n";
		cin >> new_assign;
		assignment.addAssignment(new_assign);
		cout << endl;
		file_change = true;
	}

	//adding from file -CW
	void add_assign_from_file()
		//gets the user's file to load, loads one initially then allows user to load a different file.
	{
			string fileName;

			while (true)
			{

				cout << "Enter the name of the file to load: ";
				cin >> fileName;

				char yesNo;

				cout << "Is this file name correct? [Y/N] \"" << fileName << "\"" << endl;
				cin >> yesNo;
				cout << endl;

				if (yesNo == 'Y' || yesNo == 'y'){
					break;
				}
			}

			assignment.addFromFile(fileName, assignment); //calling assignment list
				
		
		
	}



	void edit_assignment()\
		//gets assignemnt from list, then gives option to edit the description or due date
	{
			
		string options[] = { "edit due date", "edit description" };
		int choice;

		cout << "What would you like to edit? \n";

		for (int i = 0; i < 2; i++)
		{
			cout << i+1 << ": " << options[i] << endl;
		}

		cin >> choice;
		while (choice < 1 || choice > 2)//error check
		{
			cout << "Invalid choice, please select again: ";
			cin >> choice;
		}

		--choice;//changed for asthetic reasons--JW
		string due_date;
		cin.ignore();

		//get date to search for then find out what user wants to edit
		cout << "\nEnter the assigned date to edit (MM-DD-YYYY): ";
		getline(cin, due_date);
		Date date(due_date, DateFormat::US);


		AssignNode* holder;

		//if in assigned list
		//holder is a ptr to the node we are editing
		holder = assignment.getAssignedItem(date);

		cout << "This is the assignment chosen: \n" << *holder << endl;

		switch (choice)
		{
		case 0:
			edit_due_date(holder);
			file_change = true;
			break;
		case 1:
			edit_description(holder);
			file_change = true;
			break;
		}

	}
	void edit_due_date(AssignNode* holder)
		//Edits the pointer to an assignment's due date
	{
			

		string due_date;
		//change due date

		cout << "What is the new due date for this file? ";
		getline(cin, due_date);

		holder->setDueDate(due_date);

		cout << "Success!\n\n";

		return;

	}
	void edit_description(AssignNode* holder)
		//Edits the pointer to an assignment's description
	{
		string tempDescription;


		//change description of the file

		cout << "What is the new description for this file? ";
		getline(cin, tempDescription);

		holder->setDescript(tempDescription);
		cout << "Success\n\n";

		return;
	}


	void complete_assignment()
		//gets assigned date from user that has been completed
	{

		string due_date;
		string completed_date;
		cin.ignore();
		cout << "\nEnter the assigned date to complete (MM-DD-YYYY): ";
		getline(cin, due_date);
		Date date(due_date, DateFormat::US);
		cout << "\nEnter the completed date (MM-DD-YYYY): ";
		getline(cin, completed_date);
		Date completedDate(completed_date, DateFormat::US);

		assignment.completeAssignment(date, completedDate);//complete assignment with date given by user
		file_change = true;
	}

	void list_late()
		//prints the number of late assignments
	{
		int late = 0;
		late = assignment.getLateCount();
		cout << "Number of late assignments: " << late << "\n\n";

	}

	void save_lists(int choice)
		//saves the lists to a file if it has been changed, if not changed no save. choice is used to know whther to exit or not
	{
		string fileName;
		char yesNo;
		if (file_change == true)//only run if list has changed from original
		{
			//if they chose to exit, then find out if they want to save before they leave
			if (choice == 7)
			{
				cout << "Do you want to save your lists before you exit?[Y/N] ";
				cin >> yesNo;
				if (yesNo == 'N' || yesNo == 'n')
				{
					cout << "\nExiting. . .\n";
					exit(1);
				}
			}

			while (true)//user verification
			{

				cout << "Enter the name of the file to print to: ";
				cin >> fileName;

				cout << "Is this file name correct? [Y/N] \"" << fileName << "\"" << endl;
				cin >> yesNo;

				if (yesNo == 'Y' || yesNo == 'y'){
					break;
				}
			}
			assignment.printToFile(fileName);
			cout << "Lists were saved to file! \n\n";
		}
			
		if (choice == 7)//if they chose to exit
		{
			cout << "\nExiting";
			exit(1);
		}
		else//no change made to list, do not save
		{
			cout << "File was not changed, nothing to save.\n";
		}

			
	}


private:
	AssignmentList assignment;
	bool file_change;
};




#endif
