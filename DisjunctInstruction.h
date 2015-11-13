#ifndef DISJUNCT_INSTRUCTION
#define DISJUNCT_INSTRUCTION

#include <string>
#include <list>

using namespace std;

namespace wc_assembler
{

	class DisjunctInstruction
	{
	public:
		DisjunctInstruction
		(const string& label,
		 const string& instruction,
		 int address,
		 int line);
		
		const string& 
		getLabel
		();

		const string& 
		getInstruction
		();
		
		int
		getAddress
		();

		int
		getLineNumber
		();

	private:
		int address;
		int line;
		string label;
		string instruction;
	};

	typedef list<DisjunctInstruction> DisjunctInstructionList;
}

#endif
