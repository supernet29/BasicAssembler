#ifndef INSTRUCTION_READER_H
#define INSTRUCTION_READER_H

#include <fstream>
#include <list>
#include "StringControlTools.h"
#include "DisjunctInstruction.h"

using std::ifstream;

namespace wc_assembler
{
	class InstructionReader
	{
	public:

		InstructionReader
		(istream* Stream);
		
		bool 
		setStream
		(istream* Stream);

		void 
		readInstructions
		(list<DisjunctInstrcution>& list);	
		
		//TODO
		
	private:

		istream * fileStream;

		//TODO
	};
}

#endif
