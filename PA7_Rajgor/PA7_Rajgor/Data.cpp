#include "Data.h"

Data::Data()
{
	recordNumber = 0;
	id = 0;
	name = "";
	email = "";
	units = "";
	program = "";
	level = "";
}

Data::Data(int record, int id, string name, string email, string units, string major, string level, int numAbsence)
{
	recordNumber = record;
	this->id = id;
	this->name = name;
	this->email = email;
	this->units = units;
	this->program = major;
	this->level = level;
	numAbsences = numAbsence;
}

Data::~Data()
{
	//default destructor
}

//Getters
int Data::getRecord()
{
	return recordNumber;
}

int Data::getID()
{
	return id;
}

string Data::getName()
{
	return name;
}

string Data::getEmail()
{
	return email;
}

string Data::getUnits()
{
	return units;
}

string Data::getMajor()
{
	return program;
}

string Data::getLevel()
{
	return level;
}

int Data::getAbsences()
{
	return numAbsences;
}

//SETTERS
void Data::setRecord(int record)
{
	recordNumber = record;
}

void Data::setID(int id)
{
	this->id = id;
}

void Data::setName(string name)
{
	this->name = name;
}

void Data::setEmail(string email)
{
	this->email = email;
}

void Data::setUnits(string units)
{
	this->units = units;
}

void Data::setMajor(string major)
{
	program = major;
}

void Data::setLevel(string level)
{
	this->level = level;
}

void Data::setAbsences(int num)
{
	numAbsences = num;
}
