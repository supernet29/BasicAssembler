#include <iostream>
#include <fstream>
#include "StringControlTools.h"
#include "InstructionReader.h"
#include "DisjunctInstruction.h"

using namespace std;
using namespace wc_string;
using namespace wc_assembler;

void print(string& str)
{
	cout<<"=" <<str <<"=" <<endl;
}

void printDisjunctInstruction(DisjunctInstruction& instruction)
{
	cout.setf(ios::hex);
	cout<<"address: " <<instruction.getAddress() <<endl;
	cout<<"label: "<<"="<<instruction.getLabel()<<"="<<endl;
	cout<<"instruction: "<<"="<<instruction.getInstruction()<<"="<<endl;
	cout.unsetf(ios::hex);
}
	
int main(int argc, char** argv)
{
	int alpa = 0;
	cout<<"============="<<endl;
	cout<<"Module Tester"<<endl;
	cout<<"============="<<endl;

	int lineNumber = 0;
		
	if(argc != 2)
	{
		cout<<"Useage:" <<endl
			<<argv[0] <<" filename"<<endl;
		return 1;
	}
	
	ifstream asmFile;
	asmFile.open(argv[1]);
	if(asmFile.fail())
	{
		cerr<<"ERROR:: File open failed"<<endl;
		return 2;
	}
	
	InstructionReader reader(&asmFile);
	DisjunctInstructionList* result = reader.readInstructions();	
	
	for(DisjunctInstructionList::iterator i = result->begin(); i != result->end(); i++, lineNumber++)
	{
		cout<<"-----------------------------"<<endl;
		cout<<"LineNumber: " <<lineNumber <<endl;
		cout<<"-----------------------------"<<endl;
		printDisjunctInstruction(*i);
	}
	
	return 0;
}
