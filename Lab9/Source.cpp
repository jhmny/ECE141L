#include <iostream>
#include <string>
#include <fstream>

#include "trieSTR.h"
#include "NodeR.h"
using namespace std;

int main() {
	TrieSTR<string> testTST;
	testTST.read("Text.txt");

	queue<string>* qs = new queue<string>;
	qs = testTST.keys();
	
	//cout << "Popping From Test Queue " << endl;
	
	//while (!qs->empty()) {
	// 	   string tempStr2;
	//	tempStr2 = qs->front();
	//	cout << tempStr2 << endl;
	//	qs->pop();
	//}

	/*string tempStr2;
	qs = testTST.keys("the");
	while (!qs->empty()) {
		tempStr2 = qs->front();
		cout << tempStr2 << endl;
		qs->pop();
	}*/



	cout << "======================================" << endl;
	cout << "Starting Thesaurus" << endl;
	TrieSTR<string> defTST;
	defTST.thesaurusRead("words.txt");
	defTST.thesaurusCall();
	return 0; 
}