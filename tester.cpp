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
	
int main(int argc, char** argv)
{
	cout<<"============="<<endl;
	cout<<"Module Tester"<<endl;
	cout<<"============="<<endl;
		
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
	DisjunctInstructionList result = reader.readInstructions();	
	
	for(DisjunctInstructionList::iterator i = result.begin(); i != result.end(); i++)
	{
		//TODO	
	return 0;
}
