/*
Joel Rechin
CS 10b
4/30/19
Dave Harden
Assignment 13
MyString - MyString.cpp
*/

#include "Mystring.h" //Needed for Fraction class
#include <iostream>
#include <cassert>
#include <cctype>      // for toupper()
#include <string>
#include <string.h>
#pragma warning(disable:4996)

/*

    Class Invariant: a MyString object has one char array pointer that is dynamically allocated.

*/


using namespace std;
namespace cs_mystring
{
MyString::MyString()
{
    myString = new char[1];
    strcpy(myString, "");
}





MyString::MyString(const char *inString)
{
    myString = new char[strlen(inString) + 1];
    strcpy(myString, inString);
}






MyString::MyString(const MyString& right)
{
    myString = new char[strlen(right.myString) + 1];
    strcpy(myString, right.myString);
}






MyString::~MyString()
{
    delete [] myString;
}







ostream& operator<<(ostream& out, const MyString& source)
{
    out << source.myString;
    return out;
}






istream& operator>>(istream& in, MyString& target)
{
    /*while(isspace(in.peek()))
    {
        in.ignore();
    }*/
    char temp[MyString::MAX_INPUT_SIZE +1];
    in >> temp;
    delete [] target.myString;
    target.myString = new char[strlen(temp)+1];
    strcpy(target.myString, temp);
    return in;
}






void MyString::read(std::istream& in, char delim)
{
    char temp[MyString::MAX_INPUT_SIZE +1];
    in.getline(temp, MyString::MAX_INPUT_SIZE, delim);
    delete [] myString;
    myString = new char[strlen(temp)+1];
    strcpy(myString, temp);
}






MyString MyString::operator=(const MyString& right)
{
    if(this != &right)
    {
        delete [] myString;
        myString = new char[strlen(right.myString) +1];
        strcpy(myString, right.myString);
    }
    return *this;
}






MyString MyString::operator+=(const MyString& right)
{
    *this = *this + right;
    return *this;
}






MyString operator+(const MyString& left, const MyString& right)
{
    MyString temp;
    delete temp.myString;
    temp.myString = new char[strlen(left.myString) + strlen(right.myString)+1];
    strcpy(temp.myString, left.myString);
    strcat(temp.myString, right.myString);
    return temp;
}






char MyString::operator[](int index) const
{
    assert(index >= 0 && index < strlen(myString));
    return myString[index];
}






char& MyString::operator[](int index)
{
    assert(index >= 0 && index < strlen(myString));
    return myString[index];
}






bool operator<(const MyString& left, const MyString& right)
{
    int compare = strcmp(left.myString, right.myString);
    return compare < 0;
}






bool operator<=(const MyString& left, const MyString& right)
{
    int compare = strcmp(left.myString, right.myString);
    return (compare < 0 || compare == 0);
}






bool operator>(const MyString& left, const MyString& right)
{
    int compare = strcmp(left.myString, right.myString);
    return compare > 0;
}






bool operator>=(const MyString& left, const MyString& right)
{
    int compare = strcmp(left.myString, right.myString);
    return (compare > 0 || compare == 0);
}






bool operator==(const MyString& left, const MyString& right)
{
    int compare = strcmp(left.myString, right.myString);
    return compare == 0;
}






bool operator!=(const MyString& left, const MyString& right)
{
    int compare = strcmp(left.myString, right.myString);
    return compare != 0;
}






int MyString::length() const
{
    return strlen(myString);
};
}
