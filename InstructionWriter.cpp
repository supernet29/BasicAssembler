#include "InstructionWriter.h"

namespace wc_assembler
{
	InstructionWriter::InstructionWriter
	(BinaryInstructionList * list, ofstream& stream)
	: m_InstructionList(list), m_OutputFile(stream)
	{
	}

	bool
	InstructionWriter::writeInstructionToFile
	()
	{
		if(!m_OutputFile.is_open())
		{
			cout<<"ERROR :: Output file open failed"<<endl;
			return false;
		}
		m_OutputFile<<"-------------------------"<<endl
				<<"Address(hex)|   Code(hex)"<<endl
				<<"-------------------------"<<hex<<endl;
		for(BinaryInstructionList::iterator i = m_InstructionList->begin();
			i != m_InstructionList->end(); i++)
		{
			m_OutputFile.width(12);
			m_OutputFile<<i->getAddress()<<"|";
			m_OutputFile.width(12);
			m_OutputFile<<i->getCode()<<endl;
		}
		m_OutputFile<<"-------------------------";
		
		return true;
	}
}
