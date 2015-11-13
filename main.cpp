#include <iostream>
#include <fstream>
#include "InstructionWriter.h"
#include "MRI.h"
#include "NonMRI.h"
#include "InstructionReader.h"
#include "InstructionParser.h"
#include "LabelCode.h"
#include "DisjunctInstruction.h"
#include "BinaryInstruction.h"

using namespace std;
using namespace wc_assembler;

void printUsage(char** argv)
{
	cout<<"USAGE: " <<argv[0] <<" input_file_name [output_file_name]"<<endl;
}

void printCantOpen(const string& name)
{
	cout<<"ERROR :: Can't openFile -> "<<name<<endl;
}

int main(int argc, char** argv)
{
	string inFileName;
	string outFileName;

	if(argc == 2)
	{
		inFileName = argv[1];
		outFileName = "Result.oasmb";
	}
	else if(argc == 3)
	{
		inFileName = argv[1];
		outFileName = argv[2];
	}
	else	
	{
		printUsage(argv);
		return 1;
	}

	ifstream inFile;
	inFile.open(inFileName.c_str());
	if(!inFile.is_open())
	{
		printCantOpen(inFileName);
		return 2;
	}
	
	InstructionReader reader(&inFile);
	DisjunctInstructionList* readResult = reader.readInstructions();
	if(readResult == NULL)
	{
		cout<<"ERROR :: Instruction reading is failed"<<endl;
		return 3;
	}
	
	MRI MRICodeMaker;
	LabelCodeList* MRI_CodeList = MRICodeMaker.getMRIList();
	
	NonMRI NonMRICodeMaker;
	LabelCodeList* NonMRI_CodeList = NonMRICodeMaker.getNonMRIList();

	InstructionParser parser(readResult, MRI_CodeList, NonMRI_CodeList);
	BinaryInstructionList* parseResult = parser.parseInstructions();
	if(parseResult == NULL)
	{
		cout<<"ERROR :: Instruction parsing is failed"<<endl;
		return 4;
	}

	ofstream outFile;
	outFile.open(outFileName.c_str());
	if(!outFile.is_open())
	{
		printCantOpen(outFileName);
		return 2;
	}
	
	InstructionWriter writer(parseResult, outFile);
	if(!writer.writeInstructionToFile())	
	{
		cout<<"ERROR :: Instruction writing is failed"<<endl;
		return 5;
	}
	
	return 0;
}
