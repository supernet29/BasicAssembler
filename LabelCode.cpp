#include "LabelCode.h"

namespace wc_assembler
{

	LabelCode::LabelCode
	(const string& label, short code)
	:m_Label(label); m_Code(code)
	{
	}
	
	const string&
	LabelCode::getLabe
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
}
