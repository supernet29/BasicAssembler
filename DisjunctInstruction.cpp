#include "DisjunctInstruction.h"

namespace wc_assembler
{
	DisjunctInstruction::DisjunctInstruction
	(const string& label, const string& instruction,
	 int address, int line)
	:label(label), instruction(instruction), address(address),
	 line(line)
	{
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

	int
	DisjunctInstruction::getLineNumber
	()
	{
		return line;
	}
}
