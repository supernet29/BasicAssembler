#include "BinaryInstruction.h"

namespace wc_assembler
{
	BinartyInstruction::BinaryInstruction
	(short address, short code)
	:m_Address(address), m_Code(code)
	{
	}

	short
	BinaryInstruction::getAddress
	()
	{
		return m_Address;
	}
	
	short
	BinaryInstruction::getCode
	()
	{
		return m_Code;
	}
}
