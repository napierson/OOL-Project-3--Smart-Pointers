#include "PtrList.h"



PtrList::PtrList() : head_(nullptr), size_(0)
{
}

PtrList::PtrList(int i) : size_(i)
{
	head_ = new Node(0);
	Node* current = head_;
	for (int j = 1; j < size_; j++)
	{
		current->next_ = new Node(j);
		current = current->next_;
	}
}


PtrList::~PtrList()
{
	delete head_;
}

AppliancePtr & PtrList::at(int i)
{
	Node* current = head_;
	if (0 <= i && i < size_)
	{		
		for (int j = 0; j < i; j++)
		{
			current = current->next_;
		}
	}
	return *(current->app_);
}

int PtrList::size()
{
	return size_;
}

PtrList::Node::Node(int i) : ID_(i)
{
	app_ = new AppliancePtr(i);
}

PtrList::Node::~Node()
{
	delete app_;
	delete next_;
}
