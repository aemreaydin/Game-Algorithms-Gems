#include "cDIYList.h"
#include <algorithm>

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


void cDIYList::bubbleSort(eSortType sortType)
{
	switch (sortType)
	{
	case iPersonMotron::ASC_FIRST_THEN_LAST:
	{
		bool swapped = true;
		int j = 0;
		sPerson temp;
		while (swapped)
		{
			this->listGenerated.MoveStart();
			swapped = false;
			j++;
			for (int i = 0; i < this->listGenerated.size() - j; i++)
			{
				sPerson person = this->listGenerated.GetCurrentNode();
				this->listGenerated.MoveNext();
				sPerson personNext = this->listGenerated.GetCurrentNode();
				if (person.first > personNext.first)
				{
					temp = person;
					person = personNext;
					this->listGenerated.MovePrev();
					this->listGenerated.SetCurrentNode(person);
					personNext = temp;
					this->listGenerated.MoveNext();
					this->listGenerated.SetCurrentNode(personNext);
					swapped = true;
				}
			}
		}
		swapped = true;
		j = 0;
		while (swapped)
		{
			this->listGenerated.MoveStart();
			swapped = false;
			j++;
			for (int i = 0; i < this->listGenerated.size() - j; i++)
			{
				sPerson person = this->listGenerated.GetCurrentNode();
				this->listGenerated.MoveNext();
				sPerson personNext = this->listGenerated.GetCurrentNode();
				if (person.first == personNext.first && person.last > personNext.last)
				{
					temp = person;
					person = personNext;
					this->listGenerated.MovePrev();
					this->listGenerated.SetCurrentNode(person);
					personNext = temp;
					this->listGenerated.MoveNext();
					this->listGenerated.SetCurrentNode(personNext);
					swapped = true;
				}
			}
		}
		break;
	}

	case iPersonMotron::DESC_FIRST_THEN_LAST:
	{
		bool swapped = true;
		int j = 0;
		sPerson temp;
		while (swapped)
		{
			this->listGenerated.MoveStart();
			swapped = false;
			j++;
			for (int i = 0; i < this->listGenerated.size() - j; i++)
			{
				sPerson person = this->listGenerated.GetCurrentNode();
				this->listGenerated.MoveNext();
				sPerson personNext = this->listGenerated.GetCurrentNode();
				if (person.first < personNext.first)
				{
					temp = person;
					person = personNext;
					this->listGenerated.MovePrev();
					this->listGenerated.SetCurrentNode(person);
					personNext = temp;
					this->listGenerated.MoveNext();
					this->listGenerated.SetCurrentNode(personNext);
					swapped = true;
				}
			}
		}
		swapped = true;
		j = 0;
		while (swapped)
		{
			this->listGenerated.MoveStart();
			swapped = false;
			j++;
			for (int i = 0; i < this->listGenerated.size() - j; i++)
			{
				sPerson person = this->listGenerated.GetCurrentNode();
				this->listGenerated.MoveNext();
				sPerson personNext = this->listGenerated.GetCurrentNode();
				if (person.first == personNext.first && person.last < personNext.last)
				{
					temp = person;
					person = personNext;
					this->listGenerated.MovePrev();
					this->listGenerated.SetCurrentNode(person);
					personNext = temp;
					this->listGenerated.MoveNext();
					this->listGenerated.SetCurrentNode(personNext);
					swapped = true;
				}
			}
		}
		break;
	}
	case iPersonMotron::ASC_LAST_THEN_FIRST:
	{
		bool swapped = true;
		int j = 0;
		sPerson temp;
		while (swapped)
		{
			this->listGenerated.MoveStart();
			swapped = false;
			j++;
			for (int i = 0; i < this->listGenerated.size() - j; i++)
			{
				sPerson person = this->listGenerated.GetCurrentNode();
				this->listGenerated.MoveNext();
				sPerson personNext = this->listGenerated.GetCurrentNode();
				if (person.last > personNext.last)
				{
					temp = person;
					person = personNext;
					this->listGenerated.MovePrev();
					this->listGenerated.SetCurrentNode(person);
					personNext = temp;
					this->listGenerated.MoveNext();
					this->listGenerated.SetCurrentNode(personNext);
					swapped = true;
				}
			}
		}
		swapped = true;
		j = 0;
		while (swapped)
		{
			this->listGenerated.MoveStart();
			swapped = false;
			j++;
			for (int i = 0; i < this->listGenerated.size() - j; i++)
			{
				sPerson person = this->listGenerated.GetCurrentNode();
				this->listGenerated.MoveNext();
				sPerson personNext = this->listGenerated.GetCurrentNode();
				if (person.last == personNext.last && person.first > personNext.first)
				{
					temp = person;
					person = personNext;
					this->listGenerated.MovePrev();
					this->listGenerated.SetCurrentNode(person);
					personNext = temp;
					this->listGenerated.MoveNext();
					this->listGenerated.SetCurrentNode(personNext);
					swapped = true;
				}
			}
		}
		break;
	}
	case iPersonMotron::DESC_LAST_THEN_FIRST:
	{
		bool swapped = true;
		int j = 0;
		sPerson temp;
		while (swapped)
		{
			this->listGenerated.MoveStart();
			swapped = false;
			j++;
			for (int i = 0; i < this->listGenerated.size() - j; i++)
			{
				sPerson person = this->listGenerated.GetCurrentNode();
				this->listGenerated.MoveNext();
				sPerson personNext = this->listGenerated.GetCurrentNode();
				if (person.last < personNext.last)
				{
					temp = person;
					person = personNext;
					this->listGenerated.MovePrev();
					this->listGenerated.SetCurrentNode(person);
					personNext = temp;
					this->listGenerated.MoveNext();
					this->listGenerated.SetCurrentNode(personNext);
					swapped = true;
				}
			}
		}
		swapped = true;
		j = 0;
		while (swapped)
		{
			this->listGenerated.MoveStart();
			swapped = false;
			j++;
			for (int i = 0; i < this->listGenerated.size() - j; i++)
			{
				sPerson person = this->listGenerated.GetCurrentNode();
				this->listGenerated.MoveNext();
				sPerson personNext = this->listGenerated.GetCurrentNode();
				if (person.last == personNext.last && person.first < personNext.first)
				{
					temp = person;
					person = personNext;
					this->listGenerated.MovePrev();
					this->listGenerated.SetCurrentNode(person);
					personNext = temp;
					this->listGenerated.MoveNext();
					this->listGenerated.SetCurrentNode(personNext);
					swapped = true;
				}
			}
		}
		break;
	}
	case iPersonMotron::ASC_BY_ID:
	{
		bool swapped = true;
		int j = 0;
		sPerson temp;
		while (swapped)
		{
			this->listGenerated.MoveStart();
			swapped = false;
			j++;
			for (int i = 0; i < this->listGenerated.size() - j; i++)
			{
				sPerson person = this->listGenerated.GetCurrentNode();
				this->listGenerated.MoveNext();
				sPerson personNext = this->listGenerated.GetCurrentNode();
				if (person.uniqueID > personNext.uniqueID)
				{
					temp = person;
					person = personNext;
					this->listGenerated.MovePrev();
					this->listGenerated.SetCurrentNode(person);
					personNext = temp;
					this->listGenerated.MoveNext();
					this->listGenerated.SetCurrentNode(personNext);
					swapped = true;
				}
			}
		}
		break;
	}
	case iPersonMotron::DESC_BY_ID:
	{
		bool swapped = true;
		int j = 0;
		sPerson temp;
		while (swapped)
		{
			this->listGenerated.MoveStart();
			swapped = false;
			j++;
			for (int i = 0; i < this->listGenerated.size() - j; i++)
			{
				sPerson person = this->listGenerated.GetCurrentNode();
				this->listGenerated.MoveNext();
				sPerson personNext = this->listGenerated.GetCurrentNode();
				if (person.uniqueID < personNext.uniqueID)
				{
					temp = person;
					person = personNext;
					this->listGenerated.MovePrev();
					this->listGenerated.SetCurrentNode(person);
					personNext = temp;
					this->listGenerated.MoveNext();
					this->listGenerated.SetCurrentNode(personNext);
					swapped = true;
				}
			}
		}
		break;
	}
	case iPersonMotron::ASC_BY_HEALTH:
	{
		bool swapped = true;
		int j = 0;
		sPerson temp;
		while (swapped)
		{
			this->listGenerated.MoveStart();
			swapped = false;
			j++;
			for (int i = 0; i < this->listGenerated.size() - j; i++)
			{
				sPerson person = this->listGenerated.GetCurrentNode();
				this->listGenerated.MoveNext();
				sPerson personNext = this->listGenerated.GetCurrentNode();
				if (person.health > personNext.health)
				{
					temp = person;
					person = personNext;
					this->listGenerated.MovePrev();
					this->listGenerated.SetCurrentNode(person);
					personNext = temp;
					this->listGenerated.MoveNext();
					this->listGenerated.SetCurrentNode(personNext);
					swapped = true;
				}
			}
		}
		break;
	}
	case iPersonMotron::DESC_BY_HEALTH:
	{
		bool swapped = true;
		int j = 0;
		sPerson temp;
		while (swapped)
		{
			this->listGenerated.MoveStart();
			swapped = false;
			j++;
			for (int i = 0; i < this->listGenerated.size() - j; i++)
			{
				sPerson person = this->listGenerated.GetCurrentNode();
				this->listGenerated.MoveNext();
				sPerson personNext = this->listGenerated.GetCurrentNode();
				if (person.health < personNext.health)
				{
					temp = person;
					person = personNext;
					this->listGenerated.MovePrev();
					this->listGenerated.SetCurrentNode(person);
					personNext = temp;
					this->listGenerated.MoveNext();
					this->listGenerated.SetCurrentNode(personNext);
					swapped = true;
				}
			}
		}
		break;
	}
	default:
		break;
	}
}


