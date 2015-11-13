#ifndef NON_MRI_H
#define NON_MRI_H

#include "LabelCode.h"

using namespace std;

namespace wc_assembler
{
	class NonMRI
	{
		public:
		NonMRI
		();

		LabelCodeList*
		getNonMRIList
		();	
		private:
		LabelCodeList* m_NonMRI_List;
		
		void
		makeNonMRIList
		();
	};
}

#endif
