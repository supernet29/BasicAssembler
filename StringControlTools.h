#ifndef STRING_CONTROL_TOOLS_H
#define STRING_CONTROL_TOOLS_H

#include <string>

using namespace std;

namespace wc_string
{
	class StringControlTools
	{
		public:
		//delete connected space characters in string
		void deleteConnectedSpaceCharacter(string& str);

		//make string definite
		//consider _ as space character
		//make "____Insterest_a___" to "Interest_a"
		void cleanString(string& str);

	};
}

#endif
