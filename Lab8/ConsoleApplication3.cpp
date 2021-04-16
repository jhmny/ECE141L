// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Suffix
{
private:
    unsigned int indx;
    char* ptr;
    int length;
public:
    Suffix(int index, char* txt, int n)
    {
        indx = index;
        ptr = txt+=indx;
        length = n;
    }
    int get_indx()
    {
        return indx;
    }
    char* get_suffix()
    {
        return ptr;
    }
    void set_indx(int i)
    {
        indx = i;
    }
    void set_ptr(char* i)
    {
        ptr = i;
    }
    friend ostream& operator<<(ostream& cout, const Suffix &s) {
        char* p = s.ptr;
        for(int i = 0; i < s.length; i++)
        {
            cout << *p << " ";
            p++;
        }
        return cout; 
    }
    int l()
    {
        return length;
    }
};

class SuffixArray
{
private:
    char* txt;
    int n;
    vector<Suffix> suffixList;
public:
    SuffixArray(string text)
    {
        n = text.length();
        txt = new char[n];
        for (int i = 0; i < n; i++)
        {
            txt[i] = text[i];
            suffixList.push_back(Suffix(i, txt, n-i));
        }
    }
    int text_length() {
        return n;
    }
    Suffix operator[](const int i) const {
        return suffixList[i];
    }
    bool operator<(const SuffixArray that) const {
        if (this->txt[0] < that.txt[0]) return true;
        else return false;
    }
    bool operator>(const SuffixArray that) const {
        if (this->txt[0] > that.txt[0]) return true;
        else return false;
    }
};


class SuffixSort
{
private:
    SuffixArray suffixes;
    vector<unsigned int> matches;
    void sort() {

    }
public:
    SuffixSort(string text);
    void search(string key);
    vector<unsigned int> get_indices() {
        return matches;
    }
};

int main()
{
    SuffixArray sa = SuffixArray("thisisalineoftext");
    for (int i = 0; i < sa.text_length(); i++)
    {
        Suffix suffix = sa[i];
        cout << suffix << endl;
    }
    
}
