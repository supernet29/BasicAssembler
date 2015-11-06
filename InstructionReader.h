#ifndef INSTRUCTION_READER_H
#define INSTRUCTION_READER_H

#include <fstream>
#include <list>
#include <iostream>
#include <cstdlib>
#include "StringControlTools.h"
#include "DisjunctInstruction.h"

using namespace std;
using namespace wc_string;

namespace wc_assembler
{
	typedef list<DisjunctInstruction> DisjunctInstructionList;
	
	class InstructionReader
	{
	public:

		InstructionReader
		(istream* Stream);
		
		InstructionReader
		(ifstream* fileStream);
		
		bool 
		setStream
		(istream* Stream);

		bool
		setStream
		(ifstream* fileStream);

		DisjunctInstructionList*
		readInstructions
		();
		//TODO
		
	private:
		StringControlTools tool;
		bool streamOn;
		istream * fileStream;
		//TODO
	};
}

#endif
