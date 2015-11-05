#include <iostream>
#include "StringControlTools.h"

using namespace std;
using namespace wc_string;

void print(string& str)
{
	cout<<"=" <<str <<"=" <<endl;
}
int main()
{
	cout<<"============="<<endl;
	cout<<"Module Tester"<<endl;
	cout<<"============="<<endl;
		
	string str;
	string sub;
	StringControlTools sct;
	
	cout<<"input string"<<endl
		<<"string: ";
	getline(cin, str);

	cout<<"---------------------"<<endl;

	print(str);
	sct.splitStringBetweenCharacter(str, sub, ',');
	cout<<"---------------------"<<endl;
	print(str);
	print(sub);

	
	
	return 0;
}
