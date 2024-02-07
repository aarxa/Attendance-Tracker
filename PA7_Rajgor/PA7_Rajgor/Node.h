/*******************************************************************************************

* Programmer: Aarya Rajgor                                                                 *

* Class: CptS 122, Fall 2022; Lab Section 05                                               *

* Programming Assignment: 07                                                               *

* Date: November 4, 2022                                                                   *

* Description: This program tracks attendence with class templates.                        *

*******************************************************************************************/

#pragma once

#include "PA7.h"

template <class T>
class Node {
private:
	Node* next;
	T nodeData;

public:
	Node() : next(nullptr), nodeData() {}
	Node(T _nodeData) : nodeData(_nodeData) {}
	Node(Node* _next, T _nodeData) : next(_next), nodeData(_nodeData) {}
	~Node() {}

	//GETTERS
	Node* getNext()
	{
		return next;
	}

	T getData()
	{
		return nodeData;
	}

	//SETTERS
	void setNext(Node* pNext) { next = pNext; }
	void setData(T newData) { nodeData = newData; }
};
