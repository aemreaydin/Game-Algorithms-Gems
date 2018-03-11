#include "cMyList.h"

template<class T>
cMyList::cNode<T>::cNode()
{
	this->next = NULL;
	this->prev = NULL;
}

cMyList::cMyList()
{
	this->mSize = 0;
	this->mCurrent = NULL;
	this->mFirst = NULL;
	this->mLast = NULL;
}

void cMyList::AddStart(sPerson person)
{
	cNode<sPerson> * tempNode = new cNode<sPerson>;
	tempNode->person = person;

	if (this->mFirst == NULL)
	{
		this->mFirst = tempNode;
		this->mLast = tempNode;
		this->mCurrent = tempNode;
		this->mSize++;
		return;
	}
	// Just In Case
	tempNode->prev = NULL;
	tempNode->next = this->mFirst;

	this->mFirst->prev = tempNode;
	this->mFirst = tempNode;
	// Optional I guess
	this->mCurrent = tempNode;	

	this->mSize++;
}
void cMyList::AddEnd(sPerson person)
{
	cNode<sPerson> * tempNode = new cNode<sPerson>;
	tempNode->person = person;

	if(this->mFirst == NULL)
	{
		this->mFirst = tempNode;
		this->mLast = tempNode;
		this->mCurrent = tempNode;
		this->mSize++;
		return;
	}
	// I don't think I need to do this but if I want currentNode to point to the added object I have to do this
	while (this->mCurrent->next != NULL)
		this->mCurrent = this->mCurrent->next;

	tempNode->prev = this->mLast;
	this->mLast->next = tempNode;
	this->mLast = tempNode;
	// Optional I guess
	this->mCurrent = tempNode;

	this->mSize++;
}
void cMyList::DeleteNode()
{
	if (this->mCurrent == NULL)
		return;

	cNode<sPerson> * nextNode = this->mCurrent->next;
	cNode<sPerson> * prevNode = this->mCurrent->prev;

	// If only one node delete the node and set nodes to 0
	if (this->mCurrent == this->mFirst && this->mCurrent == this->mLast)
	{
		delete this->mCurrent;
		this->mCurrent = NULL;
		this->mLast = NULL;
		this->mFirst = NULL;
		this->mSize = 0;
		return;
	}

	if (this->mCurrent == this->mLast)
	{
		DeleteEnd();
		return;
	}
	if (this->mCurrent == this->mFirst)
	{
		DeleteStart();
		return;
	}
	prevNode->next = nextNode;
	nextNode->prev = prevNode;

	delete this->mCurrent;
	this->mCurrent = nextNode;
	this->mSize--;
}
void cMyList::DeleteStart()
{
	if (this->mFirst == NULL)
		return;

	cNode<sPerson> * nextNode = this->mFirst->next;
	cNode<sPerson> * prevNode = this->mFirst->prev;

	// If only one node delete the node and set nodes to 0
	if (nextNode == NULL)
	{
		delete this->mFirst;
		this->mCurrent = NULL;
		this->mLast = NULL;
		this->mFirst = NULL;
		this->mSize = 0;
		return;
	}

	nextNode->prev = NULL;	
	if (this->mFirst == this->mCurrent)
		this->mCurrent = nextNode;
	delete this->mFirst;
	this->mFirst = nextNode;
	this->mSize--;
}
void cMyList::DeleteEnd()
{
	if (this->mLast == NULL)
		return;

	cNode<sPerson> * nextNode = this->mLast->next;
	cNode<sPerson> * prevNode = this->mLast->prev;

	// If only one node delete the node and set nodes to 0
	if (prevNode == NULL)
	{
		delete this->mLast;
		this->mCurrent = NULL;
		this->mFirst = NULL;
		this->mLast = NULL;
		this->mSize = 0;
		return;
	}

	prevNode->next = NULL;
	if (this->mCurrent == this->mLast)
		this->mCurrent = prevNode;
	delete this->mLast;
	this->mLast = prevNode;
	this->mSize--;
}

sPerson cMyList::GetCurrentNode()
{
	return this->mCurrent->person;
}
bool cMyList::GetCurrentNode(sPerson &person)
{
	if (this->mCurrent == NULL)
		return false;
	person = this->mCurrent->person;
	return true;
}
void cMyList::SetCurrentNode(sPerson person)
{
	this->mCurrent->person = person;
}

void cMyList::MoveNext()
{
	if (this->mCurrent->next == NULL)
		return;

	this->mCurrent = this->mCurrent->next;
}
void cMyList::MovePrev()
{
	if (this->mCurrent->prev == NULL)
		return;

	this->mCurrent = this->mCurrent->prev;
}
void cMyList::MoveStart()
{
	if (this->mCurrent == NULL)
		return;

	while (this->mCurrent != this->mFirst)
		this->mCurrent = this->mCurrent->prev;
}

void cMyList::MoveEnd()
{
	if (this->mCurrent == NULL)
		return;

	while (this->mCurrent != this->mLast)
		this->mCurrent = this->mCurrent->next;
}

unsigned int cMyList::size()
{
	return this->mSize;
}

void cMyList::PrintAll()
{
	this->MoveStart();
	printf("Generated List:\n");
	while (this->mCurrent != this->mLast)
	{
		printf("ID : %d, Name : %s %s, Location : %f-%f-%f, Health : %f\n", 
			this->mCurrent->person.uniqueID,
			this->mCurrent->person.first.c_str(),
			this->mCurrent->person.last.c_str(),
			this->mCurrent->person.location.x,
			this->mCurrent->person.location.y,
			this->mCurrent->person.location.z,
			this->mCurrent->person.health);
		this->mCurrent = this->mCurrent->next;
	}

	if(this->mCurrent == this->mLast)
		printf("ID : %d, Name : %s %s, Location : %f-%f-%f, Health : %f\n",
			this->mCurrent->person.uniqueID,
			this->mCurrent->person.first.c_str(),
			this->mCurrent->person.last.c_str(),
			this->mCurrent->person.location.x,
			this->mCurrent->person.location.y,
			this->mCurrent->person.location.z,
			this->mCurrent->person.health);
}