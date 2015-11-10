#include "InstructionParser.h"

namespace wc_assembler
{
	InstructionParser::InstructionParser
	(DisjunctInstructionList* instructionList,
	LabelCodeList* MRI_Code,
	LabelCodeList* nonMRI_Code)
	:m_MRI_Code(MRI_Code), m_nonMRI_Code(nonMRI_Code),
	m_instructions(instructionList)
	{
	}

	InstructionParser::~InstructionParser
	()
	{
		delete m_Instructions;
	}

	BinaryInstructionList*
	parseInstructions
	()
	{
		string instruction;
		string label;
		string indirect;
		short address;
		short code;
		short labelAddress;
		BinaryInstruction* temp;
		BinaryInstructionList* binaryInstruction;
		binaryInstruction = new BinaryInstructionList();
		
		makeAddressTable();

		for(DisjunctInstructionList::iterator i = m_Instructions.begin();
		i != m_Instructions.end(); i++)
		{
			address = (short)*i.getAddress();

			if(isSingleInstruction(*i))
			{
				instruction = *i.getInstruction();

				code = getNonMRICode(instruction);
				if(code == -1)
				{
					cout<<"ERROR :: nonvaild instruction"<<endl;
					exit(100);
						
				}
			}
			else
			{
				splitInstructionString
				(*i.getInstruction(), instruction, label, indirect);
				
				if(instruction == "DEC")
				{
					code = tool.stringToInt(label, 10);
				}
				else if(instruction == "HEX")
				{
					code = tool.stringToInt(label, 16);
				}
				else if((code = getMRICode(instruction) == -1)
				{
					cout<<"ERROR :: nonvaild instruction"<<endl;
					exit(100);
				}
				labelAddress = 	findAddressByLabel(label);

				if(labelAddress == -1)
				{
					cout<<"ERROR :: no exist label"<<endl;
					exit(101);
				}
				code |= labelAddress;
				
				if(indirect == "I")
				{
					code |= 0x8000;
				}
				else if( indirect != "")
				{
					cout<<"ERROR :: no indirect Symbol"<<endl;
					exit(102);
				}	
					
			}

			temp = new BinaryInstruction(address, code);
			binaryInstruction->push_back(*temp);		
		}
		return binaryInstruction;
	}


	void
	InstrcutionParser::makeAddressTable
	()
	{
		//TODO
	}

	short
	InstructionParser::getMRICode
	(const string& label)
	{
		//TODO
	}

	short
	InstructionPaser::getNonMRICode
	(const string& label)
	{
		//TODO
	}
	
	int
	InstructionParser::splitInstructionString
	(const string& src,
	string& instruction,
	string& address,
	string& indirect)
	{
		//TODO
	}

	bool
	isSingleInstruction
	(const DisjunctInstruction& instruction)
	{
		//TODO
	}
}
