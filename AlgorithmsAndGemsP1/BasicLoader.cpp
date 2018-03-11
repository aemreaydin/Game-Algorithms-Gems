#include <vector>
#include <list>
#include <string>
#include <fstream>

#include "cPerson.h"

bool loadDataIntoVector( std::string femaleNamesFileName, std::vector<std::string> &vecFirstFemale, 
						 std::string maleNamesFileName, std::vector<std::string> &vecFirstMale, 
						 std::string lastNamesFileName, std::vector<std::string> &vecLast, 
						 std::string &error )
{
	std::fstream femaleFile(femaleNamesFileName.c_str());
	std::fstream maleFile(maleNamesFileName.c_str());
	std::fstream lastNameFile(lastNamesFileName.c_str());
	std::string tempName;	
	float garbage;

	if ( ! femaleFile.is_open() )
	{
		error = "Can't open female name file called " + femaleNamesFileName;
		return false;
	}	
	while ( femaleFile >> tempName )
	{
		vecFirstFemale.push_back( tempName );
		femaleFile >> garbage >> garbage >> garbage;
	}

	if (!maleFile.is_open())
	{
		error = "Can't open male name file called " + maleNamesFileName;
		return false;
	}
	while (maleFile >> tempName)
	{
		vecFirstMale.push_back(tempName);
		maleFile >> garbage >> garbage >> garbage;
	}

	if (!lastNameFile.is_open())
	{
		error = "Can't open last name file called " + lastNamesFileName;
		return false;
	}
	while (lastNameFile >> tempName)
	{
		vecLast.push_back(tempName);
		lastNameFile >> garbage >> garbage >> garbage;
	}

	return true;
}

unsigned int scanToToken( char* pArray,  char tokenToFind, 
						  unsigned int maxIndex, unsigned int index = 0 )
{
	while ( index < maxIndex )
	{
		if ( pArray[index] == tokenToFind )
		{
			return index;
		}
		index++;
	};

	return maxIndex;
}

