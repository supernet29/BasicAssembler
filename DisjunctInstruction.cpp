#include "DisjunctInstruction.h"

namespace wc_assembler
{
	DisjunctInstruction::DisjunctInstruction
	(const string& label, const string& instruction, int address)
	{
		this->label = label;
		this->instruction = instruction;
		this->address = address;
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

	int
	DisjunctInstruction::getAddress
	()
	{
		return address;
	}
}
