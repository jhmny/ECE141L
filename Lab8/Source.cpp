#include <iostream>
#include <string>

#include "SuffixArray.h"
#include "SuffixSort.h"

using namespace std;
int main() {
	cout << "=============================================" << endl;
	cout << "Testing Suffix Array" << endl;

	cout << "Testing Constructor" << endl;
	SuffixArray testSA("Bannana");
	cout << "Constructor Sucessful" << endl;

	cout << "End Suffix Array" << endl;
	cout << "=============================================" << endl;
	cout << "Testing Suffix Sort" << endl;

	SuffixSort testSS();


	cout << "=============================================" << endl;
	cout << "Testing Suffix Sort" << endl;
	return 0;
}