#include "cSTLMap.h"
#include <algorithm>
#include <stdlib.h>
#include <iostream>

// FIND PEOPLE BY NAME RETURN
// GENERATE PEOPLE RANDOMLY
// HEALTH AND POINT STUFF

#define LENGTH 200

struct ASC_FIRST_THEN_LAST_COMPARATOR
{
	bool operator()(const sPerson &a, const sPerson &b) const
	{
		int compare = _stricmp(a.first.c_str(), b.first.c_str());
		if (compare == 0)
			compare = _stricmp(a.last.c_str(), b.last.c_str());
		return compare < 0;
	}
};
struct DESC_FIRST_THEN_LAST_COMPARATOR
{
	bool operator()(const sPerson &a, const sPerson &b) const
	{
		int compare = _stricmp(a.first.c_str(), b.first.c_str());
		if (compare == 0)
			compare = _stricmp(a.last.c_str(), b.last.c_str());
		return compare > 0;
	}
};
struct ASC_LAST_THEN_FIRST_COMPARATOR
{
	bool operator()(const sPerson &a, const sPerson &b) const
	{
		int compare = _stricmp(a.last.c_str(), b.last.c_str());
		if (compare == 0)
			compare = _stricmp(a.first.c_str(), b.first.c_str());
		return compare < 0;
	}
};
struct DESC_LAST_THEN_FIRST_COMPARATOR
{
	bool operator()(const sPerson &a, const sPerson &b) const
	{
		int compare = _stricmp(a.last.c_str(), b.last.c_str());
		if (compare == 0)
			compare = _stricmp(a.first.c_str(), b.first.c_str());
		return compare > 0;
	}
};
struct ASC_BY_ID_COMPARATOR
{
	bool operator()(const sPerson &a, const sPerson &b) const
	{
		return a.uniqueID < b.uniqueID;
	}
};
struct DESC_BY_ID_COMPARATOR
{
	bool operator()(const sPerson &a, const sPerson &b) const
	{
		return a.uniqueID > b.uniqueID;
	}
};
struct ASC_BY_HEALTH_COMPARATOR
{
	bool operator()(const sPerson &a, const sPerson &b) const
	{
		return a.health < b.health;
	}
};
struct DESC_BY_HEALTH_COMPARATOR
{
	bool operator()(const sPerson &a, const sPerson &b) const
	{
		return a.health > b.health;
	}
};



bool loadDataIntoVector(std::string femaleNamesFileName, std::vector<std::string> &vecFirstFemale,
	std::string maleNamesFileName, std::vector<std::string> &vecFirstMale,
	std::string lastNamesFileName, std::vector<std::string> &vecLast,
	std::string &error);

// Uses c interface, rather than C++ one (so WAY faster)
bool loadDataIntoVector2(std::string femaleNamesFileName, std::vector<sPerson> &vecFirstFemale,
	std::string maleNamesFileName, std::vector<sPerson> &vecFirstMale,
	std::string lastNamesFileName, std::vector<sPerson> &vecLast,
	std::string &error);




bool cSTLMap::LoadDataFilesIntoContainer(std::string firstNameFemaleFileName,
	std::string firstNameMaleFileName,
	std::string lastNameFileName)