bool cDIYList::LoadDataFilesIntoContainer(std::string firstNameFemaleFileName,
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

	for (int i = 0; i < vecFemaleNames.size(); i++)
		this->listFemaleNames.AddStart(vecFemaleNames[i]);
	for (int i = 0; i < vecMaleNames.size(); i++)
		this->listMaleNames.AddStart(vecMaleNames[i]);
	for (int i = 0; i < vecLastNames.size(); i++)
		this->listLastNames.AddStart(vecLastNames[i]);
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}

bool cDIYList::GenerateRandomPeople(int numberOfPeople)
{
	clock_t t = clock();
	cMyList allLists;
	int ID = 0;
	for (int i = 0; i != this->listFemaleNames.size(); i++)
	{
		allLists.AddStart(this->listFemaleNames.GetCurrentNode());
		this->listFemaleNames.MoveNext();
	}
	for (int i = 0; i != this->listMaleNames.size(); i++)
	{
		allLists.AddStart(this->listMaleNames.GetCurrentNode());
		this->listMaleNames.MoveNext();
	}
	this->listFemaleNames.MoveStart();
	this->listMaleNames.MoveStart();

	for (int i = 0; i != this->listFemaleNames.size(); i++)
	{
		this->listLastNames.MoveStart();
		int randomNameIndex = rand() % this->listLastNames.size();
		int randomAge = rand() % 100 + 1;
		float randomHealth = rand() % 100 + 1;
		sPoint point;
		point.x = rand() % LENGTH;
		point.y = rand() % LENGTH;
		point.z = rand() % LENGTH;
		sPerson temp;
		this->listFemaleNames.GetCurrentNode(temp);
		for (int i = 0; i != randomNameIndex; i++)
			this->listLastNames.MoveNext();
		temp.last = this->listLastNames.GetCurrentNode().first;
		temp.uniqueID = ++ID;
		temp.age = randomAge;
		temp.health = randomHealth;
		temp.location = point;
		this->listFemaleNames.SetCurrentNode(temp);
		this->listFemaleNames.MoveNext();
	}
	for (int i = 0; i != this->listMaleNames.size(); i++)
	{
		this->listLastNames.MoveStart();
		int randomNameIndex = rand() % this->listLastNames.size();
		int randomAge = rand() % 100 + 1;
		float randomHealth = rand() % 100 + 1;
		sPoint point;
		point.x = rand() % LENGTH;
		point.y = rand() % LENGTH;
		point.z = rand() % LENGTH;
		sPerson temp;
		this->listMaleNames.GetCurrentNode(temp);
		for (int i = 0; i != randomNameIndex; i++)
			this->listLastNames.MoveNext();
		temp.last = this->listLastNames.GetCurrentNode().first;
		temp.uniqueID = ++ID;
		temp.age = randomAge;
		temp.health = randomHealth;
		temp.location = point;
		this->listMaleNames.SetCurrentNode(temp);
		this->listMaleNames.MoveNext();
	}

	allLists.MoveStart();
	this->listFemaleNames.MoveStart();
	this->listMaleNames.MoveStart();
	for (int i = 0; i != this->listFemaleNames.size(); i++)
	{
		allLists.SetCurrentNode(this->listFemaleNames.GetCurrentNode());
		allLists.MoveNext();
		this->listFemaleNames.MoveNext();
	}
	for (int i = 0; i != this->listMaleNames.size(); i++)
	{
		allLists.SetCurrentNode(this->listMaleNames.GetCurrentNode());
		allLists.MoveNext();
		this->listMaleNames.MoveNext();
	}


	ID = 0;
	for (int i = 0; i != numberOfPeople; i++)
	{
		int randomFirstNameIndex = rand() % allLists.size();
		int randomLastNameIndex = rand() % allLists.size();
		int randomAge = rand() % 100 + 1;
		float randomHealth = rand() % 100 + 1;
		sPoint point;
		point.x = rand() % LENGTH;
		point.y = rand() % LENGTH;
		point.z = rand() % LENGTH;
		sPerson person;

		allLists.MoveStart();
		for (int i = 0; i != randomFirstNameIndex; i++)
			allLists.MoveNext();
		person.first = allLists.GetCurrentNode().first;

		allLists.MoveStart();
		for (int i = 0; i != randomLastNameIndex; i++)
			allLists.MoveNext();
		person.last = allLists.GetCurrentNode().last;
		person.uniqueID = ++ID;
		person.age = randomAge;
		person.health = randomHealth;
		person.location = point;
		this->listGenerated.AddStart(person);
	}
	//this->listGenerated.PrintAll();
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}

