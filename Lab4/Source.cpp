#include <iostream>
#include <stdlib.h>
#include <string>
#include <unordered_set>
#include <vector>

#include "PhoneBookEntry.h"
#include "HashTable.h"

using namespace std;


int main() {
	cout << "==========================================" << endl;
	cout << "Calling HashTable" << endl;

	HashTable<int> intTable(5);
	intTable.insert(1);


	for (int i = 0; i < 1000; i++) {
		intTable.insert(i);
	}

	cout << endl;
	cout << "Rehash sizing done, Start Find" << endl;
	cout << "==========================================" << endl;

	cout << PhoneBookEntry << endl;

	
	PhoneBookEntry p1;
	PhoneBookEntry p2;

	if (p1 == p2);
	return 0;
}