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
		//
		const static string s_ORG;
		const static string s_END; 
		
	private:
		int ln;
		bool streamOn;
		StringControlTools tool;
		istream * fileStream;
		//TODO

		bool
		isORG
		(const string& src);
		
		bool
		isEND
		(const string& src);
		
		unsigned int
		getAddress
		(const string& src);

	};
}

#endif
