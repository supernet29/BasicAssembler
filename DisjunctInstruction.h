#ifndef DISJUNCT_INSTRUCTION
#define DISJUNCT_INSTRUCTION

#include <string>

using namespace std;

namespace wc_assembler
{
	class DisjunctInstruction
	{
	public:
		DisjunctInstruction
		(const string& label, const string& instruction, int address);
		
		const string& 
		getLabel
		();

		const string& 
		getInstruction
		();
		
		int
		getAddress
		();

	private:
		int address;
		string label;
		string instruction;
	};
}

#endif
