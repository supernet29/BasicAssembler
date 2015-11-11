#ifndef INSTRUCTION_PARSER_H
#define INSTRUCTION_PARSER_H

#include <string>
#include <cstdlib>
#include <iostream>
#include "DisjunctInstruction.h"
#include "LabelCode.h"
#include "StringControlTools.h"
#include "BinaryInstruction.h"

using namespace std;
using namespace wc_string;

namespace wc_assembler
{
	class InstructionParser
	{
		public:
		InstructionParser
		(DisjunctInstructionList* instructionList,
		LabelCodeList* MRI_Code,
		LabelCodeList* nonMRI_Code);

		~InstructionParser
		();
		
		BinaryInstructionList* 
		parseInstructions
		();

				
		private:
		DisjunctInstructionList* m_Instructions;
		LabelCodeList* m_MRI_Code;
		LabelCodeList* m_nonMRI_Code;
		LabelCodeList m_AddressList;
		StringControlTools tool;

		void
		makeAddressTable
		();

		short
		getMRICode
		(const string& label);
		
		short
		getNonMRICode
		(const string& label);
		
		int
		splitInstructionString
		(const string& src,
		string& instruction,
		string& address,
		string& indirect);

		short
		findAddressByLabel
		(const string& label);

		bool
		isSingleInstruction
		(DisjunctInstruction& instruction);
		
	};
}

#endif
