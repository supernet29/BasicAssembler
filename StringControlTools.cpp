#include "StringControlTools.h"
#include <cctype>

namespace wc_string
{
	void
	StringControlTools::deleteConnectedSpaceCharacter
	(string& str)
	{
		bool deleteReady = false;
		unsigned int i, j;
		unsigned int strLength = str.length();
		char* temp = new char[strLength + 1];	

		for(i = 0, j = 0; i < strLength; i++)
		{
			if(isspace(str[i]))
			{
				if(deleteReady)
					continue;
				
				deleteReady = true;
			}
			else
			{
				deleteReady = false;
			}
				
			temp[j] = str[i];
			j++;
		}
		temp[j] = 0;
		
		str = temp;
		delete[] temp;
	}
	
	void
	StringControlTools::cleanString
	(string& str)
	{
		unsigned int i = 0, j = 0;
		unsigned int strLength = str.length();

		j = strLength - 1;
		
		while(isspace(str[i]) && (i < strLength))
		{
			i++;
		}
		
		if( i >= strLength )
		{
			str = "";
			return;
		}
			
		while(isspace(str[j]) && ( j >= 0 ))
		{
			j--;
		}
		
		str = str.substr(i, j-i+1);
	}
	
	bool
	StringControlTools::splitStringBetweenCharacter
	(string& src, string& des, char ch)
	{
		int pos;
		unsigned int chPos;
		unsigned int srcLen = src.length();
		pos = findCharacterPosition(src, ch);
		
		if(pos < 0 )
			return false;

		chPos = (unsigned int )pos;	
		des = src.substr(0, chPos);
		src = src.substr(chPos + 1,srcLen - chPos -1);
		return true;
	}
		

	int
	StringControlTools::findCharacterPosition
	(const string& src, char ch)
	{
		unsigned int i;
		unsigned int srcLen = src.length();
		
		for(i = 0; i < srcLen; i++) 
		{
			if(src[i] == ch)
				return i;
		}
		return -1;
	}	
}
