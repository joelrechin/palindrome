#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <cctype>      // for toupper()
#include <string>
#include <string.h>

/*
Joel Rechin
CS 10b
4/30/19
Dave Harden
Assignment 13
MyString - MyString.h

The MyString class stores char values and a sequence of char values in a dynamically
allocated array. In summary, it provides functionality for all relational operators, bracket
operator, insertion and extraction operators, a read function, a concatenation
function, a concatenation/assignment operator, and the = assignment operator.
The following functions are available:

MyString();
    post: A default constructor. The calling object has been created as an empty
    MyString object.

MyString(const char *inString);
    post: A constructor with a C-string argument. The calling object has been created
    and initialized to the char parameter inString.
MyString(const MyString& right);
    post: A copy constructor. A copy of the calling object has been created and
    initialized to the MyString parameter.

~MyString();
    post: Deallocates any memory on the heap that the object is pointing to.

friend std::ostream& operator<<(std::ostream& out, const MyString& printMe);
    post: The insertion operator. This function overloads the insertion operator
    for the MyString class.

friend std::istream& operator>>(std::istream& in, MyString& target);
    post: The extraction operator. This function overloads the extraction operator
    for the MyString class.

MyString operator=(const MyString& right);
    post: The assignment operator. This function overloads the assignment operator
    for the MyString class.

char operator[](int index) const;
    post: This function overloads the bracket operator for a const MyString class.

char& operator[](int index);
    post: This function overloads the bracket operator for a MyString class.

friend bool operator<(const MyString& left, const MyString& right);
    post: This function overloads the relational operator < for the MyString class.

friend bool operator<=(const MyString& left, const MyString& right);
    post: This function overloads the relational operator <= for the MyString class.

friend bool operator>(const MyString& left, const MyString& right);
    post: This function overloads the relational operator > for the MyString class.

friend bool operator>=(const MyString& left, const MyString& right);
    post: This function overloads the relational operator >= for the MyString class.

friend bool operator==(const MyString& left, const MyString& right);
    post: This function overloads the relational operator == for the MyString class.

friend bool operator!=(const MyString& left, const MyString& right);
    post: This function overloads the relational operator != for the MyString class.

int length()const;
    post: This function returns the char length of the calling object.

void read(std::istream& in, char delim);
    post: This function allows the client the specify the delimiting character at which
    to read and assigns this to the calling object.

friend MyString operator+(const MyString& left, const MyString& right);
    post: This function overloads the binary operator + for the MyString class. Allows
    for concatenation.

MyString operator+=(const MyString& right);
    post: This function overloads the shorthand operator += to combine concatenation
    and assignment.

*/
namespace cs_mystring
{
class MyString
{
    public:
        static const int MAX_INPUT_SIZE = 127;
        MyString();
        MyString(const char *inString);
        MyString(const MyString& right);
        ~MyString();
        friend std::ostream& operator<<(std::ostream& out, const MyString& printMe);
        friend std::istream& operator>>(std::istream& in, MyString& target);
        MyString operator=(const MyString& right);
        char operator[](int index) const;
        char& operator[](int index);
        friend bool operator<(const MyString& left,
                            const MyString& right);
        friend bool operator<=(const MyString& left,
                            const MyString& right);
        friend bool operator>(const MyString& left,
                            const MyString& right);
        friend bool operator>=(const MyString& left,
                            const MyString& right);
        friend bool operator==(const MyString& left,
                            const MyString& right);
        friend bool operator!=(const MyString& left,
                            const MyString& right);
        int length()const;
        void read(std::istream& in, char delim);
        friend MyString operator+(const MyString& left,
                          const MyString& right);
        MyString operator+=(const MyString& right);
    private:
        char *myString;
};
}

#endif // MYSTRING_H

/*
----- Testing basic String creation & printing
string [0] = Wow
string [1] = C++ is neat!
string [2] =
string [3] = a-z

----- Now reading MyStrings from file

----- first, word by word
Read string = The
Read string = first
Read string = time
Read string = we
Read string = will
Read string = read
Read string = individual
Read string = words,
Read string = next
Read string = we
Read string = read
Read string = whole
Read string = lines

----- now, line by line
Read string = The  first  time  we  will
Read string =     read individual words, next
Read string = we read whole lines

----- Testing access to characters (using const)
Whole string is abcdefghijklmnopqsrtuvwxyz
now char by char: abcdefghijklmnopqsrtuvwxyz
----- Testing access to characters (using non-const)
Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

----- Testing relational operators between MyStrings
Comparing app to apple
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing apple to
        Is left < right? false
        Is left <= right? false
        Is left > right? true
        Is left >= right? true
        Does left == right? false
        Does left != right ? true
Comparing  to Banana
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing Banana to Banana
        Is left < right? false
        Is left <= right? true
        Is left > right? false
        Is left >= right? true
        Does left == right? true
        Does left != right ? false

----- Testing relations between MyStrings and char *
Comparing he to hello
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing why to wackity
        Is left < right? false
        Is left <= right? false
        Is left > right? true
        Is left >= right? true
        Does left == right? false
        Does left != right ? true

----- Testing concatentation on MyStrings
outrageous + milk = outrageousmilk
milk +  = milk
 + cow = cow
cow + bell = cowbell

----- Testing concatentation between MyString and char *
abcde + XYZ = abcdeXYZ
XYZ + abcde = XYZabcde

----- Testing shorthand concat/assign on MyStrings
who += what = whowhatandwhowhat
what += WHEN = whatWHENandwhatWHEN
WHEN += Where = WHENWhereandWHENWhere
Where += why = WherewhyandWherewhy

----- Testing shorthand concat/assign using char *
I love  += programming = I love programming

----- Testing copy constructor and operator= on MyStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return MyStrings by value and ref
after calling Append, sum is BinkyBoo
val is winky
after assign,  val is BinkyBoo

Process returned 0 (0x0)   execution time : 0.168 s
Press any key to continue.
*/



