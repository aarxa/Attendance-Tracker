#include "Stacks.h"
using std::string;
using std::vector;

//push is used to enter a new absence to the list
void Stack::push(string newAbsence)
{
	stackData.push_back(newAbsence);
}

//Pop is used to track the absence record
void Stack::pop()
{
	if (!isEmpty())
	{
		stackData.pop_back();
	}
}

string Stack::peek()
{
	if (stackData.size() > 0)
	{
		return stackData.back();
	}
	return "";
}

bool Stack::isEmpty()
{
	return stackData.empty();
}
