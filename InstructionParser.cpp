#include "InstructionParser.h"

namespace wc_assembler
{
	InstructionParser::InstructionParser
	(DisjunctInstructionList* instructionList,
	LabelCodeList* MRI_Code,
	LabelCodeList* nonMRI_Code)
	:m_MRI_Code(MRI_Code), m_nonMRI_Code(nonMRI_Code),
	m_Instructions(instructionList)
	{
	}

	InstructionParser::~InstructionParser
	()
	{
		delete m_Instructions;
	}

	BinaryInstructionList*
	InstructionParser::parseInstructions
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

		for(DisjunctInstructionList::iterator i = m_Instructions->begin();
		i != m_Instructions->end(); i++)
		{
			address = (short)i->getAddress();

			if(isSingleInstruction(*i))
			{
				instruction = i->getInstruction();

				code = getNonMRICode(instruction);
				if(code == -1)
				{
					cout<<"ERROR :: nonvaild instruction"<<endl;
					cout<<"ERROR LINE :: "<<i->getLineNumber()<<endl;
					exit(100);
						
				}
			}
			else
			{
				splitInstructionString
				(i->getInstruction(), instruction, label, indirect);
				
				if(instruction == "DEC")
				{
					code = atoi(label.c_str());
				}
				else if(instruction == "HEX")
				{
					code = tool.stringToInt(label, 16);
				}
				else if((code = getMRICode(instruction)) == -1)
				{
					cout<<"ERROR :: nonvaild instruction"<<endl;
					cout<<"ERROR LINE :: "<<i->getLineNumber()<<endl;
					exit(100);
				}
				else
				{
					labelAddress = 	findAddressByLabel(label);

					if(labelAddress == -1)
					{
						cout<<"ERROR :: no exist label"<<endl;
						cout<<"ERROR LABEL :: "<<label<<endl;
						cout<<"ERROR LINE :: "<<i->getLineNumber()<<endl;
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
						cout<<"ERROR LINE :: "<<i->getLineNumber()<<endl;
						exit(102);
					}	
				}
					
			}

			temp = new BinaryInstruction(address, code);
			binaryInstruction->push_back(*temp);		
		}
		return binaryInstruction;
	}


	void
	InstructionParser::makeAddressTable
	()
	{
		DisjunctInstructionList::iterator it;
		LabelCode* temp;
		for(it = m_Instructions->begin(); it != m_Instructions->end(); it++)
		{
			if(it->getLabel() != "")
			{
				if(findAddressByLabel(it->getLabel()) != -1)
				{
					cout<<"ERROR :: Repeated symbol address"<<endl;
					cout<<"ERROR LINE :: "<<it->getLineNumber()<<endl; 
					exit(103);
				}
				temp = new LabelCode(it->getLabel(), it->getAddress());
				m_AddressList.push_back(*temp);
			}
		}	
	}

	short
	InstructionParser::getMRICode
	(const string& label)
	{
		return findCodeByLabel(*m_MRI_Code, label);
	}

	short
	InstructionParser::getNonMRICode
	(const string& label)
	{
		return findCodeByLabel(*m_nonMRI_Code, label);
	}

	short
	InstructionParser::findAddressByLabel
	(const string& label)
	{
		return findCodeByLabel(m_AddressList, label);
	}
	
	int
	InstructionParser::splitInstructionString
	(const string& src,
	string& instruction,
	string& address,
	string& indirect)
	{
		string temp = src;
		unsigned int spaceNumber = tool.countCharacter(temp,' ');

		tool.splitStringBetweenCharacter(temp, instruction, ' ');
		if(spaceNumber == 1)
		{
			address = temp;
			indirect = "";
			return 1;
		}
		else if(spaceNumber == 2)
		{
			tool.splitStringBetweenCharacter(temp, address, ' ');
			indirect = temp;
			return 2;
		}
		else
		{
			return -1;
		}
	}

	bool
	InstructionParser::isSingleInstruction
	(DisjunctInstruction& instruction)
	{
		string temp = instruction.getInstruction();
		unsigned int spaceNumber = tool.countCharacter(temp, ' ');
		if(spaceNumber == 0)
			return true;
		else
			return false;
	}
}
