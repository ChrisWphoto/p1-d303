#include <iostream>
#include "Date\Date.h"
#include "AssignNode.h"
#include "Date\StringTokenizer.h"
#include <string>
#include <fstream>
#include "user_interface.h"
using namespace std;

int main() {

	user_interface theInterface; 

	theInterface.process_orders();

	

	system("pause");
	return 0; 
}