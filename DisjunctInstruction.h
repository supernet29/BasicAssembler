#ifndef DISJUNCT_INSTRUCTION
#define DISJUNCT_INSTRUCTION

#include <string>

using namespace std;

class DisjunctInstruction
{
public:
	DisjunctInstruction(string& label, string& instruction);
	
	string getLabel();
	string getInstruction();

private:

	string label;
	string instruction;
};
