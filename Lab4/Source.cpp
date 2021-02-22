#include <iostream>
#include <stdlib.h>
#include <string>
#include <unordered_set>

#include "PhoneBookEntry.h"
#include "HashTable.h"

using namespace std;


int main() {
	cout << "==========================" << endl;
	//size_t v = 0;
	//string str_obj;
	//str_obj = "aqadsfasdf";
	//size_t key_hash = hash<int>()(v);
	//for (char c : str_obj)
	//	v = 31 * v + c;
	//cout << v << endl;


	cout << "==========================" << endl;
	cout << "Calling Hash Function" << endl;

	
	PhoneBookEntry p1("Jim","Bob","2123");
	size_t key2 = hash<string>()(p1.toString());
	cout << key2 << endl;

	cout << "==========================" << endl;
	cout << "Calling HashTable" << endl;

	HashTable<int> intTable(5);
	intTable.insert(1);
	intTable.insert(2);
	intTable.insert(3);
	
	list<int> storeList;
	storeList = intTable.find(1); 

	return 0;
}