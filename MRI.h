#ifndef MRI_H
#define MRI_H

#include "LabelCode.h"

using namespace std;

namespace wc_assembler
{
	class MRI
	{
		public:
		static	
		LabelCodeList*
		getMRIList
		();
		
		private:		
		static LabelCodeList* m_MRI_List;

		static
		void
		makeMRIList
		();
	};
}

#endif
