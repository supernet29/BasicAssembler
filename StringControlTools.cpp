#include "StringControlTools.h"
#include <iostream>
#include <cctype>
#include <cmath>

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
			
		while(isspace(str[j]) && ( j <= strLength ))
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
		
	unsigned int
	StringControlTools::countCharacter
	(const string& src, char ch)
	{
		unsigned int count = 0;
		unsigned int srcLength = src.length();
		
		for(unsigned int i = 0; i < srcLength; i++)
		{
			if(src[i] == ch)
				count++;
		}
		return count;
	}

	unsigned int
	StringControlTools::hexStringToUInt
	(const string& src)
	{
		return (unsigned int)stringToInt(src, 16);
	}
		
	int
	StringControlTools::digitToInteger
	(char digit)
	{
		int j;
		switch(digit)
		{
		case 'A':
		case 'a':
			j = 10;
			break;
		case 'B':
		case 'b':
			j = 11;
			break;
		case 'C':
		case 'c':
			j = 12;
			break;
		case 'D':
		case 'd':
			j = 13;
			break;
		case 'E':
		case 'e':
			j = 14;
			break;
		case 'f':
		case 'F':		
			j = 15;
			break;
		case '1':
			j = 1;
			break;
		case '2':
			j = 2;
			break;
		case '3':
			j = 3;
			break;
		case '4':
			j = 4;
			break;
		case '5':
			j = 5;
			break;
		case '6':
			j = 6;
			break;
		case '7':
			j = 7;
			break;
		case '8':
			j = 8;
			break;
		case '9':
			j = 9;
			break;
		case '0':
			j = 0;
			break;
		default:
			cout<<"ERROR:: no vaild Format"<<endl;
			return -1;
		}
		return j;
	}

	int
	StringControlTools::stringToInt
	(const string& src, int base)
	{
		int j;
		unsigned int result = 0;
		unsigned int srcLength = src.length();

		for(unsigned int i = 0; i < srcLength; i++)
		{
			j = digitToInteger(src[i]);
			if(j < 0 || j >= base)
			{
				cout<<"ERROR:: format Error";
			}
			result += (unsigned int)(j * pow(base, srcLength - i - 1));
		}
		return result;
		
	}
}
