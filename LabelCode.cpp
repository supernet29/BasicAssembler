#include "LabelCode.h"

namespace wc_assembler
{

	LabelCode::LabelCode
	(const string& label, short code)
	:m_Label(label), m_Code(code)
	{
	}
	
	const string&
	LabelCode::getLabel
	()
	{
		return m_Label;
	}
	
	short
	LabelCode::getCode
	()
	{
		return m_Code;
	}

	short
	findCodeByLabel
	(LabelCodeList& lst, const string& label)
	{
		LabelCodeList::iterator it;
		for(it = lst.begin(); it != lst.end(); it++)
		{
			if(it->getLabel() == label)
				return it->getCode();
		}
		return -1;
	}
}
