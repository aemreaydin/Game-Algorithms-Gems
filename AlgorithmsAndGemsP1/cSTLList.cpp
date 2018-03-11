#include "cSTLList.h"
#include <algorithm>
#include <stdlib.h>
#include <iostream>

// FIND PEOPLE BY NAME RETURN
// GENERATE PEOPLE RANDOMLY
// HEALTH AND POINT STUFF
#define LENGTH 200


bool loadDataIntoVector(std::string femaleNamesFileName, std::vector<std::string> &vecFirstFemale,
	std::string maleNamesFileName, std::vector<std::string> &vecFirstMale,
	std::string lastNamesFileName, std::vector<std::string> &vecLast,
	std::string &error);

// Uses c interface, rather than C++ one (so WAY faster)
bool loadDataIntoVector2(std::string femaleNamesFileName, std::vector<sPerson> &vecFirstFemale,
	std::string maleNamesFileName, std::vector<sPerson> &vecFirstMale,
	std::string lastNamesFileName, std::vector<sPerson> &vecLast,
	std::string &error);



bool cSTLList::LoadDataFilesIntoContainer(std::string firstNameFemaleFileName,
	std::string firstNameMaleFileName,
	std::string lastNameFileName)
{
	clock_t t = clock();
	std::vector<sPerson> femaleNames;
	std::vector<sPerson> maleNames;
	std::vector<sPerson> lastNames;
	if (!loadDataIntoVector2(firstNameFemaleFileName, femaleNames,
		firstNameMaleFileName, maleNames,
		lastNameFileName, lastNames, error))
	{
		return false;
	}
	for (int i = 0; i != femaleNames.size(); i++)
		this->listFemaleNames.push_back(femaleNames[i]);
	for (int i = 0; i != maleNames.size(); i++)
		this->listMaleNames.push_back(maleNames[i]);
	for (int i = 0; i != lastNames.size(); i++)
		this->listLastNames.push_back(lastNames[i]);
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}
bool cSTLList::GenerateRandomPeople(int numberOfPeople)
{
	clock_t t = clock();
	std::list<sPerson> allNames;
	int ID = 0;
	std::list<sPerson>::iterator femaleIter;
	std::list<sPerson>::iterator maleIter;
	std::list<sPerson>::iterator lastIter;
	std::list<sPerson>::iterator allIter;
	for (femaleIter = this->listFemaleNames.begin(); femaleIter != this->listFemaleNames.end(); femaleIter++)
	{
		allNames.push_back(*femaleIter);
	}
	for (maleIter = this->listMaleNames.begin(); maleIter != this->listMaleNames.end(); maleIter++)
	{
		allNames.push_back(*maleIter);
	}
	//for (lastIter = this->listLastNames.begin(); lastIter != this->listLastNames.end(); lastIter++)
	//{
	//	allNames.push_back(*lastIter);
	//}


	for (femaleIter = this->listFemaleNames.begin(); femaleIter != this->listFemaleNames.end(); femaleIter++)
	{
		int randomNameIndex = rand() % this->listLastNames.size();
		int randomAge = rand() % 100 + 1;
		float randomHealth = rand() % 100 + 1;
		sPoint point;
		point.x = rand() % LENGTH;
		point.y = rand() % LENGTH;
		point.z = rand() % LENGTH;
		int count = 0;
		for (allIter = this->listLastNames.begin(); allIter != this->listLastNames.end(); allIter++, count++)
		{
			if (randomNameIndex == count)
			{
				femaleIter->last = allIter->first;
				femaleIter->uniqueID = ++ID;
				femaleIter->age = randomAge;
				femaleIter->health = randomHealth;
				femaleIter->location = point;
				break;
			}
		}
	}
	for (maleIter = this->listMaleNames.begin(); maleIter != this->listMaleNames.end(); maleIter++)
	{
		int randomNameIndex = rand() % this->listLastNames.size();
		int randomAge = rand() % 100 + 1;
		float randomHealth = rand() % 100 + 1;
		sPoint point;
		point.x = rand() % LENGTH;
		point.y = rand() % LENGTH;
		point.z = rand() % LENGTH;
		int count = 0;
		for (allIter = this->listLastNames.begin(); allIter != this->listLastNames.end(); allIter++, count++)
		{
			if (randomNameIndex == count)
			{
				maleIter->last = allIter->first;
				maleIter->uniqueID = ++ID;
				maleIter->age = randomAge;
				maleIter->health = randomHealth;
				maleIter->location = point;
				break;
			}
		}
	}
	//for (lastIter = this->listLastNames.begin(); lastIter != this->listLastNames.end(); lastIter++)
	//{
	//	int randomNameIndex = rand() % allNames.size();
	//	int randomAge = rand() % 100 + 1;
	//	float randomHealth = rand() % 100 + 1;
	//	sPoint point;
	//	point.x = rand() % LENGTH;
	//	point.y = rand() % LENGTH;
	//	point.z = rand() % LENGTH;
	//	int count = 0;
	//	for (allIter = allNames.begin(); allIter != allNames.end(); allIter++, count++)
	//	{
	//		if (randomNameIndex == count)
	//		{
	//			lastIter->last = allIter->first;
	//			lastIter->uniqueID = ++ID;
	//			lastIter->age = randomAge;
	//			lastIter->health = randomHealth;
	//			lastIter->location = point;
	//			break;
	//		}
	//	}
	//}

	allNames.clear();
	femaleIter = this->listFemaleNames.begin();
	maleIter = this->listMaleNames.begin();
	lastIter = this->listLastNames.begin();
	for (femaleIter = this->listFemaleNames.begin(); femaleIter != this->listFemaleNames.end(); femaleIter++)
	{
		allNames.push_back(*femaleIter);
	}
	for (maleIter = this->listMaleNames.begin(); maleIter != this->listMaleNames.end(); maleIter++)
	{
		allNames.push_back(*maleIter);
	}
	//for (lastIter = this->listLastNames.begin(); lastIter != this->listLastNames.end(); lastIter++)
	//{
	//	allNames.push_back(*lastIter);
	//}
	
	ID = 0;
	for (int i = 0; i != numberOfPeople; i++)
	{
		int randomFirstNameIndex = rand() % allNames.size();
		int randomLastNameIndex = rand() % allNames.size();
		int randomAge = rand() % 100 + 1;
		float randomHealth = rand() % 100 + 1;
		sPoint point;
		point.x = rand() % LENGTH;
		point.y = rand() % LENGTH;
		point.z = rand() % LENGTH;
		int count = 0;
		sPerson person;
		for (allIter = allNames.begin(); allIter != allNames.end(); allIter++, count++)
		{
			if (randomFirstNameIndex == count)
			{
				person.first = allIter->first;
				break;
			}
		}
		count = 0;
		for (allIter = allNames.begin(); allIter != allNames.end(); allIter++, count++)
		{
			if (randomLastNameIndex == count)
			{
				person.last = allIter->last;
				break;
			}
		}
		person.uniqueID = ++ID;
		person.age = randomAge;
		person.health = randomHealth;
		person.location = point;
		this->listGenerated.push_back(person);

	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}
//
bool cSTLList::FindPeopleByName(std::vector<sPerson> &vecPeople, sPerson personToMatch, int maxNumberOfPeople)
{
	clock_t t = clock();
	std::list<sPerson>::iterator listIter;

	int numberOfPeople = 0;
	for (listIter = this->listGenerated.begin(); listIter != this->listGenerated.end(); listIter++)
	{
		if (personToMatch.first == "" && personToMatch.last == "")
		{
			vecPeople.push_back(*listIter);
			numberOfPeople++;
			if (numberOfPeople == maxNumberOfPeople)
				break;
		}
		if (personToMatch.first == "" && personToMatch.last != "")
		{
			if (listIter->last == personToMatch.last)
			{
				vecPeople.push_back(*listIter);
				numberOfPeople++;
				if (numberOfPeople == maxNumberOfPeople)
					break;
			}
		}
		if (personToMatch.last == "" && personToMatch.first != "")
		{
			if (listIter->first == personToMatch.first)
			{
				vecPeople.push_back(*listIter);
				numberOfPeople++;
				if (numberOfPeople == maxNumberOfPeople)
					break;
			}
		}
		if (personToMatch.last != "" && personToMatch.first != "")
		{
			if (listIter->first == personToMatch.first && listIter->last == personToMatch.last)
			{
				vecPeople.push_back(*listIter);
				numberOfPeople++;
				if (numberOfPeople == maxNumberOfPeople)
					break;
			}

		}
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}
bool cSTLList::FindPeopleByName(std::vector<sPerson> &vecPeople, std::vector<sPerson> &vecPeopleToMatch, int maxNumberOfPeople)
{
	clock_t t = clock();
	bool once = false;
	std::list<sPerson>::iterator listIter;
	
	std::list<sPerson> findPeople;
	for (int i = 0; i != vecPeopleToMatch.size(); i++)
		findPeople.push_back(vecPeopleToMatch[i]);
	std::list<sPerson>::iterator findIter;


	int numberOfPeople = 0;
	for (listIter = this->listGenerated.begin(); listIter != this->listGenerated.end(); listIter++)
	{
		for (findIter = findPeople.begin(); findIter != findPeople.end(); findIter++)
		{
			if (findIter->first == "" && findIter->last == "" && !once)
			{
				vecPeople.push_back(*listIter);
				numberOfPeople++;
				if (numberOfPeople == maxNumberOfPeople)
					break;
				once = true;
			}
			if (findIter->first == "" && findIter->last != "")
			{
				if (listIter->last == findIter->last)
				{
					vecPeople.push_back(*listIter);
					numberOfPeople++;
					if (numberOfPeople == maxNumberOfPeople)
						break;
				}
			}
			if (findIter->last == "" && findIter->first != "")
			{
				if (listIter->first == findIter->first)
				{
					vecPeople.push_back(*listIter);
					numberOfPeople++;
					if (numberOfPeople == maxNumberOfPeople)
						break;
				}
			}
			if (findIter->last != "" && findIter->first != "")
			{
				if (listIter->first == findIter->first && listIter->last == findIter->last)
				{
					vecPeople.push_back(*listIter);
					numberOfPeople++;
					if (numberOfPeople == maxNumberOfPeople)
						break;
				}

			}
		}
		if (numberOfPeople == maxNumberOfPeople)
			break;
		once = false;
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}
bool cSTLList::FindPersonByID(sPerson &person, unsigned long long uniqueID)
{
	clock_t t = clock();
	for (std::list<sPerson>::iterator iter = this->listGenerated.begin(); iter != this->listGenerated.end(); iter++)
	{
		if (uniqueID == iter->uniqueID)
		{
			person = *iter;
			return true;
		}
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}
bool cSTLList::FindPeople(std::vector<sPerson> &vecPeople, sPoint location, float radius,
	int maxPeopleToReturn)
{
	clock_t t = clock();
	int count = 0;
	for (std::list<sPerson>::iterator iter = this->listGenerated.begin(); iter != this->listGenerated.end(); iter++)
	{
		float distance, distx, disty, distz;
		distx = iter->location.x - location.x;
		disty = iter->location.y - location.y;
		distz = iter->location.z - location.z;
		distance = sqrt(distx*distx + disty * disty + distz * distz);
		if (distance <= radius)
		{
			count++;
			vecPeople.push_back(*iter);
		}
		if (count == maxPeopleToReturn)
			break;
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}
bool cSTLList::FindPeople(std::vector<sPerson> &vecPeople, float minHealth, float maxHealth,
	int maxPeopleToReturn)
{
	clock_t t = clock();
	int count = 0;
	for (std::list<sPerson>::iterator iter = this->listGenerated.begin(); iter != this->listGenerated.end(); iter++)
	{
		if (iter->health >= minHealth && iter->health <= maxHealth)
		{
			count++;
			vecPeople.push_back(*iter);
		}
		if (count == maxPeopleToReturn)
			break;
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}
bool cSTLList::FindPeople(std::vector<sPerson> &vecPeople,
	sPoint location, float radius, float minHealth, float maxHealth,
	int maxPeopleToReturn)
{
	clock_t t = clock();
	int count = 0;
	for (std::list<sPerson>::iterator iter = this->listGenerated.begin(); iter != this->listGenerated.end(); iter++)
	{
		float distance, distx, disty, distz;
		distx = iter->location.x - location.x;
		disty = iter->location.y - location.y;
		distz = iter->location.z - location.z;
		distance = sqrt(distx*distx + disty * disty + distz * distz);
		if (distance <= radius && iter->health >= minHealth && iter->health <= maxHealth)
		{
			count++;
			vecPeople.push_back(*iter);
		}
		if (count == maxPeopleToReturn)
			break;
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}

eContainerType cSTLList::getContainerType(void)
{
	return this->containerType;
}

bool cSTLList::SortPeople(std::vector<sPerson> &vecPeople, eSortType sortType)
{
	clock_t t = clock();
	switch (sortType)
	{
	case iPersonMotron::ASC_FIRST_THEN_LAST:
	{

		this->listGenerated.sort([](sPerson &a, sPerson &b) {
			int compare = _stricmp(a.first.c_str(), b.first.c_str());
			if (compare == 0)
				compare = _stricmp(a.last.c_str(), b.last.c_str());
			return compare < 0; });
		t = clock() - t;
		double timeTaken = ((double)t) / CLOCKS_PER_SEC;
		this->perfData.elapsedCallTime_ms = timeTaken;
		break;
	}
	case iPersonMotron::DESC_FIRST_THEN_LAST:
	{

		this->listGenerated.sort([](sPerson &a, sPerson &b) {
			int compare = _stricmp(a.first.c_str(), b.first.c_str());
			if (compare == 0)
				compare = _stricmp(a.last.c_str(), b.last.c_str());
			return compare > 0; });
		t = clock() - t;
		double timeTaken = ((double)t) / CLOCKS_PER_SEC;
		this->perfData.elapsedCallTime_ms = timeTaken;
		break;
	}
	case iPersonMotron::ASC_LAST_THEN_FIRST:
	{

		this->listGenerated.sort([](sPerson &a, sPerson &b) {
			int compare = _stricmp(a.last.c_str(), b.last.c_str());
			if (compare == 0)
				compare = _stricmp(a.first.c_str(), b.first.c_str());
			return compare < 0; });
		t = clock() - t;
		double timeTaken = ((double)t) / CLOCKS_PER_SEC;
		this->perfData.elapsedCallTime_ms = timeTaken;
		break;
	}
	case iPersonMotron::DESC_LAST_THEN_FIRST:
	{

		this->listGenerated.sort([](sPerson &a, sPerson &b) {
			int compare = _stricmp(a.last.c_str(), b.last.c_str());
			if (compare == 0)
				compare = _stricmp(a.first.c_str(), b.first.c_str());
			return compare > 0; });
		t = clock() - t;
		double timeTaken = ((double)t) / CLOCKS_PER_SEC;
		this->perfData.elapsedCallTime_ms = timeTaken;
		break;
	}
	case iPersonMotron::ASC_BY_ID:
	{

		this->listGenerated.sort([](sPerson &a, sPerson &b) {
			return a.uniqueID < b.uniqueID; });
		break;
	}
	case iPersonMotron::DESC_BY_ID:
	{

		this->listGenerated.sort([](sPerson &a, sPerson &b) {
			return a.uniqueID > b.uniqueID; });
		t = clock() - t;
		double timeTaken = ((double)t) / CLOCKS_PER_SEC;
		this->perfData.elapsedCallTime_ms = timeTaken;
		break;
	}
	case iPersonMotron::ASC_BY_HEALTH:
	{

		this->listGenerated.sort([](sPerson &a, sPerson &b) {
			return a.health < b.health; });
		break;
	}
	case iPersonMotron::DESC_BY_HEALTH:
	{

		this->listGenerated.sort([](sPerson &a, sPerson &b) {
			return a.health > b.health; });
		t = clock() - t;
		double timeTaken = ((double)t) / CLOCKS_PER_SEC;
		this->perfData.elapsedCallTime_ms = timeTaken;
		break;
	}
	default:
		break;
	}
	for (std::list<sPerson>::iterator iter = this->listGenerated.begin(); iter != this->listGenerated.end(); iter++)
		vecPeople.push_back(*iter);
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return false;
}
bool cSTLList::GetPerformanceFromLastCall(sPerfData &callStats)
{
	callStats = this->perfData;
	return true;
}