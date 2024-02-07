
/*******************************************************************************************

* Programmer: Aarya Rajgor                                                                 *

* Class: CptS 122, Fall 2022; Lab Section 05                                               *

* Programming Assignment: 07                                                               *

* Date: November 4, 2022                                                                   *

* Description: This program tracks attendence with class templates.                        *

*******************************************************************************************/

#pragma once

#include "PA7.h"
#include "Stacks.h"

class Data
{
private:
	int recordNumber;
	int id;
	string name;
	string email;
	string units;
	string program;
	string level;
	int numAbsences;
	Stack absencesInfo;

public:
	Data(); //default constructor
	Data(int recordNum, int idNum, string name, string email, string units, string major, string level, int absenceNum);
	~Data(); //default destructor

	Data& operator = (Data& Dobj)
	{
		recordNumber = Dobj.getRecord();
		id = Dobj.getID();
		name = Dobj.getName();
		email = Dobj.getEmail();
		units = Dobj.getUnits();
		program = Dobj.getMajor();
		level = Dobj.getLevel();
		numAbsences = Dobj.getAbsences();
		absencesInfo = Dobj.getStack();
		return *this;
	}

	//GETTERS
	int getRecord(void);
	int getID(void);
	string getName(void);
	string getEmail(void);
	string getUnits(void);
	string getMajor(void);
	string getLevel(void);
	int getAbsences(void);
	Stack getStack(void)
	{
		return absencesInfo;
	}

	//SETTERS
	void setRecord(int record);
	void setID(int ID);
	void setName(string name);
	void setEmail(string email);
	void setUnits(string units);
	void setMajor(string major);
	void setLevel(string level);
	void setAbsences(int num);
	void setStack(Stack newStack) { absencesInfo = newStack; }
};