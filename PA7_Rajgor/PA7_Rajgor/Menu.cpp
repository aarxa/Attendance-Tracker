#include "Menu.h"

void Menu::printMenu()
{
	cout << "Welome to PA7!!!" << endl;
	cout << "This program tracks attendence for a class which can be viewed, modified, etc." << endl << endl;
	cout << "Menu:" << endl;
	cout << "\t1.  Import course list" << endl;
	cout << "\t2.  Load master list" << endl;
	cout << "\t3.  Store master list" << endl;
	cout << "\t4.  Mark absences" << endl;
	cout << "\t5.  BONUS: Edit absences" << endl;
	cout << "\t6.  Generate report" << endl;
	cout << "\t7.  Exit" << endl << endl;
}

void Menu::case6Menu()
{
	cout << endl;
	cout << "\t(1). Generate report for all students and show only the most recent absences the students have had." << endl;
	cout << "\t(2). Generate report for students whose absences match or surpass." << endl;
}