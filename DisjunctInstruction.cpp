#include "DisjunctInstruction.h"

namespace wc_assembler
{
	DisjunctInstruction::DisjunctInstruction
	(const string& label, const string& instruction)
	{
		this->label = label;
		this->instruction = instruction
	}
	
	const string&
	DisjunctInstruction::getLabel
	()
	{
		return label;
	}

	const string&
	DisjunctInstruction::getInstruction
	()
	{
		return instruction;
	}
}
