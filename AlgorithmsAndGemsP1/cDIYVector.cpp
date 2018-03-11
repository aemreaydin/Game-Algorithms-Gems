#include "cDIYVector.h"
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

void cDIYVector::quickSort(int start, int end, eSortType sortType)
{
	end -= 1;
	switch (sortType)
	{
	case iPersonMotron::ASC_FIRST_THEN_LAST:
		break;
	case iPersonMotron::DESC_FIRST_THEN_LAST:
		break;
	case iPersonMotron::ASC_LAST_THEN_FIRST:
		break;
	case iPersonMotron::DESC_LAST_THEN_FIRST:
		break;
	case iPersonMotron::ASC_BY_ID:
		break;
	case iPersonMotron::DESC_BY_ID:
		break;
	case iPersonMotron::ASC_BY_HEALTH:
	{
		int i = start, j = end;
		sPerson tmp;
		float pivot = 50;
		while (i <= j)
		{
			while (this->vecGenerated[i].health < pivot)
			{
				i++;
			}
			while (this->vecGenerated[j].health > pivot)
			{
				j--;
			}
			if (i <= j)
			{
				tmp = this->vecGenerated[j];
				this->vecGenerated[i] = this->vecGenerated[j];
				this->vecGenerated[j] = tmp;
				i++;
				j--;
			}
		}
		if (start < j)
			quickSort(start, j, sortType);
		if (i < end)
			quickSort(i, end, sortType);
		break;
	}
	case iPersonMotron::DESC_BY_HEALTH:
		break;
	default:
		break;
	}

}
void cDIYVector::bubbleSort(eSortType sortType)
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
			swapped = false;
			j++;
			for (int i = 0; i < this->vecGenerated.size() - j; i++)
			{
				if (this->vecGenerated[i].first > this->vecGenerated[i + 1].first)
				{
					temp = this->vecGenerated[i];
					this->vecGenerated[i] = this->vecGenerated[i + 1];
					this->vecGenerated[i + 1] = temp;
					swapped = true;
				}
			}
		}
		swapped = true;
		j = 0;
		while (swapped)
		{
			swapped = false;
			j++;
			for (int i = 0; i < this->vecGenerated.size() - j; i++)
			{
				if (this->vecGenerated[i].first == this->vecGenerated[i + 1].first && this->vecGenerated[i].last > this->vecGenerated[i + 1].last)
				{
					temp = this->vecGenerated[i];
					this->vecGenerated[i] = this->vecGenerated[i + 1];
					this->vecGenerated[i + 1] = temp;
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
			swapped = false;
			j++;
			for (int i = 0; i < this->vecGenerated.size() - j; i++)
			{
				if (this->vecGenerated[i].first < this->vecGenerated[i + 1].first)
				{
					temp = this->vecGenerated[i];
					this->vecGenerated[i] = this->vecGenerated[i + 1];
					this->vecGenerated[i + 1] = temp;
					swapped = true;
				}
			}
		}
		swapped = true;
		j = 0;
		while (swapped)
		{
			swapped = false;
			j++;
			for (int i = 0; i < this->vecGenerated.size() - j; i++)
			{
				if (this->vecGenerated[i].first == this->vecGenerated[i + 1].first && this->vecGenerated[i].last < this->vecGenerated[i + 1].last)
				{
					temp = this->vecGenerated[i];
					this->vecGenerated[i] = this->vecGenerated[i + 1];
					this->vecGenerated[i + 1] = temp;
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
			swapped = false;
			j++;
			for (int i = 0; i < this->vecGenerated.size() - j; i++)
			{
				if (this->vecGenerated[i].last > this->vecGenerated[i + 1].last)
				{
					temp = this->vecGenerated[i];
					this->vecGenerated[i] = this->vecGenerated[i + 1];
					this->vecGenerated[i + 1] = temp;
					swapped = true;
				}
			}
		}
		swapped = true;
		j = 0;
		while (swapped)
		{
			swapped = false;
			j++;
			for (int i = 0; i < this->vecGenerated.size() - j; i++)
			{
				if (this->vecGenerated[i].last == this->vecGenerated[i + 1].last && this->vecGenerated[i].first > this->vecGenerated[i + 1].first)
				{
					temp = this->vecGenerated[i];
					this->vecGenerated[i] = this->vecGenerated[i + 1];
					this->vecGenerated[i + 1] = temp;
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
			swapped = false;
			j++;
			for (int i = 0; i < this->vecGenerated.size() - j; i++)
			{
				if (this->vecGenerated[i].last < this->vecGenerated[i + 1].last)
				{
					temp = this->vecGenerated[i];
					this->vecGenerated[i] = this->vecGenerated[i + 1];
					this->vecGenerated[i + 1] = temp;
					swapped = true;
				}
			}
		}
		swapped = true;
		j = 0;
		while (swapped)
		{
			swapped = false;
			j++;
			for (int i = 0; i < this->vecGenerated.size() - j; i++)
			{
				if (this->vecGenerated[i].last ==  this->vecGenerated[i + 1].last && this->vecGenerated[i].first < this->vecGenerated[i + 1].first)
				{
					temp = this->vecGenerated[i];
					this->vecGenerated[i] = this->vecGenerated[i + 1];
					this->vecGenerated[i + 1] = temp;
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
			swapped = false;
			j++;
			for (int i = 0; i < this->vecGenerated.size() - j; i++)
			{
				if (this->vecGenerated[i].uniqueID > this->vecGenerated[i + 1].uniqueID)
				{
					temp = this->vecGenerated[i];
					this->vecGenerated[i] = this->vecGenerated[i + 1];
					this->vecGenerated[i + 1] = temp;
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
			swapped = false;
			j++;
			for (int i = 0; i < this->vecGenerated.size() - j; i++)
			{
				if (this->vecGenerated[i].uniqueID < this->vecGenerated[i + 1].uniqueID)
				{
					temp = this->vecGenerated[i];
					this->vecGenerated[i] = this->vecGenerated[i + 1];
					this->vecGenerated[i + 1] = temp;
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
			swapped = false;
			j++;
			for (int i = 0; i < this->vecGenerated.size() - j; i++)
			{
				if (this->vecGenerated[i].health > this->vecGenerated[i + 1].health)
				{
					temp = this->vecGenerated[i];
					this->vecGenerated[i] = this->vecGenerated[i + 1];
					this->vecGenerated[i + 1] = temp;
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
			swapped = false;
			j++;
			for (int i = 0; i < this->vecGenerated.size() - j; i++)
			{
				if (this->vecGenerated[i].health < this->vecGenerated[i + 1].health)
				{
					temp = this->vecGenerated[i];
					this->vecGenerated[i] = this->vecGenerated[i + 1];
					this->vecGenerated[i + 1] = temp;
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

bool cDIYVector::LoadDataFilesIntoContainer(std::string firstNameFemaleFileName,
	std::string firstNameMaleFileName,
	std::string lastNameFileName)
{
	clock_t t = clock();
	std::vector<sPerson> vecFemaleNames;
	std::vector<sPerson> vecMaleNames;
	std::vector<sPerson> vecLastNames;

	if (!loadDataIntoVector2(firstNameFemaleFileName, vecFemaleNames,
		firstNameMaleFileName, vecMaleNames,
		lastNameFileName,vecLastNames, error))
	{
		return false;
	}

	for (int i = 0; i < vecFemaleNames.size(); i++)
		this->vecFemaleNames.push_back(vecFemaleNames[i]);
	for (int i = 0; i < vecMaleNames.size(); i++)
		this->vecMaleNames.push_back(vecMaleNames[i]);
	for (int i = 0; i < vecLastNames.size(); i++)
		this->vecLastNames.push_back(vecLastNames[i]);
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}

// Based on the files that have been loaded, generate people.
// Should be a mix of male and female names.
// Unique IDs must be unique								 
bool cDIYVector::GenerateRandomPeople(int numberOfPeople)
{
	clock_t t = clock();
	cMyVector allVecs;
	int ID = 0;
	for (int i = 0; i != this->vecFemaleNames.size(); i++)
		allVecs.push_back(this->vecFemaleNames.get_index(i));
	for (int i = 0; i != this->vecMaleNames.size(); i++)
		allVecs.push_back(this->vecMaleNames.get_index(i));/*
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
	allVecs.clear();
	for (int i = 0; i != this->vecFemaleNames.size(); i++)
		allVecs.push_back(this->vecFemaleNames[i]);
	for (int i = 0; i != this->vecMaleNames.size(); i++)
		allVecs.push_back(this->vecMaleNames[i]);

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

// Returns only people with this name 
// If the name (first or last) is blank (""), then ignore this parameter.
// For example: 
// - if last name is "", search only by first name
// - if first name is "", search only by last name
// - if both names are blank, return everyone
bool cDIYVector::FindPeopleByName(std::vector<sPerson> &vecPeople, sPerson personToMatch, int maxNumberOfPeople)
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
bool cDIYVector::FindPeopleByName(std::vector<sPerson> &vecPeople, std::vector<sPerson> &vecPeopleToMatch, int maxNumberOfPeople)
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

//// Returns false if not found.
bool cDIYVector::FindPersonByID(sPerson &person, unsigned long long uniqueID)
{
	clock_t t = clock();
	for (int i = 0; i < this->vecGenerated.size(); i++)
	{
		if (uniqueID == this->vecGenerated[i].uniqueID)
		{
			person = this->vecGenerated[i];
			return true;
		}
	}
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return false;
}

//// Finds the closest people (could be zero), from a point and radius. 
//// Assume that location is "less than or equal" to radius
bool cDIYVector::FindPeople(std::vector<sPerson> &vecPeople, sPoint location, float radius, int maxPeopleToReturn)
{
	clock_t t = clock();
	int count = 0;
	for (int i = 0; i < this->vecGenerated.size(); i++)
	{
		float distance, distx, disty, distz;
		distx = this->vecGenerated[i].location.x - location.x;
		disty = this->vecGenerated[i].location.y - location.y;
		distz = this->vecGenerated[i].location.z - location.z;
		distance = sqrt(distx * distx + disty * disty + distz * distz);
		if (distance <= radius)
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
//// Finds people with a cetain health range (inclusive of the min and max values)
bool cDIYVector::FindPeople(std::vector<sPerson> &vecPeople, float minHealth, float maxHealth,
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
//// Combination of the two functions above
bool cDIYVector::FindPeople(std::vector<sPerson> &vecPeople,
	sPoint location, float radius, float minHealth, float maxHealth,
	int maxPeopleToReturn)
{
	clock_t t = clock();
	int count = 0;
	for (int i = 0; i < this->vecGenerated.size(); i++)
	{
		float distance, distx, disty, distz;
		distx = this->vecGenerated[i].location.x - location.x;
		disty = this->vecGenerated[i].location.y - location.y;
		distz = this->vecGenerated[i].location.z - location.z;
		distance = sqrt(distx*distx + disty * disty + distz * distz);
		if (distance <= radius && this->vecGenerated[i].health >= minHealth && this->vecGenerated[i].health <= maxHealth)
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

// Returns the enum from the cPerson.h file
eContainerType cDIYVector::getContainerType(void)
{
	return this->containerType;
}


// Sorts the people, then returns the container of sorted people
// - this is from the data loaded by LoadDataFilesIntoContainer()
bool cDIYVector::SortPeople(std::vector<sPerson> &vecPeople, eSortType sortType)
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
	for (int i = 0; i < this->vecGenerated.size(); i++)
		vecPeople.push_back(this->vecGenerated[i]);
	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	this->perfData.elapsedCallTime_ms = timeTaken;
	return true;
}

// Can be called after every function. 
// Calls from any of the above functions overwrites this data. 
// Measuring starts from when call is made to just before it returns.
bool cDIYVector::GetPerformanceFromLastCall(sPerfData &callStats)
{
	callStats = this->perfData;
	return true;
}