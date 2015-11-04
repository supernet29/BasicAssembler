#ifndef INSTRUCTION_READER_H
#define INSTRUCTION_READER_H

#include <fstream>
#include "DisjunctInstruction.h"

using std::ifstream;

class InstructionReader
{
public:

	InstructionReader(istream* fileStream);

		
	

private:

	istream * fileStream;

};

#endif