bool cDIYList::FindPeopleByName(std::vector<sPerson> &vecPeople, sPerson personToMatch, int maxNumberOfPeople)
{
	clock_t t = clock();
	int numberOfPeople = 0;
	this->listGenerated.MoveStart();
	for (int i = 0; i != this->listGenerated.size(); i++)
	{
		if (personToMatch.first == "" && personToMatch.last == "")
		{
			vecPeople.push_back(this->listGenerated.GetCurrentNode());
			numberOfPeople++;
			if (numberOfPeople == maxNumberOfPeople)
				break;
		}
		if (personToMatch.first == "" && personToMatch.last != "")
		{
			if (this->listGenerated.GetCurrentNode().last == personToMatch.last)
			{
				vecPeople.push_back(this->listGenerated.GetCurrentNode());
				numberOfPeople++;
				if (numberOfPeople == maxNumberOfPeople)
					break;
			}
		}
		if (personToMatch.last == "" && personToMatch.first != "")
		{
			if (this->listGenerated.GetCurrentNode().first == personToMatch.first)
			{
				vecPeople.push_back(this->listGenerated.GetCurrentNode());
				numberOfPeople++;
				if (numberOfPeople == maxNumberOfPeople)
					break;
			}
		}
		if (personToMatch.last != "" && personToMatch.first != "")
		{
			if (this->listGenerated.GetCurrentNode().first == personToMatch.first && this->listGenerated.GetCurrentNode().last == personToMatch.last)
			{
				vecPeople.push_back(this->listGenerated.GetCurrentNode());
				numberOfPeople++;
				if (numberOfPeople == maxNumberOfPeople)
					break;
			}
		}
		this->listGenerated.MoveNext();
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}
bool cDIYList::FindPeopleByName(std::vector<sPerson> &vecPeople, std::vector<sPerson> &vecPeopleToMatch, int maxNumberOfPeople)
{
	clock_t t = clock();
	int numberOfPeople = 0;
	this->listGenerated.MoveStart();
	bool once = false;
	for (int i = 0; i != this->listGenerated.size(); i++)
	{
		for (int j = 0; j != vecPeopleToMatch.size(); j++)
		{
			if (vecPeopleToMatch[j].first == "" && vecPeopleToMatch[j].last == "" && !once)
			{
				vecPeople.push_back(this->listGenerated.GetCurrentNode());
				numberOfPeople++;
				if (numberOfPeople == maxNumberOfPeople)
					break;
				once = true;
			}
			if (vecPeopleToMatch[j].first == "" && vecPeopleToMatch[j].last != "")
			{
				if (this->listGenerated.GetCurrentNode().last == vecPeopleToMatch[j].last)
				{
					vecPeople.push_back(this->listGenerated.GetCurrentNode());
					numberOfPeople++;
					if (numberOfPeople == maxNumberOfPeople)
						break;
				}
			}
			if (vecPeopleToMatch[j].last == "" && vecPeopleToMatch[j].first != "")
			{
				if (this->listGenerated.GetCurrentNode().first == vecPeopleToMatch[j].first)
				{
					vecPeople.push_back(this->listGenerated.GetCurrentNode());
					numberOfPeople++;
					if (numberOfPeople == maxNumberOfPeople)
						break;
				}
			}
			if (vecPeopleToMatch[j].last != "" && vecPeopleToMatch[j].first != "")
			{
				if (this->listGenerated.GetCurrentNode().first == vecPeopleToMatch[j].first && this->listGenerated.GetCurrentNode().last == vecPeopleToMatch[j].last)
				{
					vecPeople.push_back(this->listGenerated.GetCurrentNode());
					numberOfPeople++;
					if (numberOfPeople == maxNumberOfPeople)
						break;
				}

			}
		}
		if (numberOfPeople == maxNumberOfPeople)
			break;
		once = false;
		this->listGenerated.MoveNext();
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}

//// Returns false if not found.
bool cDIYList::FindPersonByID(sPerson &person, unsigned long long uniqueID)
{
	clock_t t = clock();
	this->listGenerated.MoveStart();
	for (int i = 0; i < this->listGenerated.size(); i++)
	{
		//std::cout << this->listGenerated.GetCurrentNode().uniqueID << std::endl;
		//bool x = uniqueID == this->listGenerated.GetCurrentNode().uniqueID;
		//std::cout << x << std::endl;
		if (uniqueID == this->listGenerated.GetCurrentNode().uniqueID)
		{
			person = this->listGenerated.GetCurrentNode();
			return true;
		}
		this->listGenerated.MoveNext();
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return false;
}

//// Finds the closest people (could be zero), from a point and radius. 
//// Assume that location is "less than or equal" to radius
bool cDIYList::FindPeople(std::vector<sPerson> &vecPeople, sPoint location, float radius, int maxPeopleToReturn)
{
	clock_t t = clock();
	int count = 0;
	this->listGenerated.MoveStart();
	for (int i = 0; i < this->listGenerated.size(); i++)
	{
		float distance, distx, disty, distz;
		distx = this->listGenerated.GetCurrentNode().location.x - location.x;
		disty = this->listGenerated.GetCurrentNode().location.y - location.y;
		distz = this->listGenerated.GetCurrentNode().location.z - location.z;
		distance = sqrt(distx*distx + disty * disty + distz * distz);
		if (distance <= radius)
		{
			count++;
			vecPeople.push_back(this->listGenerated.GetCurrentNode());
		}
		if (count == maxPeopleToReturn)
			break;
		this->listGenerated.MoveNext();
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}
//// Finds people with a cetain health range (inclusive of the min and max values)
bool cDIYList::FindPeople(std::vector<sPerson> &vecPeople, float minHealth, float maxHealth,
	int maxPeopleToReturn)
{
	clock_t t = clock();
	this->listGenerated.MoveStart();
	int count = 0;
	for (int i = 0; i != this->listGenerated.size(); i++)
	{
		if (this->listGenerated.GetCurrentNode().health >= minHealth && this->listGenerated.GetCurrentNode().health <= maxHealth)
		{
			count++;
			vecPeople.push_back(this->listGenerated.GetCurrentNode());
		}
		if (count == maxPeopleToReturn)
			break;
		this->listGenerated.MoveNext();
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}
//// Combination of the two functions above
bool cDIYList::FindPeople(std::vector<sPerson> &vecPeople,
	sPoint location, float radius, float minHealth, float maxHealth,
	int maxPeopleToReturn)
{
	clock_t t = clock();
	this->listGenerated.MoveStart();
	int count = 0;
	for (int i = 0; i < this->listGenerated.size(); i++)
	{
		float distance, distx, disty, distz;
		distx = this->listGenerated.GetCurrentNode().location.x - location.x;
		disty = this->listGenerated.GetCurrentNode().location.y - location.y;
		distz = this->listGenerated.GetCurrentNode().location.z - location.z;
		distance = sqrt(distx*distx + disty * disty + distz * distz);
		if (distance <= radius && this->listGenerated.GetCurrentNode().health >= minHealth && this->listGenerated.GetCurrentNode().health <= maxHealth)
		{
			count++;
			vecPeople.push_back(this->listGenerated.GetCurrentNode());
		}
		if (count == maxPeopleToReturn)
			break;
		this->listGenerated.MoveNext();
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}

// Returns the enum from the cPerson.h file
eContainerType cDIYList::getContainerType(void)
{
	return this->containerType;
}
// Sorts the people, then returns the container of sorted people
// - this is from the data loaded by LoadDataFilesIntoContainer()
bool cDIYList::SortPeople(std::vector<sPerson> &vecPeople, eSortType sortType)
{
	clock_t t = clock();
	switch (sortType)
	{
	case iPersonMotron::ASC_FIRST_THEN_LAST:
		bubbleSort(iPersonMotron::ASC_FIRST_THEN_LAST);
		break;
	case iPersonMotron::DESC_FIRST_THEN_LAST:
		bubbleSort(iPersonMotron::DESC_FIRST_THEN_LAST);
		break;
	case iPersonMotron::ASC_LAST_THEN_FIRST:
		bubbleSort(iPersonMotron::ASC_LAST_THEN_FIRST);
		break;
	case iPersonMotron::DESC_LAST_THEN_FIRST:
		bubbleSort(iPersonMotron::DESC_LAST_THEN_FIRST);
		break;
	case iPersonMotron::ASC_BY_ID:
		bubbleSort(iPersonMotron::ASC_BY_ID);
		break;
	case iPersonMotron::DESC_BY_ID:
		bubbleSort(iPersonMotron::DESC_BY_ID);
		break;
	case iPersonMotron::ASC_BY_HEALTH:
		bubbleSort(iPersonMotron::ASC_BY_HEALTH);
		break;
	case iPersonMotron::DESC_BY_HEALTH:
		bubbleSort(iPersonMotron::DESC_BY_HEALTH);
		break;
	default:
		break;
	}
	this->listGenerated.MoveStart();
	for (int i = 0; i < this->listGenerated.size(); i++)
	{
		vecPeople.push_back(this->listGenerated.GetCurrentNode());
		this->listGenerated.MoveNext();
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}

// Can be called after every function. 
// Calls from any of the above functions overwrites this data. 
// Measuring starts from when call is made to just before it returns.
bool cDIYList::GetPerformanceFromLastCall(sPerfData &callStats)
{
	callStats = this->perfData;
	return true;
}