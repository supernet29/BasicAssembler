#include <iostream>
#include <fstream>
#include "StringControlTools.h"
#include "InstructionReader.h"
#include "DisjunctInstruction.h"
#include "BinaryInstruction.h"
#include "InstructionParser.h"
#include "MRI.h"
#include "NonMRI.h"
#include "InstructionWriter.h"


using namespace std;
using namespace wc_string;
using namespace wc_assembler;

void print(string& str)
{
	cout<<"=" <<str <<"=" <<endl;
}

void printDisjunctInstruction(DisjunctInstruction& instruction)
{
	cout<<"address: " <<hex<<instruction.getAddress() <<endl;
	cout<<"label: "<<"="<<instruction.getLabel()<<"="<<endl;
	cout<<"instruction: "<<"="<<instruction.getInstruction()<<"="<<dec<<endl;
}

void printBinaryInstruction(BinaryInstruction& instruction)
{
	cout<<hex<<instruction.getAddress()<<"\t"<<instruction.getCode()<<dec<<endl;
}
	
int main(int argc, char** argv)
{
	MRI mri;
	NonMRI nonMri;
	StringControlTools tool;
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
	
	string arg1 = argv[1];
	string outFileName;
	tool.splitStringBetweenCharacter(arg1, outFileName, '.');
	outFileName += ".oasmb";
	
	
	ofstream outFile;
	outFile.open(outFileName.c_str());

	if(outFile.fail())
	{
		cerr<<"ERROR:: File open failed"<<endl;
		return 2;
	}
		
	
	InstructionReader reader(&asmFile);
	DisjunctInstructionList* result = reader.readInstructions();	
	asmFile.close();
	LabelCodeList* MRICodes = mri.getMRIList();
	LabelCodeList* NonMRICodes = nonMri.getNonMRIList();
	InstructionParser parser(result, MRICodes, NonMRICodes);
	
	BinaryInstructionList* binaryResult = parser.parseInstructions();
	
	InstructionWriter writer(binaryResult, outFile);
	if(!writer.writeInstructionToFile())
	{
		cerr<<"ERROR:: Writing File is failed"<<endl;
		return 3;
	}
	outFile.close();
		
		
	cout<<"---------------------------------"<<endl;
	cout<<"Address \t| Instruction"<<endl;
	cout<<"---------------------------------"<<endl;
	for(BinaryInstructionList::iterator i = binaryResult->begin(); i != binaryResult->end(); i++)
	{
		printBinaryInstruction(*i);
	}
	
	
	return 0;
}
