#include <iostream>	
#include <stdlib.h>	
#include <string>	
#include <unordered_set>	
#include <vector>	
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


	PhoneBookEntry p1("Jim", "Bob", "2123");
	size_t key1 = hash<string>()(p1.toString());
	cout << key1 << endl;

	PhoneBookEntry p2("Swaglord", "DudeMan", "512358");
	size_t key2 = hash<string>()(p2.toString());
	cout << key2 << endl;

	PhoneBookEntry p3("QPC", "Pipes", "123");
	size_t key3 = hash<string>()(p3.toString());
	cout << key3 << endl;

	cout << "======================================" << endl;
	cout << "Calling HashTable" << endl;


	HashTable<int> intTable(5);	
	intTable.insert(1);	


	intTable.insert(2);
	intTable.insert(3);
	intTable.insert(3);
	intTable.insert(3);
	intTable.insert(2);
	intTable.insert(1);
	intTable.insert(3);
	intTable.insert(3);
	intTable.insert(3);
	intTable.insert(3);
	intTable.insert(3);
	intTable.insert(5);


	for (int i = 4; i < 1000; i++) {
			intTable.insert(i);			
	}

	cout << endl;
	cout << "Rehash sizing done, Start Find" << endl;	
	cout << "======================================" << endl;
	cout << "Try to find 1" << endl;
	vector<int> storeVec;
	storeVec = intTable.find(1);
	cout << storeVec.at(0) << endl;
	intTable.remove(999);
	storeVec = intTable.find(999);
	for (int i = 0; i < storeVec.size(); i++) {
		cout << "found it" << endl;
		cout << storeVec[i] << " ";
	}
	cout << endl;


	HashTable<PhoneBookEntry> phoneTable(10);
	phoneTable.insert(p1);
	phoneTable.insert(p2);
	phoneTable.insert(p3);
	phoneTable.insert(p2);
	phoneTable.insert(p3);
	phoneTable.insert(p2);
	phoneTable.insert(p3);
	phoneTable.insert(p2);
	phoneTable.insert(p3);
	phoneTable.insert(p2);
	phoneTable.insert(p3);


	cout << "Testing Remove " << endl;
	phoneTable.remove(p2);
	cout << "Remove Done " << endl;
	vector<PhoneBookEntry> phoneVec;
	phoneVec = phoneTable.find(p1);
	cout << "Test Print " << endl;
	phoneVec.at(0).toString();
	return 0;
}