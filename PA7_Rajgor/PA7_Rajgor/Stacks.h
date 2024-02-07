/*******************************************************************************************

* Programmer: Aarya Rajgor                                                                 *

* Class: CptS 122, Fall 2022; Lab Section 05                                               *

* Programming Assignment: 07                                                               *

* Date: November 4, 2022                                                                   *

* Description: This program tracks attendence with class templates.                        *

*******************************************************************************************/

#pragma once
#include "PA7.h"

class Stack
{
public:
	//Constructor and Destructor 
	Stack() {}
	~Stack() {}

	void push(string newAbsence);
	void pop();
	string peek();
	bool isEmpty();

private:
	vector<string> stackData;
};