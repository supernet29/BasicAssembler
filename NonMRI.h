#ifndef NON_MRI_H
#define NON_MRI_H

#include "LabelCode.h"

using namespace std;

namespace wc_assembler
{
	class NonMRI
	{
		public:
		static
		LabelCodeList*
		getNonMRIList
		();	
		private:
		static LabelCodeList* m_NonMRI_List;
		
		static
		void
		makeNonMRIList
		();
	};
}

#endif
