#include "PhoneBookEntry.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <unordered_set>


string PhoneBookEntry::toString() 
{	
	string s;
	s = firstName + lastName;
	cout << s << endl;
	return s;
}


