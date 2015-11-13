#ifndef INSTRUCTION_WRITER_H
#define INSTRUCTION_WRITER_H

#include <fstream>
#include <iostream>
#include "BinaryInstruction.h"

using namespace std;

namespace wc_assembler
{
	class InstructionWriter
	{
		public:
		InstructionWriter
		(BinaryInstructionList* list, ofstream& stream);
		
		bool
		writeInstructionToFile
		();
		
		private:
		BinaryInstructionList* m_InstructionList;
		ofstream& m_OutputFile;
	};
}
		
		
#endif
