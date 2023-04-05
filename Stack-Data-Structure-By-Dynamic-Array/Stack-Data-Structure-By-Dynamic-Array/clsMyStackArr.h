#pragma once
#include "clsMyQueue.h"

template <class T>
class clsMyStackArr : public clsMyQueue <T>
{
public:

	void Push(T Item) {
		clsMyQueue <T>::Queue.InsertAtBeginning(Item);
	}

	T Top()
	{
		return clsMyQueue <T>::Front();

	}

	T Bottom()
	{
		return clsMyQueue <T>::Back();

	}
};

