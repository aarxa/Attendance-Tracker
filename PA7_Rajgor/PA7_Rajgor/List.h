/*******************************************************************************************

* Programmer: Aarya Rajgor                                                                 *

* Class: CptS 122, Fall 2022; Lab Section 05                                               *

* Programming Assignment: 07                                                               *

* Date: November 4, 2022                                                                   *

* Description: This program tracks attendence with class templates.                        *

*******************************************************************************************/

#pragma once

#include "PA7.h"
#include "Node.h"

//Template class for LinkedList.
template <class T>
class List
{
private:
	Node<T>* head;

public:
	List() : head(nullptr) {}
	~List() {}

	//Overloaded assignment operator
	List& operator = (List& Lobj)
	{
		head = Lobj.getHead();
		return *this;
	}

	bool insertAtFront(T data)
	{
		bool success = false;
		Node<T>* node = new Node<T>(data);
		if (node != nullptr)
		{
			success = true;
			node->setNext(head);
			head = node;
		}
		return success;
	}

	//GETTERS
	Node<T>* getHead()
	{
		return head;
	}

	//SETTERS
	void setHead(Node<T>* newHead) { head = newHead; }
};
