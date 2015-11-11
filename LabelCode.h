#ifndef LABEL_CODE_H
#define LABEL_CODE_H

#include <string>
#include <list>

using namespace std;

namespace wc_assembler
{

	class LabelCode
	{
		public:
		LabelCode
		(const string& label, short code);
		
		const string&
		getLabel
		();
		
		short
		getCode
		();
		
		private:
		string m_Label;
		short m_Code;
	};
	
	typedef list<LabelCode> LabelCodeList;
	
	short
	findCodeByLabel
	(LabelCodeList& list, const string& label);

}

#endif
