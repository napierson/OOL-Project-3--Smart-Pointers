#pragma once
#include "AppliancePtr.h"
class PtrList
{
public:
	PtrList();
	PtrList(int i);
	~PtrList();

	AppliancePtr& at(int i);
	int size();

	

protected:
	class Node
	{
	public:
		Node(int i);
		~Node();

		int ID_;
		Node* next_;
		AppliancePtr* app_;
	};

	int size_;
	Node* head_;
};

