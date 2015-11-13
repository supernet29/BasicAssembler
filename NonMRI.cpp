#include "NonMRI.h"

namespace wc_assembler
{
	NonMRI::NonMRI
	()
	:m_NonMRI_List(NULL)
	{
	}

	LabelCodeList*
	NonMRI::getNonMRIList
	()
	{
		if(m_NonMRI_List == NULL)
			makeNonMRIList();
		return m_NonMRI_List;
	}

	void
	NonMRI::makeNonMRIList
	()
	{
		m_NonMRI_List = new LabelCodeList();
		
		m_NonMRI_List->push_back(*(new LabelCode("CLA", (short)0x7800)));
		m_NonMRI_List->push_back(*(new LabelCode("CLE", (short)0x7400)));
		m_NonMRI_List->push_back(*(new LabelCode("CMA", (short)0x7200)));
		m_NonMRI_List->push_back(*(new LabelCode("CME", (short)0x7100)));
		m_NonMRI_List->push_back(*(new LabelCode("CIR", (short)0x7080)));
		m_NonMRI_List->push_back(*(new LabelCode("CIL", (short)0x7040)));
		m_NonMRI_List->push_back(*(new LabelCode("INC", (short)0x7020)));
		m_NonMRI_List->push_back(*(new LabelCode("SPA", (short)0x7010)));
		m_NonMRI_List->push_back(*(new LabelCode("SNA", (short)0x7008)));
		m_NonMRI_List->push_back(*(new LabelCode("SZA", (short)0x7004)));
		m_NonMRI_List->push_back(*(new LabelCode("SZE", (short)0x7002)));
		m_NonMRI_List->push_back(*(new LabelCode("HLT", (short)0x7001)));
		m_NonMRI_List->push_back(*(new LabelCode("INP", (short)0xF800)));
		m_NonMRI_List->push_back(*(new LabelCode("OUT", (short)0xF400)));
		m_NonMRI_List->push_back(*(new LabelCode("SKI", (short)0xF200)));
		m_NonMRI_List->push_back(*(new LabelCode("SKO", (short)0xF100)));
		m_NonMRI_List->push_back(*(new LabelCode("ION", (short)0xF080)));
		m_NonMRI_List->push_back(*(new LabelCode("IOF", (short)0xF040)));
	}
}
