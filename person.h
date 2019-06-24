#ifndef PERSON_H
#define PERSON_H
#include "mystring.h"
#include <string.h>

using namespace std;

class Person
{

protected:
    char* firstName;
    char* lastName;
    unsigned short age;
    bool isDead;
    bool isMarried;
public:
    char *getFirstName() const;
    void setFirstName(char *value);
    char *getLastName() const;
    void setLastName(char *value);
    unsigned short getAge() const;
    void setAge(unsigned short value);
    bool getIsDead() const;
    void setIsDead(bool value);
    bool getIsMarried() const;
    void setIsMarried(bool value);
    void setAll(char *_firstName, char *_lastName,
                unsigned short _age, bool _isDead,
                const bool _isMarried);
    Person();
    Person(Person const &obj);
    Person(char *_firstName, char *_lastName,
           unsigned short _age, bool _isDead,
           bool _isMarried);
    const Person &operator=(const Person &aStr);
    virtual ~Person();
    friend std::ostream& operator<<(std::ostream &out, const Person &person);
    friend std::istream& operator>>(std::istream &in, Person &person);
    virtual void toString(std::ostream &out) const;
};

#endif // PERSON_H
