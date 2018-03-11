#include "cMyVector.h"


cMyVector::cMyVector()
{
	this->mData = new sPerson[SIZE];
	this->mCapacity = SIZE;
	this->mCurrentSize = 0;
}
cMyVector::~cMyVector()
{
	delete[] this->mData;
}

void cMyVector::push_back(sPerson p)
{
	if (this->mCurrentSize >= this->mCapacity)
	{
		doubleCap(this->mCapacity * 2);
		
	}
	this->mData[mCurrentSize] = p;
	mCurrentSize++;
}
sPerson cMyVector::get_index(unsigned int index)
{
	return this->mData[index];
}
void cMyVector::set_index(unsigned int index, sPerson person)
{
	this->mData[index] = person;
}

void cMyVector::clear()
{
	delete[] this->mData;
	this->mData = new sPerson[SIZE];
	this->mCurrentSize = 0;
	this->mCapacity = SIZE;
}
unsigned int cMyVector::size()
{
	return this->mCurrentSize;
}
unsigned int cMyVector::capacity()
{
	return this->mCapacity;
}


void cMyVector::doubleCap(int size)
{
	if (size <= this->mCapacity)
		return;

	sPerson * temp = new sPerson[size];
	for (int i = 0; i != this->mCapacity; i++)
	{
		temp[i] = this->mData[i];
	}
	this->mCapacity = size;

	delete[] this->mData;
	this->mData = temp;
}