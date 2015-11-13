#ifndef MRI_H
#define MRI_H

#include "LabelCode.h"

using namespace std;

namespace wc_assembler
{
	class MRI
	{
		public:
		MRI();

		LabelCodeList*
		getMRIList
		();
		
		private:		
		LabelCodeList* m_MRI_List;

		void
		makeMRIList
		();
	};
}

#endif
