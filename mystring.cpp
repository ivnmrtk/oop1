#include "mystring.h"
#include <string.h>

MyString::MyString()
{
    this->str = new char;
    this->str[0] = '\0';
}

MyString::MyString(MyString const &obj)
{
    set(obj.str);
}

MyString::MyString(const char *_str)
{
    set(_str);
}

MyString::~MyString()
{
    delete [] str;
}

void MyString::set(const char *_str)
{
    if (this->str != nullptr){
        delete [] this->str;
    }
    this->str = new char [strlen(_str + 1)];
    strcpy(this->str, _str);
}

const MyString &MyString::operator =(const MyString &obj)
{
    if (&obj == this) {
        return *this;
    }

    if (str != nullptr) {
        delete []str;
    }

    set(obj.str);

    return *this;
}

ostream& operator<<(ostream &out, const MyString &obj)
{
    return out << obj.str;
}

istream& operator>>(istream &in, MyString &obj)
{
    const unsigned char length = 255;
    char buf[length];
    in.get(buf, length);
    delete []obj.str;
    obj.set(buf);
    return in;
}
