/*

5/12/19
Joel Rechin
CS 10b
Dave Harden
Assignment 15.2

*/

#include <iostream>
#include <cctype>
#include "MyString.h"

using namespace std;
using namespace cs_mystring;

void readStrings(MyString& words, int& upper);
int getBounds(MyString& words, int& upper);
bool isAPalindrome(MyString& words, int lower, int upper);

int main()
{
    int lowerBound = 0, upperBound;
    MyString words;

    readStrings(words, upperBound);

    do{

    if(isAPalindrome(words, lowerBound, upperBound) == true)
        cout << words << " is a palindrome." << endl;
    else
        cout << words << " is not a palindrome." << endl;

    readStrings(words, upperBound);

    }while(words != "quit");
}






//Function gets a MyString from the user.
void readStrings(MyString& words, int& upper)
{
    cout << "Enter a string: ";
    words.read(cin, '\n');
    getBounds(words, upper);
}






//Function returns the upper bound, based on the MyString size.
int getBounds(MyString& words, int& upper)
{
    return upper = words.length()-1;
}






//Function returns a bool determined by if MyString is a palindrome. Ignores
//white space and punctuation marks, and is not case sensitive.
bool isAPalindrome(MyString& words, int lower, int upper)
{
    if(lower >= upper)
        return true;
    if(toupper(words[lower]) != toupper(words[upper]))
    {
        if(ispunct(words[lower]) || isspace(words[lower]))
            return isAPalindrome(words, lower+1, upper);
        if(ispunct(words[upper]) || isspace(words[upper]))
            return isAPalindrome(words, lower, upper-1);
        else
            return false;
    }

    return isAPalindrome(words, lower+1, upper-1);
}

/*
Enter a string: Able was I, ere I saw Elba
Able was I, ere I saw Elba is a palindrome.
Enter a string: peanut butter
peanut butter is not a palindrome.
Enter a string: quit

Process returned 0 (0x0)   execution time : 30.888 s
Press any key to continue.
*/
