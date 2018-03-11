#ifndef  _MY_LIST_HG_
#define _MY_LIST_HG_

#include "cPerson.h"



class cMyList
{
public:
	template<class T>
	struct cNode
	{
		cNode();
		sPerson person;
		cNode * next;
		cNode * prev;
	};

	cMyList();


	void AddStart(sPerson);
	void AddEnd(sPerson);
	// Deletes the current node
	void DeleteNode();
	void DeleteStart();
	void DeleteEnd();
	//// Deletes a specific node
	//void DeleteNode(int index);
	//
	sPerson GetCurrentNode();
	bool GetCurrentNode(sPerson &);
	
	void SetCurrentNode(sPerson);

	void PrintAll();

	void MoveNext();
	void MovePrev();
	void MoveStart();
	void MoveEnd();
	unsigned int size();






private:
	unsigned int mSize;
	cNode<sPerson> *mFirst;
	cNode<sPerson> *mLast;
	cNode<sPerson> *mCurrent;
};
#endif // ! _MY_LIST_HG_