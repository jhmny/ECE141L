#include "SuffixArray.h"
#include <ostream>

using namespace std;

SuffixArray::SuffixArray(string text)
{
    int n = text.length();
    suffixList = new vector<suffix>;
    txt = new char[n];
    for (int i = 0; i < n; i++) {
        txt[i] = text.at(i);
        suffixList->push_back(suffix(i, txt, n));
    }
}

unsigned int SuffixArray::getLength()
{   
    return n;
}

suffix SuffixArray::operator[](const int i) const {
    return suffixList->at(i);
}

bool SuffixArray::operator<(const SuffixArray) const
{
    return false;
}

bool SuffixArray::operator>(const SuffixArray) const
{
    return false;
}

ostream& operator<<(ostream& fin, suffix s)
{
    for(int i = 0; i < n; i++)
    {
        cout << &ptr[i] << " ";
    }
    return cout;
}
