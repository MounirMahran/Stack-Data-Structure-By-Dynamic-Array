#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

template <class T>
class clsMyQueue
{
protected:
	clsDynamicArray <T> Queue;
public:

	void Push(T Value) {
		Queue.InsertAtEnd(Value);
	}

	void Pop() {
		Queue.DeleteFirstItem();
	}

	void Print() {
		Queue.PrintList();
	}

	short Size() {
		return Queue.Size();
	}

	T Front() {
		return Queue.GetItem(0);
	}

	T Back() {
		return Queue.GetItem(Size() - 1);
	}

	void Reverse() {
		Queue.Reverse();
	}

	T GetItem(short Index) {
		return Queue.GetItem(Index);
	}

	bool UpdateItem(short Index, T Value) {
		return Queue.SetItem(Index, Value);
	}

	bool InsertAfter(short Index, T Value) {
		return Queue.InsertAfter(Index, Value);
	}

	bool InsertAtFront(T Value) {
		return Queue.InsertAtBeginning(Value);
	}

	bool InsertAtBack(T Value) {
		return Queue.InsertAtEnd(Value);
	}

	void Clear() {
		Queue.Clear();
	}
};

