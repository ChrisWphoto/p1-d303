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

	void process_orders()
	{
		bool again = true; //always start loop over until exit is selected


		string orders[] = {
			"Display Assignments",
			"Add Assignment",
			"Add Assignment from txt file",
			"Edit Assignment",
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
				cout << i << ": " << orders[i] << endl;
			}

			cin >> choice;
			while (choice < 0 || choice > 8)//error check
			{
				cout << "Invalid choice, please select again: ";
				cin >> choice;
			}


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
			case 6:
				save_lists(choice);//save list, and exit depending on the user's choice
				break;
			case 7: //exit
				return;

			}
		}
	}


		void display_assignments()
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
				cout << i << ": " << displayLists[i] << endl;
			}
			cin >> display;
			while (display < 0 || display > 2) //error check
			{
				cout << "Invalid choice, please select again: ";
				cin >> display;
			}
			switch (display)
			{
			case 0:
				assignment.displayAssignedList();
				break;
			case 1:
				assignment.displayCompletedList();
				break;
			case 2:
				assignment.displayAssignedList();
				assignment.displayCompletedList();
				break;
			};
		}

		void add_assignment()
		{
			AssignNode new_assign;
			AssignmentList add_new;
			cin.ignore();
			cout << "Enter in the new assignment details on one line, separated by commas. \n[Assigned Date], [Description], [Due Date], [Status]\n";
			cin >> new_assign;
			add_new.addAssignment(new_assign);
		}

		//adding from file -CW
		void add_assign_from_file(){
		
			string fileName;
			
			while (true)
			{
				
				cout << "Enter the name of the file \n";

				cin >> fileName; 

				char yesNo; 

				cout << "Is this file name correct? [Y/N] " << fileName << endl; 

				cin >> yesNo; 

				if (yesNo == 'Y' || yesNo == 'y'){
					break;
				}
			}
			
			assignment.addFromFile(fileName, assignment); //calling assignment list
		
		}



		void edit_assignment()
		{
			
			//Need to make it a call by reference or pointer to edit it in the list?


			string options[] = { "edit due date", "edit description" };
			int choice;
			cout << "What would you like to edit? \n";
			for (int i = 0; i < 2; i++)
			{
				cout << i << ": " << options[i] << endl;
			}

			cin >> choice;
			while (choice < 0 || choice > 1)//error check
			{
				cout << "Invalid choice, please select again: ";
				cin >> choice;
			}

			string due_date;
			cin.ignore();
			cout << "\nEnter the assigned date to edit (MM-DD-YYYY): ";
			getline(cin, due_date);
			Date date(due_date, DateFormat::US);


			AssignNode* holder;

			//if in assigned list
			//holder is a ptr to the node we are editing
			holder = assignment.getAssignedItem(date);

			cout << "This is holder : " << *holder << endl;

			switch (choice)
			{
			case 0:
				edit_due_date(holder);
				break;
			case 1:
				edit_description(holder);
				break;
			}

		}
		void edit_due_date(AssignNode* holder)
		{
			

			string due_date;
			//change due date

			cout << "What is the new due date for this file? ";
			getline(cin, due_date);

			holder->setDueDate(due_date);

			cout << "Success\n";

			return;

		}
		void edit_description(AssignNode* holder)
		{
			string tempDescription;


			//change description of the file

			cout << "What is the new description for this file? ";
			//cin.ignore(); deletes first letter of word -CW
			getline(cin, tempDescription);

			holder->setDescript(tempDescription);
			cout << "Success\n";

			return;
		}


		void complete_assignment()
		{

			string due_date;
			cin.ignore();
			cout << "\nEnter the assigned date to complete (MM-DD-YYYY): ";
			getline(cin, due_date);
			Date date(due_date, DateFormat::US);

			assignment.completeAssignment(date);//complete assignment with date given by user
		}

		void list_late()
		{
			int late = 0;
			late = assignment.getLateCount();
			cout << "There are " << late << " late assignments. \n\n";

		}

		void save_lists(int choice)
		{
			//assignment.print_to_file();

			//if they chose to exit
			if (choice == 7)
			{
				exit(1);
			}
		}


		


	private:
		AssignmentList assignment;
};



















#endif