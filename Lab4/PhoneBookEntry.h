#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <unordered_set>

using namespace std;

class PhoneBookEntry
{
private:
	string firstName;
	string lastName;
	string phoneName;
public:
	PhoneBookEntry(string f1, string l1, string p1)
	{
		firstName = f1;
		lastName = l1;
		phoneName = p1;
	}
	~PhoneBookEntry() {};
	void changePhoneNum(string num)
	{
		phoneName = num;
	}
	string toString() const; 
	string toString();
	bool operator==(const PhoneBookEntry that) const {
		if((this->firstName.compare(that.firstName) && this->lastName.compare(that.lastName) && this->phoneName.compare(that.phoneName)) == 0)
			return true;
		else
		return false;
	}
	bool operator!=(const PhoneBookEntry that) const {
		if (*this == that)
			return false;
		else
			return true;
	}
};