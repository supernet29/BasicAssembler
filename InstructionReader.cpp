#include "InstructionReader.h"

namespace wc_assembler
{
	InstructionReader::InstructionReader
	(istream* Stream)
	: streamOn(false), ln(0)
	{
		setStream(Stream);
	}

	InstructionReader::InstructionReader
	(ifstream* fileStream)
	: streamOn(false), ln(0)
	{
		setStream(fileStream);
	}
	
	bool
	InstructionReader::setStream
	(istream* Stream)	
	{
		this->fileStream = Stream;
		streamOn = true;
		return true;
	}

	bool
	InstructionReader::setStream
	(ifstream* fileStream)
	{
		if(fileStream->fail())
		{
			streamOn = false;
			return false;
		}
			
		this->fileStream = fileStream;
		streamOn = true;
		return true;
	}
		
		

	DisjunctInstructionList*
	InstructionReader::readInstructions
	()
	{
		string line;
		string label;
		string instruction;
		DisjunctInstruction* temp;
		DisjunctInstructionList* instList;

		ln = 0;

		if(!streamOn)
			return NULL;

		instList = new DisjunctInstructionList;
		if(!instList)
		{
			cerr<<"ERROR::Memory allocation fail"<<endl;
			exit(3);
		}	

		while(getline(*fileStream, line))
		{
			tool.deleteConnectedSpaceCharacter(line);

			if(tool.findCharacterPosition(line,',') < 0)
				label = "";
			else
			{
				tool.splitStringBetweenCharacter(line, label, ',');
			}
			
			if(tool.findCharacterPosition(line, '/') < 0 )
				instruction = line;	
			else
			{
				tool.splitStringBetweenCharacter
				(line, instruction, '/');
			}

			tool.cleanString(label);
			tool.cleanString(instruction);

			if(label == "")
			{
				if(isORG(instruction))
				{
					ln = getAddress(instruction);
					continue;	
				}
				else if(isEND(instruction))
				{
					break;
				}
			}

			temp = new DisjunctInstruction(label, instruction, ln);
			if(!temp)
			{
				cerr<<"ERROR::Memory allocation fail"<<endl;
				exit(3);
			}	
			instList->push_back(*temp);
			ln++;
		}
			
		return instList;
	}	
		
	bool
	InstructionReader::isORG
	(const string& src)
	{
		int number = tool.countCharacter(src, ' ');
		if(number != 1)
			return false;	
		
		for(int i = 0; i < 3; i++)
		{
			if(src[i] != s_ORG[i])
				return false;
		}
		return true;
	}

	bool
	InstructionReader::isEND
	(const string& src)
	{
		int number = tool.countCharacter(src, ' ');
		if(number != 0)
			return false;	
		
		for(int i = 0; i < 3; i++)
		{
			if(src[i] != s_END[i])
				return false;
		}
		return true;
	}

	unsigned int
	InstructionReader::getAddress
	(const string& src)
	{
		string instruction;
		string address = src;
		
		tool.splitStringBetweenCharacter(address, instruction, ' ');
		
		
		return tool.hexStringToUInt(address);
	}	

	const string InstructionReader::s_ORG = "ORG";
	const string InstructionReader::s_END = "END";
		
}