// Uses c interface, rather than C++ one (so WAY faster)
bool loadDataIntoVector2( std::string femaleNamesFileName, std::vector<sPerson> &vecFirstFemale,
						  std::string maleNamesFileName, std::vector<sPerson> &vecFirstMale,
						  std::string lastNamesFileName, std::vector<sPerson> &vecLast,
						  std::string &error )
{
	// START OF: load female file
	{	
		std::fstream femaleFile(femaleNamesFileName.c_str());
		if (!femaleFile.is_open())
		{
			error = "Can't open female name file called " + femaleNamesFileName;
			return false;
		}
		femaleFile.seekg(0, std::ios::end);
		// returns "std::ios::pos_type" type (which seems to be int in VC++)
		unsigned int fileSize = static_cast<unsigned int>(femaleFile.tellg());
		// Return to start
		femaleFile.seekg(0, std::ios::beg);

		//std::vector<char> data( static_cast<unsigned int>(fileSize), 0);
		//this->m_vecRawData.resize( static_cast<unsigned int>(fileSize), 0);
		char* pCharData = new char[fileSize];
		femaleFile.read(pCharData, fileSize);
		femaleFile.close();

		// Now pRawData contains the entire file
		// You can scan to the 1st 'whitespace' to get the end of the first name
		// You can scan to the 1st newline (\n) to get the end of the first line
		// ...etc.
		unsigned int startIndex = 0;
		unsigned int endIndex = scanToToken(pCharData, ' ', fileSize, startIndex);
		unsigned int lineStartIndex = 0;
		unsigned int lineEndIndex = scanToToken(pCharData, '\n', fileSize, startIndex);
		char tempBuff[256] = { 0 };
		char tempLineBuff[256] = { 0 };

		while (lineEndIndex <= fileSize)
		{
			// Scan for whitespace
			memcpy(tempBuff, &(pCharData[startIndex]), endIndex - startIndex);
			tempBuff[endIndex - startIndex] = '\0';
			std::string tempString(tempBuff);
			sPerson person;
			person.first = tempString;
			vecFirstFemale.push_back(person);
			// Scan for newline
			if (lineEndIndex == fileSize)
				break;
			memcpy(tempBuff, &(pCharData[lineStartIndex]), lineEndIndex - lineStartIndex);
			tempBuff[lineEndIndex - lineStartIndex] = '\0';
			std::string tempLineString(tempBuff);

			// Update index positions
			startIndex = lineEndIndex + 1;
			endIndex = scanToToken(pCharData, ' ', fileSize, startIndex);
			lineStartIndex = lineEndIndex + 1;
			lineEndIndex = scanToToken(pCharData, '\n', fileSize, startIndex);
			if (endIndex > 149560)
				int x = 0;
		}
		delete pCharData;
	}

	// START OF: load male file
	{	
		std::fstream maleFile(maleNamesFileName.c_str());
		if (!maleFile.is_open())
		{
			error = "Can't open female name file called " + maleNamesFileName;
			return false;
		}
		maleFile.seekg(0, std::ios::end);
		// returns "std::ios::pos_type" type (which seems to be int in VC++)
		unsigned int fileSize = static_cast<unsigned int>(maleFile.tellg());
		// Return to start
		maleFile.seekg(0, std::ios::beg);

		//std::vector<char> data( static_cast<unsigned int>(fileSize), 0);
		//this->m_vecRawData.resize( static_cast<unsigned int>(fileSize), 0);
		char* pCharData = new char[fileSize];
		maleFile.read(pCharData, fileSize);
		maleFile.close();

		// Now pRawData contains the entire file
		// You can scan to the 1st 'whitespace' to get the end of the first name
		// You can scan to the 1st newline (\n) to get the end of the first line
		// ...etc.
		unsigned int startIndex = 0;
		unsigned int endIndex = scanToToken(pCharData, ' ', fileSize, startIndex);
		unsigned int lineStartIndex = 0;
		unsigned int lineEndIndex = scanToToken(pCharData, '\n', fileSize, startIndex);
		char tempBuff[256] = { 0 };
		char tempLineBuff[256] = { 0 };

		while (lineEndIndex <= fileSize)
		{
			// Scan for whitespace
			memcpy(tempBuff, &(pCharData[startIndex]), endIndex - startIndex);
			tempBuff[endIndex - startIndex] = '\0';
			std::string tempString(tempBuff);
			sPerson person;
			person.first = tempString;
			vecFirstMale.push_back(person);
			// Scan for newline
			if (lineEndIndex == fileSize)
				break;
			memcpy(tempBuff, &(pCharData[lineStartIndex]), lineEndIndex - lineStartIndex);
			tempBuff[lineEndIndex - lineStartIndex] = '\0';
			std::string tempLineString(tempBuff);

			// Update index positions
			startIndex = lineEndIndex + 1;
			endIndex = scanToToken(pCharData, ' ', fileSize, startIndex);
			lineStartIndex = lineEndIndex + 1;
			lineEndIndex = scanToToken(pCharData, '\n', fileSize, startIndex);
			if (endIndex > 149560)
				int x = 0;
		}

		delete pCharData;
	}


	// START OF: load lastname file
	{	
		std::fstream lastNameFile(lastNamesFileName.c_str());
		if (!lastNameFile.is_open())
		{
			error = "Can't open female name file called " + lastNamesFileName;
			return false;
		}
		lastNameFile.seekg(0, std::ios::end);
		// returns "std::ios::pos_type" type (which seems to be int in VC++)
		unsigned int fileSize = static_cast<unsigned int>(lastNameFile.tellg());
		// Return to start
		lastNameFile.seekg(0, std::ios::beg);

		//std::vector<char> data( static_cast<unsigned int>(fileSize), 0);
		//this->m_vecRawData.resize( static_cast<unsigned int>(fileSize), 0);
		char* pCharData = new char[fileSize];
		lastNameFile.read(pCharData, fileSize);
		lastNameFile.close();

		// Now pRawData contains the entire file
		// You can scan to the 1st 'whitespace' to get the end of the first name
		// You can scan to the 1st newline (\n) to get the end of the first line
		// ...etc.
		unsigned int startIndex = 0;
		unsigned int endIndex = scanToToken(pCharData, ' ', fileSize, startIndex);
		unsigned int lineStartIndex = 0;
		unsigned int lineEndIndex = scanToToken(pCharData, '\n', fileSize, startIndex);
		char tempBuff[256] = { 0 };
		char tempLineBuff[256] = { 0 };

		while (lineEndIndex <= fileSize)
		{
			// Scan for whitespace
			memcpy(tempBuff, &(pCharData[startIndex]), endIndex - startIndex);
			tempBuff[endIndex - startIndex] = '\0';
			std::string tempString(tempBuff);
			sPerson person;
			person.first = tempString;
			vecLast.push_back(person);
			// Scan for newline
			if (lineEndIndex == fileSize)
				break;
			memcpy(tempBuff, &(pCharData[lineStartIndex]), lineEndIndex - lineStartIndex);
			tempBuff[lineEndIndex - lineStartIndex] = '\0';
			std::string tempLineString(tempBuff);

			// Update index positions
			startIndex = lineEndIndex + 1;
			endIndex = scanToToken(pCharData, ' ', fileSize, startIndex);
			lineStartIndex = lineEndIndex + 1;
			lineEndIndex = scanToToken(pCharData, '\n', fileSize, startIndex);
			if (endIndex > 149560)
				int x = 0;
		}

		//
		//memcpy(tempBuff, &(pCharData[startIndex]), endIndex - startIndex);
		//tempBuff[endIndex - startIndex] = '\0';
		//std::string tempString(tempBuff);
		//vecFirstFemale.push_back(tempString);

		//// Scan for '\n'
		//
		//memcpy(tempBuff, &(pCharData[lineStartIndex]), lineEndIndex - lineStartIndex);
		//tempBuff[lineEndIndex - lineStartIndex] = '\0';
		//std::string tempLineString(tempBuff);

		//startIndex = lineEndIndex + 1;
		//endIndex = scanToToken(pCharData, ' ', fileSize, startIndex);

		//memcpy(tempBuff, &(pCharData[startIndex]), endIndex - startIndex);
		//tempBuff[endIndex - startIndex] = '\0';
		//std::string tempAgain(tempBuff);

		delete pCharData;
	}//ENDOF: load female file

	return true;
}
