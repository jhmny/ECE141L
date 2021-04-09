// Lab 10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Boyer_Moore
{
private:
    string pat;
    int R;
    int *right;
public:
    Boyer_Moore() {
    }
    Boyer_Moore(string pattern, int R) {
        pat = pattern;
        this->R = R;
        right = new int[R];
        for (int c = 0; c < R; c++)
            right[c] = -1;
        for (int j = 0; j < pat.length(); j++)
            right[pat.at(j)] = j;
    }
    void setPattern(string pattern) {
        pat = pattern;
        for (int c = 0; c < R; c++)
            right[c] = -1;
        for (int j = 0; j < pat.length(); j++)
            right[pat.at(j)] = j;
    }
    int search(string txt) {
        int N = txt.length();
        int M = pat.length();
        int skip;
        for (int i = 0; i <= N - M; i += skip)
        {
            skip = 0;
            for (int j = M - 1; j >= 0; j--)
            {
                if (pat.at(j) != txt.at(i + j)) {
                    skip = max(1, j - right[txt.at(i + j)]);
                    break;
                }
            }
            if (skip == 0) return i;
        }
        return -1;
    }
};

class RabinKarp {
private:
    string pattern;
    int patHash;
    int patLen;
    int modulus;
    int R;
    int rm;
    long hash(string key) {
        long hashValue = 0;
        for (int i = 0; i < patLen; i++)
            hashValue = (hashValue * R + key.at(i)) % modulus;
        return hashValue;
    }
public:
    RabinKarp(string pattern, int modulus) {
        this->pattern = pattern;
        R = 256;
        this->modulus = modulus;
        patLen = pattern.length();
        rm = 1;
        for (int i = 1; i <= patLen - 1; i++)
            rm = (R * rm) % modulus;
        patHash = hash(pattern);
    }
    void setPattern(string pattern) {
        this->pattern = pattern;
        patLen = pattern.length();
        rm = 1;
        for (int i = 1; i <= patLen - 1; i++)
            rm = (R * rm) % modulus;
        patHash = hash(pattern);
    }
    int LVsearch(string txt) {
        int N = txt.length();
        int txtHash = hash(txt);
        if (patHash == txtHash || pattern == txt.substr(0,patLen)) return 0;
        for (int i = patLen; i < N; i++)
        {
            txtHash = (txtHash + modulus - rm * txt.at(i - patLen) % modulus) % modulus;
            txtHash = (txtHash * R + txt.at(i)) % modulus;
            if (patHash == txtHash && pattern == txt.substr(i-patLen+1, patLen)) return i - patLen + 1;
        }
        return -1;
    }
    int* LVsearchM(string pat[], string txt, int n) {
        int* idx = new int[n];
        for (int j = 0; j < n; j++)
        {
            setPattern(pat[j]);
            int N = txt.length();
            int txtHash = hash(txt);
            if (patHash == txtHash || pattern == txt.substr(0, patLen)) return 0;
            for (int i = patLen; i < N; i++)
            {
                txtHash = (txtHash + modulus - rm * txt.at(i - patLen) % modulus) % modulus;
                txtHash = (txtHash * R + txt.at(i)) % modulus;
                if (patHash == txtHash && pattern == txt.substr(i - patLen + 1, patLen)) {
                    idx[j] = i - patLen + 1;
                    break;
                }
            }
            if (idx[j] < 0) idx[j] = -1;
        }
        return idx;
    }
    int MCsearch(string txt) {
        int N = txt.length();
        int txtHash = hash(txt);
        if (patHash == txtHash) return 0;
        txtHash = hash(txt);
        for (int i = patLen; i < N; i++)
        {
            txtHash = (txtHash + modulus - rm * txt.at(i - patLen) % modulus) % modulus;
            txtHash = (txtHash * R + txt.at(i)) % modulus;
            if (patHash == txtHash) return i - patLen + 1;
        }
        return -1;
    }
};
int main()
{
    Boyer_Moore s = Boyer_Moore("the", 256);
    RabinKarp t = RabinKarp("the", 937);
    ifstream myfile("Text.txt");
    string txt;
    myfile >> txt;
    string w;
    while (myfile >> w) {
        txt += " " + w;
    }
    cout << "Boyer Moore Test: " << endl;
    cout << "Search for 'the' " << s.search(txt) << endl;
    s.setPattern("expected");
    cout << "Search for 'expected' " << s.search(txt) << endl;
    s.setPattern("wearing");
    cout << "Search for 'wearing' " << s.search(txt) << endl;
    s.setPattern("fresnostate");
    cout << "Search for 'fresnostate' " << s.search(txt) << endl << endl;
    cout << "RabinKarp Test: " << endl;
    cout << "Search for 'the' " << t.LVsearch(txt) << endl;
    t.setPattern("expected");
    cout << "Search for 'expected' " << t.LVsearch(txt) << endl;
    t.setPattern("wearing");
    cout << "Search for 'wearing' " << t.LVsearch(txt) << endl;
    t.setPattern("fresnostate");
    cout << "Search for 'fresnostate' " << t.LVsearch(txt) << endl << endl;

    cout << "LasVegas Multiple Pattern Search:" << endl;
    string set1[] = { "the","expected" };
    int n = 2;
    int* idx = new int[n];
    cout << "Search for 'the' and 'expected' " << endl;
    idx = t.LVsearchM(set1, txt, n);
    for (int i = 0; i < n; i++) cout << idx[i] << endl;
    cout << endl;
    string set2[] = { "expected" };
    n = 1;
    cout << "Search for 'expected' " << endl;
    idx = t.LVsearchM(set2, txt, n);
    for (int i = 0; i < n; i++) cout << idx[i] << endl;
    cout << endl;
    string set3[] = { "fresnostate","expected" };
    n = 2;
    cout << "Search for 'fresnostate' and 'expected' " << endl;
    idx = t.LVsearchM(set3, txt, n);
    for (int i = 0; i < n; i++) cout << idx[i] << endl;
    cout << endl;
    string set4[] = { "fresnostate" ,"lcoe" };
    cout << "Search for 'fresnostate' and 'lcoe' " << endl;
    idx = t.LVsearchM(set4, txt, n);
    for (int i = 0; i < n; i++) cout << idx[i] << endl;
    cout << endl;
    cout << "'-1' indicates not found." << endl;
}
