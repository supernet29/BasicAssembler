#include "InstructionReader.h"

namespace wc_assembler
{
	InstructionReader::InstructionReader
	(istream* Stream)
	{
		setStream(Stream);
	}
	
	bool
	InstructionReader::setStream
	(istream* Stream)	
	{
		this->Stream = Stream;
		return true;
	}

	void
	InstructionReader::readInstructions
	(list<DisjunctInstruction>& list)
	{
		//TODO
	}	
}
