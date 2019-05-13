#ifndef PERSON_H
#define PERSON_H
#include "mystring.h"


class Person
{

private:
    MyString* firstName;
    MyString* lastName;
    unsigned short age;
    bool isDead;
    bool isMarried;
public:
    MyString *getFirstName() const;
    void setFirstName(MyString *value);
    MyString *getLastName() const;
    void setLastName(MyString *value);
    unsigned short getAge() const;
    void setAge(unsigned short value);
    bool getIsDead() const;
    void setIsDead(bool value);
    bool getIsMarried() const;
    void setIsMarried(bool value);
    void setAll(MyString *_firstName, MyString *_lastName,
                unsigned short _age, bool _isDead,
                const bool _isMarried);
    Person();
    Person(Person const &obj);
    Person(MyString *_firstName, MyString *_lastName,
           unsigned short _age, bool _isDead,
           bool _isMarried);
    ~Person();
    friend std::ostream& operator<<(std::ostream &out, const Person &person);
    friend std::istream& operator>>(std::istream &in, Person &person);

};

#endif // PERSON_H
