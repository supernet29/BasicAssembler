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
		void 
		deleteConnectedSpaceCharacter
		(string& str);

		//make string definite
		//consider _ as space character
		//make "____Insterest_a___" to "Interest_a"
		void 
		cleanString
		(string& str);
		
		//split src string between a character
		//head part is stored in des
		//tail part is stored in src
		//ch character will be ignored
		bool 
		splitStringBetweenCharacter
		(string& src, string& des, char ch);

		private:
		
		int
		findCharacterPosition
		(const string& src, char ch);

	};
}

#endif
