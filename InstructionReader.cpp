#include "InstructionReader.h"

namespace wc_assembler
{
	InstructionReader::InstructionReader
	(istream* Stream)
	{
		setStream(Stream);
	}

	InstructionReader::InstructionReader
	(ifstream* fileStream)
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
		m_lineCounter = 1;

		if(!streamOn)
			return NULL;

		instList = new DisjunctInstructionList;
		if(!instList)
		{
			cerr<<"ERROR::Memory allocation fail"<<endl;
			exit(1);
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
			
			if(too.findCharacterPosition(line, '/') < 0 )
				instruction = line;	
			else
			{
				tool.splitStringBetweenCharacter
				(line, instruction, '/');
			}

			tool.cleanString(label);
			tool.cleanString(instruction);
			
			temp = new DisjunctInstruction(label, instruction);
			
			instList->push_back(*temp);
		}
			
		return instList;
	}	
		
}
