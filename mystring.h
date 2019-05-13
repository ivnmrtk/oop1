#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
using namespace std;

class MyString
{
private:
    char *str;
public:
    MyString();
    MyString(MyString const &obj);
    MyString(const char *_str);
    ~MyString();
    void set(const char *_str);
    const MyString& operator = (const MyString &_str);
    friend ostream& operator<<(ostream &out, const MyString &obj);
    friend istream& operator>>(istream &in, MyString &obj);
};

#endif // MYSTRING_H
