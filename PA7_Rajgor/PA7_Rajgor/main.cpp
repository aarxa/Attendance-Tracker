/*******************************************************************************************

* Programmer: Aarya Rajgor                                                                 *

* Class: CptS 122, Fall 2022; Lab Section 05                                               *

* Programming Assignment: 07                                                               *

* Date: November 4, 2022                                                                   *

* Description: This program tracks attendence with class templates.                        *

*******************************************************************************************/

#include "PA7.h"
#include "Data.h"
#include "Menu.h"
#include "List.h"

int main(void)
{
	Menu appMenu;
	List<Data> records;

	time_t t = time(0);
	struct tm* now = localtime(&t);
	fstream infile;
	int choice = 0, n = 0;
	bool running = true;

	while (running)
	{
		system("cls");
		appMenu.printMenu();
		cout << "\t Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1: //Import course List
		{
			system("cls");
			char buffer1[50] = { '\0' };
			char buffer2[50] = { '\0' };

			int num = 1;
			infile.open("classList.csv"); //openi g the file
			if (infile.is_open()) // runs if the file if open
			{
				for (int i = 0; i < 7; i++)
				{
					infile.getline(buffer1, 50, ','); //getting the first line of the file
				}

				while (!infile.eof()) //loop runs till the file is empty
				{
					Data newRecord;
					//set the record in order
					newRecord.setRecord(num++);
					infile.getline(buffer1, 50, ',');
					//sets the ids in order
					newRecord.setID(atoi(buffer1));
					infile.getline(buffer1, 50, ',');
					infile.getline(buffer2, 50, ',');
					strcat(buffer1, ",");
					strcat(buffer1, buffer2);
					//sets the names in order
					newRecord.setName(buffer1);
					infile.getline(buffer1, 50, ',');
					//sets the emails in order
					newRecord.setEmail(buffer1);
					infile.getline(buffer1, 50, ',');
					//sets the units in order
					newRecord.setUnits(buffer1);
					infile.getline(buffer1, 50, ',');
					//sets the majors in order
					newRecord.setMajor(buffer1);
					infile.getline(buffer1, 50, ',');
					newRecord.setLevel(buffer1);
					infile.getline(buffer1, 50, ',');
					newRecord.setAbsences(atoi(buffer1));

					string processed = buffer1;
					processed.erase(std::remove(processed.begin(), processed.end(), '\n'), processed.end());
					//Solution for removing non-alpha numeric characters from string using STL provided by "songyuanyao",
					//https://stackoverflow.com/questions/28491954/remove-non-alphabet-characters-from-string-c
					//Removes over-read characters after deleting newline. This is done to comply with the provided .csv file.
					processed.erase(std::remove_if(processed.begin(), processed.end(), [](char c) { return !isalpha(c); }), processed.end());
					newRecord.setLevel(processed);
					newRecord.setAbsences(0);

					//Insert student record into list
					records.insertAtFront(newRecord);
				}
				cout << "The course file has been imported successfully!" << endl;
			}
			else
			{
				cout << "Failed to import the course file!" << endl;
			}

			infile.close();
			system("pause");
			break;
		}

		case 2: //Load the master List
		{
			system("cls");
			int i;
			char buffer1[50] = { '\0' };
			char buffer2[50] = { '\0' };
			fstream masterFile;

			masterFile.open("master.csv");
			if (masterFile.is_open())
			{
				int num = 1;
				masterFile.getline(buffer1, 50, ',');
				while (!masterFile.eof())
				{
					Data newRecord;

					newRecord.setRecord(num++);
					masterFile.getline(buffer1, 50, ',');

					newRecord.setID(atoi(buffer1));
					masterFile.getline(buffer1, 50, ',');
					masterFile.getline(buffer2, 50, ',');
					strcat(buffer1, ",");
					strcat(buffer1, buffer2);
					//sets the names in order
					newRecord.setName(buffer1);
					masterFile.getline(buffer1, 50, ',');
					//sets the emails in order
					newRecord.setEmail(buffer1);
					masterFile.getline(buffer1, 50, ',');
					//sets the units in order
					newRecord.setUnits(buffer1);
					masterFile.getline(buffer1, 50, ',');
					//sets the majors in order
					newRecord.setMajor(buffer1);
					masterFile.getline(buffer1, 50, ',');
					//sets the level in order
					newRecord.setLevel(buffer1);
					masterFile.getline(buffer1, 50, ',');
					newRecord.setAbsences(atoi(buffer1));

					Stack newAbsence;
					int iterations = newRecord.getAbsences();

					for (i = 0; i < iterations; i++)
					{
						masterFile.getline(buffer1, 50, ',');
						string num = buffer1;
						num.erase(std::remove(num.begin(), num.end(), '\n'), num.end());
						newAbsence.push(num);
						newRecord.setStack(newAbsence);
					}
					records.insertAtFront(newRecord);
					masterFile.getline(buffer1, 50, ',');
				}

				cout << "Master List loaded successfully!!" << endl;
			}
			else
			{
				cout << "Error in loading the master list!" << endl;
			}
			system("pause");
			break;
		}

		case 3: //Store the master List
		{
			system("cls");
			fstream master;
			master.open("master.csv");

			int tracker = 1;
			if (master.is_open())
			{
				Node<Data>* temp = records.getHead();
				while (temp != NULL)
				{
					Data currentRecord = temp->getData();
					master << tracker++ << "," << currentRecord.getID() << "," << currentRecord.getName() << "," << currentRecord.getEmail() << "," << currentRecord.getUnits() << "," << currentRecord.getMajor() << "," << currentRecord.getLevel() << "," << currentRecord.getAbsences() << ",";
					if (currentRecord.getAbsences() > 0)
					{
						Stack tempStack = currentRecord.getStack();
						for (int i = 0; i < currentRecord.getAbsences(); i++)
						{
							master << tempStack.peek() << ",";
							tempStack.pop();
							if (tempStack.isEmpty())
							{
								master << endl;
							}
						}
					}

					else
					{
						master << endl;
					}

					temp = temp->getNext();
				}
				cout << "Master list stored successfully!!" << endl;;
				master.close();
			}
			else
			{
				cout << "Failed to store the master list!!" << endl;
			}
			system("pause");
			break;
		}

		case 4: //Mark Absences
		{
			system("cls");
			List<Data> temp = records;
			Node <Data>* tempNode = temp.getHead();
			while (tempNode != nullptr)
			{
				char ab = '\0';
				cout << tempNode->getData().getRecord() << "-" << tempNode->getData().getName() << ": is he/she absent (Y/N)? ";
				cin >> ab;

				if (toupper(ab) == 'Y' || toupper(ab) == 'y')
				{
					Data current = tempNode->getData();
					int numA = current.getAbsences();
					current.setAbsences(numA + 1);
					string date = to_string((now->tm_year + 1900)) + "-" + to_string((now->tm_mon + 1)) + "-" + to_string(now->tm_mday);
					date.erase(std::remove(date.begin(), date.end(), '\n'), date.end());
					Stack absences = current.getStack();
					absences.push(date);
					current.setStack(absences);
					tempNode->setData(current);
				}
				tempNode = tempNode->getNext();
			}
			records = temp;
			cout << "Absences marked successfully!!" << endl;
			system("pause");
			break;
		}

		case 5: //BONUS: Edit Absences
		{
			system("cls");
			int ans = 0, found = 0;
			cout << "Do you want to edit the absences by Student's (1)ID or (2)Name? ";
			cin >> ans;

			if (ans == 2)
			{
				string firstName, lastName, name;
				cout << "What is the FIRST name of the student whose absence record you wish to edit? ";
				cin >> firstName;
				cout << "What is the LAST name of the student whose absence record you wish to edit? ";
				cin >> lastName;
				name = "\"" + lastName + "," + firstName + "\"";

				//Linear time search
				Node<Data>* temp = records.getHead(); //temp node goes to the first node
				while (temp != nullptr)
				{
					if (temp->getData().getName().compare(name) == 0)
					{
						found = 1;
						break;
					}
					temp = temp->getNext();
				}

				if (found == 0)
				{

				}

				else if (found == 1)
				{
					string date;
					cout << "Student found! " << endl;
					if (temp->getData().getAbsences() > 0)
					{
						bool foundName = false;
						cout << "Enter the date the student was present but was marked absent (YYYY-MM-DD): ";
						cin >> date;
						Data currentData = temp->getData();
					}
				}
			}
		}

		case 6: //Generate Report
		{
			int select;
			system("cls");
			appMenu.case6Menu();
			cout << "\n\tEnter your choice: ";
			cin >> select;

			if (select == 1)
			{
				system("cls");
				fstream absencesReport;
				absencesReport.open("absenceReport.txt");
				if (absencesReport.is_open())
				{
					List<Data> temp = records;
					Node<Data>* tempNode = temp.getHead();
					while (tempNode != nullptr)
					{
						Stack absences = tempNode->getData().getStack();
						absencesReport << tempNode->getData().getName() << ", most recent absence: " << absences.peek() << endl;
						tempNode = tempNode->getNext();
					}
					cout << "Check the Absence Report File!! ";
					cout << "Report saved to the file successfully!" << endl;
					absencesReport.close();
				}
				else
				{
					cout << "Failed to open the file!" << endl;
				}
				system("pause");
			}

			else if (select == 2)
			{
				system("cls");
				int min = 0;
				fstream absenceGreater;
				absenceGreater.open("absenceGreater.txt");
				if (absenceGreater.is_open())
				{
					cout << "What do you want the least number of absences to be?: ";
					cin >> min;

					List<Data> temp = records;
					Node<Data>* tempNode = temp.getHead();
					absenceGreater << "Students with absences greater than " << min << " are: " << endl;
					while (tempNode != nullptr)
					{
						if (tempNode->getData().getAbsences() > min)
						{
							absenceGreater << tempNode->getData().getName() << endl;
						}
						tempNode = tempNode->getNext();
					}
					cout << "Check the Absence Greater Report File!! ";
					cout << "Report saved to the file successfully!" << endl;
					absenceGreater.close();
				}
				else
				{
					cout << "Failed to open the file!" << endl;
				}
			}
			system("pause");
			break;
		}

		case 7:
			system("cls");
			running = false;
			break;
		}
	}

	return 0;
}