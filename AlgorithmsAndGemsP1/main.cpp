#include "cPerson.h"

#include <string>
#include <iostream>
#include <algorithm>
#include <time.h>

#include <vector>
#include <list>
#include <map>

#include "cSTLVector.h"
#include "cSTLList.h"
#include "cSTLMap.h"
#include "cDIYVector.h"
#include "cDIYList.h"

//#include <windows.h>
//#include <stdio.h>

#define DIV 1048576
#define WIDTH 7

cSTLVector * STLVector;
cSTLList * STLList;
cSTLMap * STLMap;
cDIYVector * DIYVector;
cDIYList * DIYList;
int main()
{
	std::vector<sPerson> personVec;
	//MEMORYSTATUSEX status;
	//status.dwLength = sizeof(MEMORYSTATUSEX);
	//GlobalMemoryStatusEx(&status);
	//DWORDLONG totalVirtualMem = status.ullTotalPageFile;
	//std::cout << status.dwMemoryLoad << std::endl;

	srand(time(NULL));
	// VECTOR

	//cSTLVector people;
	//cSTLList people;
	//cSTLMap people;
	//cDIYVector people;
	cDIYList people;
	sPerfData perfData;
	people.LoadDataFilesIntoContainer("dist.female.first.txt", "dist.male.first.txt", "US_LastNames.txt");
	people.GetPerformanceFromLastCall(perfData);
	std::cout << perfData.elapsedCallTime_ms << std::endl;
	people.GenerateRandomPeople(100);
	people.GetPerformanceFromLastCall(perfData);
	std::cout << perfData.elapsedCallTime_ms << std::endl;
	people.FindPeople(personVec, 80, 100, 100);
	people.GetPerformanceFromLastCall(perfData);
	std::cout << perfData.elapsedCallTime_ms << std::endl;
	personVec.clear();
	people.SortPeople(personVec, iPersonMotron::ASC_BY_HEALTH);
	people.GetPerformanceFromLastCall(perfData);
	std::cout << perfData.elapsedCallTime_ms << std::endl;
	//// Load Files Into Vectors
	//sPerson person;
	//std::vector<sPerson> pVec;
	//sPoint point;
	//point.x = 0.0f;
	//point.y = 0.0f;
	//point.z = 0.0f;
	//sPerson p1;
	//p1.first = "";
	//p1.last = "";
	//sPerson p2;
	//p2.first = "";
	//p2.last = "";
	//std::vector<sPerson> pMatch; pMatch.push_back(p1); pMatch.push_back(p2);
	//STLVector->LoadDataFilesIntoContainer("dist.female.first.txt", "dist.male.first.txt", "US_LastNames.txt");
	////// Generate Random People
	//STLVector->GenerateRandomPeople(1000);
	//std::cout << "Generated Vector of People:" << std::endl;
	//for (int index = 0; index != STLVector->vecGenerated.size(); index++)
	//	std::cout << STLVector->vecGenerated[index].uniqueID << " " <<
	//	STLVector->vecGenerated[index].first << " " <<
	//	STLVector->vecGenerated[index].last << std::endl;

	//STLVector->FindPeopleByName(pVec, pMatch, 100);
	//std::cout << "\nFind People By Name" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << std::endl;
	//pVec.clear();
	//STLVector->FindPersonByID(person, 3);
	//std::cout << "\nFind Person by ID" << std::endl;
	//std::cout << person.uniqueID << " " << person.first << " " << person.last << std::endl;

	//std::cout << "\nFind People by location:" << std::endl;
	//pVec.clear();
	//STLVector->FindPeople(pVec, point, 75, 100);
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << std::endl;
	//std::cout << "\nFind People by health:" << std::endl;
	//pVec.clear();
	//STLVector->FindPeople(pVec, 80, 100, 100);
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].health << std::endl;
	//std::cout << "\nFind People by location and health:" << std::endl;
	//pVec.clear();
	//STLVector->FindPeople(pVec, point, 75, 80, 100, 100);
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].health << std::endl;
	//
	//pVec.clear();
	//std::cout << "\nSort by First then Last Ascending" << std::endl;
	//STLVector->SortPeople(pVec, iPersonMotron::ASC_FIRST_THEN_LAST);
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " 
	//			  << pVec[i].first << " " << pVec[i].last << " " 
	//	          << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " "
	//	          << pVec[i].health << std::endl;
	//pVec.clear();
	//std::cout << "\nSort by First then Last Descending" << std::endl;
	//STLVector->SortPeople(pVec, iPersonMotron::DESC_FIRST_THEN_LAST);
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " "
	//	<< pVec[i].first << " " << pVec[i].last << " "
	//	<< pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " "
	//	<< pVec[i].health << std::endl;
	//pVec.clear();
	//std::cout << "\nSort by Last then First Ascending" << std::endl;
	//STLVector->SortPeople(pVec, iPersonMotron::ASC_LAST_THEN_FIRST);
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " "
	//	<< pVec[i].first << " " << pVec[i].last << " "
	//	<< pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " "
	//	<< pVec[i].health << std::endl;
	//pVec.clear();
	//std::cout << "\nSort by Last then First Descending" << std::endl;
	//STLVector->SortPeople(pVec, iPersonMotron::DESC_LAST_THEN_FIRST);
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " "
	//	<< pVec[i].first << " " << pVec[i].last << " "
	//	<< pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " "
	//	<< pVec[i].health << std::endl;
	//pVec.clear();
	//std::cout << "\nSort by ID Ascending" << std::endl;
	//STLVector->SortPeople(pVec, iPersonMotron::ASC_BY_ID);
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " "
	//	<< pVec[i].first << " " << pVec[i].last << " "
	//	<< pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " "
	//	<< pVec[i].health << std::endl;
	//pVec.clear();
	//std::cout << "\nSort by ID Descending" << std::endl;
	//STLVector->SortPeople(pVec, iPersonMotron::DESC_BY_ID);
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " "
	//	<< pVec[i].first << " " << pVec[i].last << " "
	//	<< pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " "
	//	<< pVec[i].health << std::endl;	
	//pVec.clear();
	//std::cout << "\nSort by Health Ascending" << std::endl;
	//STLVector->SortPeople(pVec, iPersonMotron::ASC_BY_HEALTH);
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " "
	//	<< pVec[i].first << " " << pVec[i].last << " "
	//	<< pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " "
	//	<< pVec[i].health << std::endl;
	//pVec.clear();
	//std::cout << "\nSort by Health Descending" << std::endl;
	//STLVector->SortPeople(pVec, iPersonMotron::DESC_BY_HEALTH);
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " "
	//	<< pVec[i].first << " " << pVec[i].last << " "
	//	<< pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " "
	//	<< pVec[i].health << std::endl;


	//// LIST
	//STLList->LoadDataFilesIntoContainer("dist.female.first.txt", "dist.male.first.txt", "US_LastNames.txt");
	//STLList->GenerateRandomPeople(1000);
	//std::list<sPerson>::iterator listIter;
	//std::cout << "\nGenerated List of People" << std::endl;
	//for (listIter = STLList->listGenerated.begin(); listIter != STLList->listGenerated.end(); listIter++)
	//{
	//		std::cout << listIter->uniqueID << " "
	//		<< listIter->first << " " << listIter->last << " "
	//		<< listIter->location.x << " " << listIter->location.y << " " << listIter->location.y << " "
	//		<< listIter->health << std::endl;
	//}	
	//pVec.clear();
	//STLList->FindPeopleByName(pVec, p1, 100);
	//std::cout << "\nFind People By Name" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.z << " " << pVec[i].location.y << " " << pVec[i].health << std::endl;
	//pVec.clear();
	//STLList->FindPeopleByName(pVec, pMatch, 100);
	//std::cout << "\nFind People By Name" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.z << " " << pVec[i].location.y << " " << pVec[i].health << std::endl;
	//sPerson per;
	//STLList->FindPersonByID(per, 3);
	//std::cout << "\nFind Person By ID" << std::endl;
	//std::cout << per.uniqueID << " " << per.first << " " << per.last << " " << per.location.x << " " << per.location.y << " " << per.location.z << " " << per.health << std::endl;
	//pVec.clear();
	//STLList->FindPeople(pVec, point, 100, 100);
	//std::cout << "\nFind People By Location" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//pVec.clear();
	//STLList->FindPeople(pVec, 70, 100, 100);
	//std::cout << "\nFind People By Health" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//pVec.clear();
	//STLList->FindPeople(pVec, point, 100, 70, 100, 100);
	//std::cout << "\nFind People By Location and Health" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//
	//pVec.clear();
	//std::cout << "\nSort by First then Last Ascending" << std::endl;
	//STLList->SortPeople(pVec, iPersonMotron::ASC_FIRST_THEN_LAST);
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " 
	//			  << pVec[i].first << " " << pVec[i].last << " " 
	//	          << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " "
	//	          << pVec[i].health << std::endl;
	//pVec.clear();
	//std::cout << "\nSort by First then Last Descending" << std::endl;
	//STLList->SortPeople(pVec, iPersonMotron::DESC_FIRST_THEN_LAST);
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " "
	//	<< pVec[i].first << " " << pVec[i].last << " "
	//	<< pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " "
	//	<< pVec[i].health << std::endl;
	//pVec.clear();
	//std::cout << "\nSort by Last then First Ascending" << std::endl;
	//STLList->SortPeople(pVec, iPersonMotron::ASC_LAST_THEN_FIRST);
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " "
	//	<< pVec[i].first << " " << pVec[i].last << " "
	//	<< pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " "
	//	<< pVec[i].health << std::endl;
	//pVec.clear();
	//std::cout << "\nSort by Last then First Descending" << std::endl;
	//STLList->SortPeople(pVec, iPersonMotron::DESC_LAST_THEN_FIRST);
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " "
	//	<< pVec[i].first << " " << pVec[i].last << " "
	//	<< pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " "
	//	<< pVec[i].health << std::endl;
	//pVec.clear();
	//std::cout << "\nSort by ID Ascending" << std::endl;
	//STLList->SortPeople(pVec, iPersonMotron::ASC_BY_ID);
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " "
	//	<< pVec[i].first << " " << pVec[i].last << " "
	//	<< pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " "
	//	<< pVec[i].health << std::endl;	
	//pVec.clear();
	//std::cout << "\nSort by ID Descending" << std::endl;
	//STLList->SortPeople(pVec, iPersonMotron::DESC_BY_ID);
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " "
	//	<< pVec[i].first << " " << pVec[i].last << " "
	//	<< pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " "
	//	<< pVec[i].health << std::endl;		
	//pVec.clear();
	//std::cout << "\nSort by Health Ascending" << std::endl;
	//STLList->SortPeople(pVec, iPersonMotron::ASC_BY_HEALTH);
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " "
	//	<< pVec[i].first << " " << pVec[i].last << " "
	//	<< pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " "
	//	<< pVec[i].health << std::endl;
	//pVec.clear();
	//std::cout << "\nSort by Health Descending" << std::endl;
	//STLList->SortPeople(pVec, iPersonMotron::DESC_BY_HEALTH);
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " "
	//	<< pVec[i].first << " " << pVec[i].last << " "
	//	<< pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " "
	//	<< pVec[i].health << std::endl;

	//// MAP
	//STLMap->LoadDataFilesIntoContainer("dist.female.first.txt", "dist.male.first.txt", "US_LastNames.txt");
	//STLMap->GenerateRandomPeople(1000);
	//std::cout << "Generated Map of People" << std::endl;
	//for (std::map<int, sPerson>::iterator iter = STLMap->mapGenerated.begin(); iter != STLMap->mapGenerated.end(); iter++)
	//{
	//	std::cout << iter->second.uniqueID << " " << iter->second.first << " " << iter->second.last << " " << iter->second.location.x << " " << iter->second.location.y << " " << iter->second.location.z << " " << iter->second.health << std::endl;
	//}
	//person.first = "";
	//person.last = "";
	//std::cout << "\nFind People by Name" << std::endl;
	//STLMap->FindPeopleByName(pVec, person, 100);
	//for (int i = 0; i != pVec.size(); i++)
	//{
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//}
	//
	//std::cout << "\nFind People by Name" << std::endl;
	//pVec.clear();
	//STLMap->FindPeopleByName(pVec, pMatch, 100);
	//for (int i = 0; i != pVec.size(); i++)
	//{
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//}
	//
	//std::cout << "\nFind People by ID" << std::endl;
	//pVec.clear();
	//STLMap->FindPersonByID(person, 23);
	//std::cout << person.uniqueID << " " << person.first << " " << person.last << " " << person.location.x << " " << person.location.y << " " << person.location.z << " " << person.health << std::endl;
	//
	//
	//std::cout << "\nFind People by Location" << std::endl;
	//pVec.clear();
	//STLMap->FindPeople(pVec, point, 100, 100);
	//for (int i = 0; i != pVec.size(); i++)
	//{
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//}
	//
	//std::cout << "\nFind People by Health" << std::endl;
	//pVec.clear();
	//STLMap->FindPeople(pVec, 70, 100, 100);
	//for (int i = 0; i != pVec.size(); i++)
	//{
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//}
	//
	//std::cout << "\nFind People by Location and Health" << std::endl;
	//pVec.clear();
	//STLMap->FindPeople(pVec, point, 100, 70, 100, 100);
	//for (int i = 0; i != pVec.size(); i++)
	//{
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//}
	//
	//
	//std::cout << "\nSort First then Last Ascending" << std::endl;
	//pVec.clear();
	//STLMap->SortPeople(pVec, iPersonMotron::ASC_FIRST_THEN_LAST);
	//for (int i = 0; i != pVec.size(); i++)
	//{
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//}
	//
	//std::cout << "\nSort First then Last Descending" << std::endl;
	//pVec.clear();
	//STLMap->SortPeople(pVec, iPersonMotron::DESC_FIRST_THEN_LAST);
	//for (int i = 0; i != pVec.size(); i++)
	//{
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//}
	//
	//std::cout << "\nSort Last then First Ascending" << std::endl;
	//pVec.clear();
	//STLMap->SortPeople(pVec, iPersonMotron::ASC_LAST_THEN_FIRST);
	//for (int i = 0; i != pVec.size(); i++)
	//{
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//}
	//
	//std::cout << "\nSort Last then First Descending" << std::endl;
	//pVec.clear();
	//STLMap->SortPeople(pVec, iPersonMotron::DESC_LAST_THEN_FIRST);
	//for (int i = 0; i != pVec.size(); i++)
	//{
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//}
	//
	//std::cout << "\nSort by ID Ascending" << std::endl;
	//pVec.clear();
	//STLMap->SortPeople(pVec, iPersonMotron::ASC_BY_ID);
	//for (int i = 0; i != pVec.size(); i++)
	//{
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//}
	//
	//std::cout << "\nSort by ID Descending" << std::endl;
	//pVec.clear();
	//STLMap->SortPeople(pVec, iPersonMotron::DESC_BY_ID);
	//for (int i = 0; i != pVec.size(); i++)
	//{
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//}
	//
	//std::cout << "\nSort by Health Ascending" << std::endl;
	//pVec.clear();
	//STLMap->SortPeople(pVec, iPersonMotron::ASC_BY_HEALTH);
	//for (int i = 0; i != pVec.size(); i++)
	//{
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//}
	//
	//std::cout << "\nSort by Health Descending" << std::endl;
	//pVec.clear();
	//STLMap->SortPeople(pVec, iPersonMotron::DESC_BY_HEALTH);
	//for (int i = 0; i != pVec.size(); i++)
	//{
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//}


	//DIYVector->LoadDataFilesIntoContainer("dist.female.first.txt", "dist.male.first.txt", "US_LastNames.txt");
	//DIYVector->GenerateRandomPeople(1000);
	//std::cout << "\nGenerated People by DIY vector" << std::endl;
	//for (int i = 0; i != DIYVector->vecGenerated.size(); i++)
	//{
	//	std::cout << DIYVector->vecGenerated[i].uniqueID << " " << DIYVector->vecGenerated[i].first << " " << DIYVector->vecGenerated[i].last << " " << DIYVector->vecGenerated[i].health << " " << DIYVector->vecGenerated[i].location.x << " " << DIYVector->vecGenerated[i].location.y << " " << DIYVector->vecGenerated[i].location.z << " " << DIYVector->vecGenerated[i].health << std::endl;
	//}
	//DIYVector->FindPeopleByName(pVec, p1, 50);
	//std::cout << "\nFind people by name" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//pVec.clear();
	//DIYVector->FindPeopleByName(pVec, pMatch, 10);
	//std::cout << "\nFind people by name" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//pVec.clear();
	//DIYVector->FindPersonByID(person, 34);
	//std::cout << "\nFind person by ID" << std::endl;
	//std::cout << person.uniqueID << " " << person.first << " " << person.last << " " << person.location.x << " " << person.location.y << " " << person.location.z << " " << person.health << std::endl;
	//pVec.clear();
	//DIYVector->FindPeople(pVec, 70, 100, 100);
	//std::cout << "\nFind people by health" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//pVec.clear();
	//DIYVector->FindPeople(pVec, point, 100, 100);
	//std::cout << "\nFind people by location" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//pVec.clear();
	//DIYVector->FindPeople(pVec, point, 100, 70, 100, 100);
	//std::cout << "\nFind people by location and health" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//pVec.clear();
	//DIYVector->SortPeople(pVec, iPersonMotron::ASC_FIRST_THEN_LAST);
	//std::cout << "\nSort people by first then last ascending" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//pVec.clear();
	//DIYVector->SortPeople(pVec, iPersonMotron::DESC_FIRST_THEN_LAST);
	//std::cout << "\nSort people by first then last descending" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//pVec.clear();
	//DIYVector->SortPeople(pVec, iPersonMotron::ASC_FIRST_THEN_LAST);
	//std::cout << "\nSort people by first then last ascending" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//pVec.clear();
	//DIYVector->SortPeople(pVec, iPersonMotron::DESC_FIRST_THEN_LAST);
	//std::cout << "\nSort people by first then last descending" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//pVec.clear();
	//DIYVector->SortPeople(pVec, iPersonMotron::ASC_LAST_THEN_FIRST);
	//std::cout << "\nSort people by last then first ascending" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//pVec.clear();
	//DIYVector->SortPeople(pVec, iPersonMotron::DESC_LAST_THEN_FIRST);
	//std::cout << "\nSort people by last then first descending" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//pVec.clear();
	//DIYVector->SortPeople(pVec, iPersonMotron::ASC_BY_ID);
	//std::cout << "\nSort people by id ascending" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//pVec.clear();
	//DIYVector->SortPeople(pVec, iPersonMotron::DESC_BY_ID);
	//std::cout << "\nSort people by id descending" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//pVec.clear();
	//DIYVector->SortPeople(pVec, iPersonMotron::ASC_BY_HEALTH);
	//std::cout << "\nSort people by health ascending" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//pVec.clear();
	//DIYVector->SortPeople(pVec, iPersonMotron::DESC_BY_HEALTH);
	//std::cout << "\nSort people by health descending" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
	//pVec.clear();

	/*DIYList->LoadDataFilesIntoContainer("dist.female.first.txt", "dist.male.first.txt", "US_LastNames.txt");

	DIYList->GenerateRandomPeople(250);

	pVec.clear();
	person.first = "SARAH";
	DIYList->FindPeopleByName(pVec, person, 25);
	std::cout << "\nFind person by name" << std::endl;
	for (int i = 0; i != pVec.size(); i++)
		std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;

	pVec.clear();
	DIYList->FindPeopleByName(pVec, pMatch, 12);
	std::cout << "\nFind people by name" << std::endl;
	for (int i = 0; i != pVec.size(); i++)
		std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;

	pVec.clear();
	DIYList->FindPersonByID(person, 245);
	std::cout << "\nFind person by ID" << std::endl;
	std::cout << person.uniqueID << " " << person.first << " " << person.last << " " << person.location.x << " " << person.location.y << " " << person.location.z << " " << person.health << std::endl;

	pVec.clear();
	DIYList->FindPeople(pVec, point, 100, 25);
	std::cout << "\nFind people by location" << std::endl;
	for (int i = 0; i != pVec.size(); i++)
		std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;

	pVec.clear();
	DIYList->FindPeople(pVec, 70, 100, 25);
	std::cout << "\nFind people by health" << std::endl;
	for (int i = 0; i != pVec.size(); i++)
		std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;

	pVec.clear();
	DIYList->FindPeople(pVec, point, 100, 70, 100, 12);
	std::cout << "\nFind people by location and health" << std::endl;
	for (int i = 0; i != pVec.size(); i++)
		std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;
*/
	//
	//pVec.clear();
	//DIYList->SortPeople(pVec, iPersonMotron::ASC_FIRST_THEN_LAST);
	//std::cout << "\nSort by first then last asc" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;

	//pVec.clear();
	//DIYList->SortPeople(pVec, iPersonMotron::DESC_FIRST_THEN_LAST);
	//std::cout << "\nSort by first then last desc" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;

	//pVec.clear();
	//DIYList->SortPeople(pVec, iPersonMotron::ASC_LAST_THEN_FIRST);
	//std::cout << "\nSort by last then first asc" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;

	//pVec.clear();
	//DIYList->SortPeople(pVec, iPersonMotron::DESC_LAST_THEN_FIRST);
	//std::cout << "\nSort by last then first desc" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;

	//pVec.clear();
	//DIYList->SortPeople(pVec, iPersonMotron::ASC_BY_ID);
	//std::cout << "\nSort by id asc" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;

	//pVec.clear();
	//DIYList->SortPeople(pVec, iPersonMotron::DESC_BY_ID);
	//std::cout << "\nSort by id desc" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;

	//pVec.clear();
	//DIYList->SortPeople(pVec, iPersonMotron::ASC_BY_HEALTH);
	//std::cout << "\nSort by health asc" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;

	//pVec.clear();
	//DIYList->SortPeople(pVec, iPersonMotron::DESC_BY_HEALTH);
	//std::cout << "\nSort by health desc" << std::endl;
	//for (int i = 0; i != pVec.size(); i++)
	//	std::cout << pVec[i].uniqueID << " " << pVec[i].first << " " << pVec[i].last << " " << pVec[i].location.x << " " << pVec[i].location.y << " " << pVec[i].location.z << " " << pVec[i].health << std::endl;

	system("pause");
	return 0;
}