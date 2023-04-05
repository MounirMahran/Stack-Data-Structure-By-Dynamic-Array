#pragma once
#include <iostream>

using namespace std;

template <class T> 
class clsDynamicArray
{
	short _Size = 0;
	T* TempArray;

public:
	T* OriginalArray;

	clsDynamicArray(short Size = 0) {
		if (Size <= 0) Size = 0;

		_Size = Size;

		OriginalArray = new T[_Size];
	}

	~clsDynamicArray() {
		delete[] OriginalArray;
	}

	bool SetItem(short Index, T Value) {
		if (Index < 0 || Index >= _Size) return false;
		OriginalArray[Index] = Value;
		return true;
	}

	void PrintList() {
		if (_Size == 0) return;
		for (int i = 0; i < _Size; i++) {
			cout << OriginalArray[i] << " ";
		}
		cout << endl;
	}

	short Size() {
		return _Size;
	}

	bool IsEmpty() {
		return _Size == 0;
	}

	void Resize(short NewSize) {
		TempArray = new T[NewSize];

		_Size = NewSize;
		for (short i = 0; i < _Size; i++) TempArray[i] = OriginalArray[i];
		delete[] OriginalArray;

		OriginalArray = TempArray;


	}

	T GetItem(short Index) {
		if (Index < 0 || Index >= _Size) return 0;
		return OriginalArray[Index];
	}

	void Reverse() {
		TempArray = new T[_Size];
		for (short i = 0; i < _Size; i++) TempArray[i] = OriginalArray[_Size - i - 1];
		
		delete[] OriginalArray;
		OriginalArray = TempArray;
	}

	void Clear() {
		_Size = 0;
		TempArray = new T[0];
		delete[] OriginalArray;
		OriginalArray = TempArray;
	}

	bool Delete(short Index) {
		if (Index < 0 || Index >= _Size) return false;

		for (short i = Index; i < _Size; i++) OriginalArray[i] = OriginalArray[i + 1];

		Resize(_Size - 1);

		return true;
	}

	bool DeleteFirstItem() {
		return Delete(0);
	}

	bool DeleteLastItem() {
		return Delete(_Size - 1);
	}

	short Find(T Value) {
		for (short i = 0; i < _Size; i++) if (OriginalArray[i] == Value) return i;
		return -1;
	}

	bool DeleteItem(T Value) {
		return Delete(Find(Value));
	}

	bool InsertAt(short Index, T Value) {
		if (Index < 0 || Index > _Size) return false;

		_Size++;
		Resize(_Size);

		for (short i = _Size - 1; i >= Index; i--) {
			OriginalArray[i] = OriginalArray[i - 1];
		}

		OriginalArray[Index] = Value;

		return true;
	}

	bool InsertAtBeginning(T Value) {
		return InsertAt(0, Value);
	}

	bool InsertAtEnd(T Value) {
		return InsertAt(_Size, Value);
	}

	bool InsertBefore(short Index, T Value) {
		return InsertAt(Index - 1, Value);
	}

	bool InsertAfter(short Index, T Value) {
		return InsertAt(Index + 1, Value);
	}

};

