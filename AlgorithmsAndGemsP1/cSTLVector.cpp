#include "cSTLVector.h"
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




bool cSTLVector::LoadDataFilesIntoContainer(std::string firstNameFemaleFileName,
											std::string firstNameMaleFileName,
											std::string lastNameFileName)
{
	clock_t t = clock();
	if (!loadDataIntoVector2(firstNameFemaleFileName, this->vecFemaleNames,
		firstNameMaleFileName, this->vecMaleNames,
		lastNameFileName, this->vecLastNames, error))
	{
		return false;
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}						 
bool cSTLVector::GenerateRandomPeople(int numberOfPeople) 
{
	clock_t t = clock();

	std::vector<sPerson> allVecs;
	int ID = 0;
	for (int i = 0; i != this->vecFemaleNames.size(); i++)
		allVecs.push_back(this->vecFemaleNames[i]);
	for (int i = 0; i != this->vecMaleNames.size(); i++)
		allVecs.push_back(this->vecMaleNames[i]);/*
	for (int i = 0; i != this->vecLastNames.size(); i++)
		allVecs.push_back(this->vecLastNames[i]);*/

	for (int i = 0; i != this->vecFemaleNames.size(); i++)
	{
		int randomNameIndex = rand() % this->vecLastNames.size();
		int randomAge = rand() % 100 + 1;
		float randomHealth = rand() % 100 + 1;
		sPoint point;
		point.x = rand() % LENGTH;
		point.y = rand() % LENGTH;
		point.z = rand() % LENGTH;
		this->vecFemaleNames[i].last = this->vecLastNames[randomNameIndex].first;
		this->vecFemaleNames[i].uniqueID = ++ID;
		this->vecFemaleNames[i].age = randomAge;
		this->vecFemaleNames[i].health = randomHealth;
		this->vecFemaleNames[i].location = point;
	}
	for (int i = 0; i != this->vecMaleNames.size(); i++)
	{
		int randomNameIndex = rand() % this->vecLastNames.size();
		int randomAge = rand() % 100 + 1;
		float randomHealth = rand() % 100 + 1;
		sPoint point;
		point.x = rand() % LENGTH;
		point.y = rand() % LENGTH;
		point.z = rand() % LENGTH;
		this->vecMaleNames[i].last = this->vecLastNames[randomNameIndex].first;
		this->vecMaleNames[i].uniqueID = ++ID;
		this->vecMaleNames[i].age = randomAge;
		this->vecMaleNames[i].health = randomHealth;
		this->vecMaleNames[i].location = point;
	}
	//for (int i = 0; i != this->vecLastNames.size(); i++)
	//{
	//	int randomNameIndex = rand() % this->vecLastNames.size();
	//	int randomAge = rand() % 100 + 1;
	//	float randomHealth = rand() % 100 + 1;
	//	sPoint point;
	//	point.x = rand() % LENGTH;
	//	point.y = rand() % LENGTH;
	//	point.z = rand() % LENGTH;
	//	this->vecLastNames[i].last = this->vecLastNames[randomNameIndex].first;
	//	this->vecLastNames[i].uniqueID = ++ID;
	//	this->vecLastNames[i].age = randomAge;
	//	this->vecLastNames[i].health = randomHealth;
	//	this->vecLastNames[i].location = point;
	//}
	allVecs.clear();
	for (int i = 0; i != this->vecFemaleNames.size(); i++)
		allVecs.push_back(this->vecFemaleNames[i]);
	for (int i = 0; i != this->vecMaleNames.size(); i++)
		allVecs.push_back(this->vecMaleNames[i]);
	//for (int i = 0; i != this->vecLastNames.size(); i++)
	//	allVecs.push_back(this->vecLastNames[i]);

	ID = 0;
	for (int i = 0; i != numberOfPeople; i++)
	{
		int randomFirstNameIndex = rand() % allVecs.size();
		int randomLastNameIndex = rand() % allVecs.size();
		int randomAge = rand() % 100 + 1;
		float randomHealth = rand() % 100 + 1;
		sPoint point;
		point.x = rand() % LENGTH;
		point.y = rand() % LENGTH;
		point.z = rand() % LENGTH;
		sPerson person;
		person.first = allVecs[randomFirstNameIndex].first;
		person.last = allVecs[randomLastNameIndex].last;
		person.uniqueID = ++ID;
		person.age = randomAge;
		person.health = randomHealth;
		person.location = point;
		this->vecGenerated.push_back(person);
	}

	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}
//
bool cSTLVector::FindPeopleByName(std::vector<sPerson> &vecPeople, sPerson personToMatch, int maxNumberOfPeople)
{
	clock_t t = clock();
	int numberOfPeople = 0;
	for (int i = 0; i != this->vecGenerated.size(); i++)
	{
		if (personToMatch.first == "" && personToMatch.last == "")
		{
			vecPeople.push_back(this->vecGenerated[i]);
			numberOfPeople++;
			if (numberOfPeople == maxNumberOfPeople)
				break;
		}
		if (personToMatch.first == "" && personToMatch.last != "")
		{
			if (this->vecGenerated[i].last == personToMatch.last)
			{
				vecPeople.push_back(this->vecGenerated[i]);
				numberOfPeople++;
				if (numberOfPeople == maxNumberOfPeople)
					break;
			}
		}
		if (personToMatch.last == "" && personToMatch.first != "")
		{
			if (this->vecGenerated[i].first == personToMatch.first)
			{
				vecPeople.push_back(this->vecGenerated[i]);
				numberOfPeople++;
				if (numberOfPeople == maxNumberOfPeople)
					break;
			}
		}
		if (personToMatch.last != "" && personToMatch.first != "")
		{
			if (this->vecGenerated[i].first == personToMatch.first && this->vecGenerated[i].last == personToMatch.last)
			{
				vecPeople.push_back(this->vecGenerated[i]);
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
bool cSTLVector::FindPeopleByName(std::vector<sPerson> &vecPeople, std::vector<sPerson> &vecPeopleToMatch, int maxNumberOfPeople)
{
	clock_t t = clock();
	int numberOfPeople = 0;
	bool once = false;
	for (int i = 0; i != this->vecGenerated.size(); i++)
	{
		for (int j = 0; j != vecPeopleToMatch.size(); j++)
		{
			if (vecPeopleToMatch[j].first == "" && vecPeopleToMatch[j].last == "" && !once)
			{
				vecPeople.push_back(this->vecGenerated[i]);
				numberOfPeople++;
				if (numberOfPeople == maxNumberOfPeople)
					break;
				once = true;
			}
			if (vecPeopleToMatch[j].first == "" && vecPeopleToMatch[j].last != "")
			{
				if (this->vecGenerated[i].last == vecPeopleToMatch[j].last)
				{
					vecPeople.push_back(this->vecGenerated[i]);
					numberOfPeople++;
					if (numberOfPeople == maxNumberOfPeople)
						break;
				}
			}
			if (vecPeopleToMatch[j].last == "" && vecPeopleToMatch[j].first != "")
			{
				if (this->vecGenerated[i].first == vecPeopleToMatch[j].first)
				{
					vecPeople.push_back(this->vecGenerated[i]);
					numberOfPeople++;
					if (numberOfPeople == maxNumberOfPeople)
						break;
				}
			}
			if (vecPeopleToMatch[j].last != "" && vecPeopleToMatch[j].first != "")
			{
				if (this->vecGenerated[i].first == vecPeopleToMatch[j].first && this->vecGenerated[i].last == vecPeopleToMatch[j].last)
				{
					vecPeople.push_back(this->vecGenerated[i]);
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
bool cSTLVector::FindPersonByID(sPerson &person, unsigned long long uniqueID)
{
	clock_t t = clock();
	for (std::vector<sPerson>::iterator iter = this->vecGenerated.begin(); iter != this->vecGenerated.end(); iter++)
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
	return false;
}
bool cSTLVector::FindPeople(std::vector<sPerson> &vecPeople, sPoint location, float radius, int maxPeopleToReturn)
{
	clock_t t = clock();
	int count = 0;
	for (std::vector<sPerson>::iterator iter = this->vecGenerated.begin(); iter != this->vecGenerated.end(); iter++)
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
bool cSTLVector::FindPeople(std::vector<sPerson> &vecPeople, float minHealth, float maxHealth,
	int maxPeopleToReturn)
{
	clock_t t = clock();
	int count = 0;
	for (int i = 0; i != this->vecGenerated.size(); i++)
	{
		if (this->vecGenerated[i].health >= minHealth && this->vecGenerated[i].health <= maxHealth)
		{
			count++;
			vecPeople.push_back(this->vecGenerated[i]);
		}
		if (count == maxPeopleToReturn)
			break;
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}
bool cSTLVector::FindPeople(std::vector<sPerson> &vecPeople,
	sPoint location, float radius, float minHealth, float maxHealth,
	int maxPeopleToReturn)
{
	clock_t t = clock();
	int count = 0;
	for (std::vector<sPerson>::iterator iter = this->vecGenerated.begin(); iter != this->vecGenerated.end(); iter++)
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

eContainerType cSTLVector::getContainerType(void)
{
	return this->containerType;
}

bool cSTLVector::SortPeople(std::vector<sPerson> &vecPeople, eSortType sortType)
{
	clock_t t = clock();
	for (int i = 0; i < this->vecGenerated.size(); i++)
		vecPeople.push_back(this->vecGenerated[i]);
	switch (sortType)
	{
	case iPersonMotron::ASC_FIRST_THEN_LAST:
	{

		std::sort(vecPeople.begin(), vecPeople.end(), [](sPerson &a, sPerson &b) {
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

		std::sort(vecPeople.begin(), vecPeople.end(), [](sPerson &a, sPerson &b) {
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

		std::sort(vecPeople.begin(), vecPeople.end(), [](sPerson &a, sPerson &b) {
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

		std::sort(vecPeople.begin(), vecPeople.end(), [](sPerson &a, sPerson &b) {
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

		std::sort(vecPeople.begin(), vecPeople.end(), [](sPerson &a, sPerson &b) {
			return a.uniqueID < b.uniqueID; });
		t = clock() - t;
		double timeTaken = ((double)t) / CLOCKS_PER_SEC;
		this->perfData.elapsedCallTime_ms = timeTaken;
		break;
	}
	case iPersonMotron::DESC_BY_ID:
	{

		std::sort(vecPeople.begin(), vecPeople.end(), [](sPerson &a, sPerson &b) {
			return a.uniqueID > b.uniqueID; });
		t = clock() - t;
		double timeTaken = ((double)t) / CLOCKS_PER_SEC;
		this->perfData.elapsedCallTime_ms = timeTaken;
		break;
	}
	case iPersonMotron::ASC_BY_HEALTH:
	{
		std::sort(vecPeople.begin(), vecPeople.end(), [](sPerson &a, sPerson &b) {

			return a.health < b.health; });
		t = clock() - t;
		double timeTaken = ((double)t) / CLOCKS_PER_SEC;
		this->perfData.elapsedCallTime_ms = timeTaken;
		break;
	}
	case iPersonMotron::DESC_BY_HEALTH:
	{

		std::sort(vecPeople.begin(), vecPeople.end(), [](sPerson &a, sPerson &b) {
			return a.health > b.health; });
		t = clock() - t;
		double timeTaken = ((double)t) / CLOCKS_PER_SEC;
		this->perfData.elapsedCallTime_ms = timeTaken;
		break;
	}
	default:
		break;
	}
	return false;
}
bool cSTLVector::GetPerformanceFromLastCall(sPerfData &callStats)
{
	callStats = this->perfData;
	return true;
}