#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include "iPersonMotron.h"
#include <iostream>

#define SIZE 2

class cMyVector
{
public:
	cMyVector();
	~cMyVector();

	void push_back(sPerson);
	sPerson get_index(unsigned int);
	void set_index(unsigned int, sPerson);

	unsigned int size();
	unsigned int capacity();

	sPerson& operator[](int i)
	{
		return this->mData[i];
	}
	const sPerson& operator[](int i) const
	{
		return this->mData[i];
	}

	void clear();
private:
	sPerson * mData;
	unsigned int mCapacity;
	unsigned int mCurrentSize;

	void doubleCap(int);
};

#endif // !_MY_VECTOR_
