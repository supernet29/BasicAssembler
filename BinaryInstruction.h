#ifndef BINARY_INSTRUCTION
#define BINARY_INSTRUCTION

#include <list>

namespace wc_assembler
{
	
	class BinaryInstruction
	{
		public:
		BinaryInstruction
		(short address, short code);
		
		short
		getAddress
		();
		
		short
		getCode
		();

		private:
		short m_Address;
		short m_Code;
	};

	typedef list<BinaryInstruction> BinaryInstructionList;

}

#endif
