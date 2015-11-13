#include "MRI.h"

namespace wc_assembler
{
	
	MRI::MRI
	()
	:m_MRI_List(NULL)
	{
	}

	LabelCodeList*
	MRI::getMRIList
	()
	{
		if(m_MRI_List == NULL)
			makeMRIList();
		return m_MRI_List;
	}
	
	void
	MRI::makeMRIList
	()
	{
		m_MRI_List = new LabelCodeList();
		
		m_MRI_List->push_back(*(new LabelCode("AND", (short)0x0000)));
		m_MRI_List->push_back(*(new LabelCode("ADD", (short)0x1000)));
		m_MRI_List->push_back(*(new LabelCode("LDA", (short)0x2000)));
		m_MRI_List->push_back(*(new LabelCode("STA", (short)0x3000)));
		m_MRI_List->push_back(*(new LabelCode("BUN", (short)0x4000)));
		m_MRI_List->push_back(*(new LabelCode("BSA", (short)0x5000)));
		m_MRI_List->push_back(*(new LabelCode("ISZ", (short)0x6000)));
	}
}