{
	clock_t t = clock();
	std::vector<sPerson> vecFemaleNames;
	std::vector<sPerson> vecMaleNames;
	std::vector<sPerson> vecLastNames;

	if (!loadDataIntoVector2(firstNameFemaleFileName, vecFemaleNames,
		firstNameMaleFileName, vecMaleNames,
		lastNameFileName, vecLastNames, error))
	{
		return false;
	}

	for (int i = 0; i != vecFemaleNames.size(); i++)
	{
		this->mapFemaleNames[i] = vecFemaleNames[i];
	}
	for (int i = 0; i != vecMaleNames.size(); i++)
	{
		this->mapMaleNames[i] = vecMaleNames[i];
	}
	for (int i = 0; i != vecLastNames.size(); i++)
	{
		this->mapLastNames[i] = vecLastNames[i];
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}

bool cSTLMap::GenerateRandomPeople(int numberOfPeople)
{
	clock_t t = clock();
	std::map<int, sPerson> allVecs;
	int ID = 0;
	int index = 0;
	for (int i = 0; i != this->mapFemaleNames.size(); i++, index++)
		allVecs[index] = this->mapFemaleNames[i];
	for (int i = 0; i != this->mapMaleNames.size(); i++, index++)
		allVecs[index] = this->mapMaleNames[i];

	for (int i = 0; i != this->mapFemaleNames.size(); i++)
	{
		int randomNameIndex = rand() % this->mapLastNames.size();
		int randomAge = rand() % 100 + 1;
		float randomHealth = rand() % 100 + 1;
		sPoint point;
		point.x = rand() % LENGTH;
		point.y = rand() % LENGTH;
		point.z = rand() % LENGTH;
		this->mapFemaleNames[i].last = this->mapLastNames[randomNameIndex].first;
		this->mapFemaleNames[i].uniqueID = ++ID;
		this->mapFemaleNames[i].age = randomAge;
		this->mapFemaleNames[i].health = randomHealth;
		this->mapFemaleNames[i].location = point;
	}
	for (int i = 0; i != this->mapMaleNames.size(); i++)
	{
		int randomNameIndex = rand() % this->mapLastNames.size();
		int randomAge = rand() % 100 + 1;
		float randomHealth = rand() % 100 + 1;
		sPoint point;
		point.x = rand() % LENGTH;
		point.y = rand() % LENGTH;
		point.z = rand() % LENGTH;
		this->mapMaleNames[i].last = this->mapLastNames[randomNameIndex].first;
		this->mapMaleNames[i].uniqueID = ++ID;
		this->mapMaleNames[i].age = randomAge;
		this->mapMaleNames[i].health = randomHealth;
		this->mapMaleNames[i].location = point;
	}

	allVecs.clear();
	index = 0;
	for (int i = 0; i != this->mapFemaleNames.size(); i++, index++)
		allVecs[index] = this->mapFemaleNames[i];
	for (int i = 0; i != this->mapMaleNames.size(); i++, index++)
		allVecs[index] = this->mapMaleNames[i];


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
		this->mapGenerated[i] = person;
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}
//
bool cSTLMap::FindPeopleByName(std::vector<sPerson> &vecPeople, sPerson personToMatch, int maxNumberOfPeople)
{
	clock_t t = clock();
	int numberOfPeople = 0;
	for (std::map<int, sPerson>::iterator iter = this->mapGenerated.begin(); iter != this->mapGenerated.end(); iter++)
	{
		if (personToMatch.first == "" && personToMatch.last == "")
		{
			vecPeople.push_back(iter->second);
			numberOfPeople++;
			if (numberOfPeople == maxNumberOfPeople)
				break;
		}
		if (personToMatch.first == "" && personToMatch.last != "")
		{
			if (iter->second.last == personToMatch.last)
			{
				vecPeople.push_back(iter->second);
				numberOfPeople++;
				if (numberOfPeople == maxNumberOfPeople)
					break;
			}
		}
		if (personToMatch.last == "" && personToMatch.first != "")
		{
			if (iter->second.first == personToMatch.first)
			{
				vecPeople.push_back(iter->second);
				numberOfPeople++;
				if (numberOfPeople == maxNumberOfPeople)
					break;
			}
		}
		if (personToMatch.last != "" && personToMatch.first != "")
		{
			if (iter->second.first == personToMatch.first && iter->second.last == personToMatch.last)
			{
				vecPeople.push_back(iter->second);
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
bool cSTLMap::FindPeopleByName(std::vector<sPerson> &vecPeople, std::vector<sPerson> &vecPeopleToMatch, int maxNumberOfPeople)
{
	clock_t t = clock();
	int numberOfPeople = 0;
	bool once = false;
	for (std::map<int, sPerson>::iterator iter = this->mapGenerated.begin(); iter != this->mapGenerated.end(); iter++)
	{
		for (int j = 0; j != vecPeopleToMatch.size(); j++)
		{
			if (vecPeopleToMatch[j].first == "" && vecPeopleToMatch[j].last == "" && !once)
			{
				vecPeople.push_back(iter->second);
				numberOfPeople++;
				if (numberOfPeople == maxNumberOfPeople)
					break;
				once = true;
			}
			if (vecPeopleToMatch[j].first == "" && vecPeopleToMatch[j].last != "")
			{
				if (iter->second.last == vecPeopleToMatch[j].last)
				{
					vecPeople.push_back(iter->second);
					numberOfPeople++;
					if (numberOfPeople == maxNumberOfPeople)
						break;
				}
			}
			if (vecPeopleToMatch[j].last == "" && vecPeopleToMatch[j].first != "")
			{
				if (iter->second.first == vecPeopleToMatch[j].first)
				{
					vecPeople.push_back(iter->second);
					numberOfPeople++;
					if (numberOfPeople == maxNumberOfPeople)
						break;
				}
			}
			if (vecPeopleToMatch[j].last != "" && vecPeopleToMatch[j].first != "")
			{
				if (iter->second.first == vecPeopleToMatch[j].first && iter->second.last == vecPeopleToMatch[j].last)
				{
					vecPeople.push_back(iter->second);
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
bool cSTLMap::FindPersonByID(sPerson &person, unsigned long long uniqueID)
{
	clock_t t = clock();
	for (std::map<int, sPerson>::iterator iter = this->mapGenerated.begin(); iter != this->mapGenerated.end(); iter++)
	{
		if (uniqueID == iter->second.uniqueID)
		{
			person = iter->second;
			return true;
		}
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return false;
}
bool cSTLMap::FindPeople(std::vector<sPerson> &vecPeople, sPoint location, float radius,
	int maxPeopleToReturn)
{
	clock_t t = clock();
	int count = 0;
	for (std::map<int, sPerson>::iterator iter = this->mapGenerated.begin(); iter != this->mapGenerated.end(); iter++)
	{
		float distance, distx, disty, distz;
		distx = iter->second.location.x - location.x;
		disty = iter->second.location.y - location.y;
		distz = iter->second.location.z - location.z;
		distance = sqrt(distx*distx + disty * disty + distz * distz);
		if (distance <= radius)
		{
			count++;
			vecPeople.push_back(iter->second);
		}
		if (count == maxPeopleToReturn)
			break;
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return false;
}
bool cSTLMap::FindPeople(std::vector<sPerson> &vecPeople, float minHealth, float maxHealth,
	int maxPeopleToReturn)
{
	clock_t t = clock();
	int count = 0;
	for (std::map<int, sPerson>::iterator iter = this->mapGenerated.begin(); iter != this->mapGenerated.end(); iter++)
	{
		if (iter->second.health >= minHealth && iter->second.health <= maxHealth)
		{
			count++;
			vecPeople.push_back(iter->second);
		}
		if (count == maxPeopleToReturn)
			break;
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return false;
}
bool cSTLMap::FindPeople(std::vector<sPerson> &vecPeople,
	sPoint location, float radius, float minHealth, float maxHealth,
	int maxPeopleToReturn)
{
	clock_t t = clock();
	int count = 0;
	for (std::map<int, sPerson>::iterator iter = this->mapGenerated.begin(); iter != this->mapGenerated.end(); iter++)
	{
		float distance, distx, disty, distz;
		distx = iter->second.location.x - location.x;
		disty = iter->second.location.y - location.y;
		distz = iter->second.location.z - location.z;
		distance = sqrt(distx*distx + disty * disty + distz * distz);
		if (distance <= radius && iter->second.health >= minHealth && iter->second.health <= maxHealth)
		{
			count++;
			vecPeople.push_back(iter->second);
		}
		if (count == maxPeopleToReturn)
			break;
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}


eContainerType cSTLMap::getContainerType(void)
{
	return this->containerType;
}

bool cSTLMap::SortPeople(std::vector<sPerson> &vecPeople, eSortType sortType)
{
	clock_t t = clock();
	switch (sortType)
	{
	case iPersonMotron::ASC_FIRST_THEN_LAST:
	{
		std::map<sPerson, int, ASC_FIRST_THEN_LAST_COMPARATOR> personToId;
		for (int i = 0; i < this->mapGenerated.size(); i++)
			personToId[this->mapGenerated[i]] = i;
		for (std::map<sPerson, int>::iterator iter = personToId.begin(); iter != personToId.end(); iter++)
			vecPeople.push_back(iter->first);
		t = clock() - t;
		double timeTaken = ((double)t) / CLOCKS_PER_SEC;
		this->perfData.elapsedCallTime_ms = timeTaken;
		break;
	}
	case iPersonMotron::DESC_FIRST_THEN_LAST:
	{
		std::map<sPerson, int, DESC_FIRST_THEN_LAST_COMPARATOR> personToId;
		for (int i = 0; i < this->mapGenerated.size(); i++)
			personToId[this->mapGenerated[i]] = i;
		for (std::map<sPerson, int>::iterator iter = personToId.begin(); iter != personToId.end(); iter++)
			vecPeople.push_back(iter->first);
		t = clock() - t;
		double timeTaken = ((double)t) / CLOCKS_PER_SEC;
		this->perfData.elapsedCallTime_ms = timeTaken;
		break;
	}
	case iPersonMotron::ASC_LAST_THEN_FIRST:
	{
		std::map<sPerson, int, ASC_LAST_THEN_FIRST_COMPARATOR> personToId;
		for (int i = 0; i < this->mapGenerated.size(); i++)
			personToId[this->mapGenerated[i]] = i;
		for (std::map<sPerson, int>::iterator iter = personToId.begin(); iter != personToId.end(); iter++)
			vecPeople.push_back(iter->first);
		t = clock() - t;
		double timeTaken = ((double)t) / CLOCKS_PER_SEC;
		this->perfData.elapsedCallTime_ms = timeTaken;
		break;
	}
	case iPersonMotron::DESC_LAST_THEN_FIRST:
	{
		std::map<sPerson, int, DESC_LAST_THEN_FIRST_COMPARATOR> personToId;
		for (int i = 0; i < this->mapGenerated.size(); i++)
			personToId[this->mapGenerated[i]] = i;
		for (std::map<sPerson, int>::iterator iter = personToId.begin(); iter != personToId.end(); iter++)
			vecPeople.push_back(iter->first);
		t = clock() - t;
		double timeTaken = ((double)t) / CLOCKS_PER_SEC;
		this->perfData.elapsedCallTime_ms = timeTaken;
		break;
	}
	case iPersonMotron::ASC_BY_ID:
	{
		std::map<sPerson, int, ASC_BY_ID_COMPARATOR> personToId;
		for (int i = 0; i < this->mapGenerated.size(); i++)
			personToId[this->mapGenerated[i]] = i;
		for (std::map<sPerson, int>::iterator iter = personToId.begin(); iter != personToId.end(); iter++)
			vecPeople.push_back(iter->first);
		t = clock() - t;
		double timeTaken = ((double)t) / CLOCKS_PER_SEC;
		this->perfData.elapsedCallTime_ms = timeTaken;
		break;
	}
	case iPersonMotron::DESC_BY_ID:
	{
		std::map<sPerson, int, DESC_BY_ID_COMPARATOR> personToId;
		for (int i = 0; i < this->mapGenerated.size(); i++)
			personToId[this->mapGenerated[i]] = i;
		for (std::map<sPerson, int>::iterator iter = personToId.begin(); iter != personToId.end(); iter++)
			vecPeople.push_back(iter->first);
		t = clock() - t;
		double timeTaken = ((double)t) / CLOCKS_PER_SEC;
		this->perfData.elapsedCallTime_ms = timeTaken;
		break;
	}
	case iPersonMotron::ASC_BY_HEALTH:
	{
		std::map<sPerson, int, ASC_BY_HEALTH_COMPARATOR> personToId;
		for (int i = 0; i < this->mapGenerated.size(); i++)
			personToId[this->mapGenerated[i]] = i;
		for (std::map<sPerson, int>::iterator iter = personToId.begin(); iter != personToId.end(); iter++)
			vecPeople.push_back(iter->first);
		t = clock() - t;
		double timeTaken = ((double)t) / CLOCKS_PER_SEC;
		this->perfData.elapsedCallTime_ms = timeTaken;
		break;
	}
	case iPersonMotron::DESC_BY_HEALTH:
	{
		std::map<sPerson, int, DESC_BY_HEALTH_COMPARATOR> personToId;
		for (int i = 0; i < this->mapGenerated.size(); i++)
			personToId[this->mapGenerated[i]] = i;
		for (std::map<sPerson, int>::iterator iter = personToId.begin(); iter != personToId.end(); iter++)
			vecPeople.push_back(iter->first);
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
bool cSTLMap::GetPerformanceFromLastCall(sPerfData &callStats)
{
	callStats = this->perfData;
	return true;
}