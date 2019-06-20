#include "person.h"

char *Person::getFirstName() const
{
    return firstName;
}

void Person::setFirstName(char *value)
{
    if (firstName != nullptr){
        delete [] firstName;
    }
    firstName = new char [strlen(value + 1)];
    strcpy(firstName, value);

}

char *Person::getLastName() const
{
    return lastName;
}

void Person::setLastName(char *value)
{
    if (lastName != nullptr){
        delete [] lastName;
    }
    lastName = new char [strlen(value + 1)];
    strcpy(lastName, value);
}

unsigned short Person::getAge() const
{
    return age;
}

void Person::setAge(unsigned short value)
{
    age = value;
}

bool Person::getIsDead() const
{
    return isDead;
}

void Person::setIsDead(bool value)
{
    isDead = value;
}

bool Person::getIsMarried() const
{
    return isMarried;
}

void Person::setIsMarried(bool value)
{
    isMarried = value;
}

void Person::setAll(char *_firstName, char *_lastName, unsigned short _age, bool _isDead, bool _isMarried)
{
    setFirstName(_firstName);
    setLastName(_lastName);
    age = _age;
    isDead = _isDead;
    isMarried = _isMarried;

}

Person::Person()
{
    firstName = new char;
    firstName[0] = '\0';
    lastName = new char;
    lastName[0] = '\0';
    age = 0;
    isDead = false;
    isMarried = false;
}

Person::Person(const Person &obj)
{
    /*
    firstName = obj.getFirstName();
    lastName = obj.getLastName();
    age = obj.getAge();
    isDead = obj.getIsDead();
    isMarried = obj.getIsMarried();
    */
    setAll(obj.getFirstName(), obj.getLastName(), obj.getAge(), obj.getIsDead(), obj.getIsMarried());
}

Person::Person(char *_firstName, char *_lastName,
               const unsigned short _age, const bool _isDead,
               const bool _isMarried)
{
    /*
    firstName = new MyString(_firstName);
    lastName = new MyString(_lastName);
    age = _age;
    isDead = _isDead;
    isMarried = _isMarried;
    */
    setAll(_firstName, _lastName, _age, _isDead, _isMarried);
}

const Person &Person::operator=(const Person &obj)
{
    if (this == &obj){
        return *this;
    }
    if (firstName != nullptr){
        delete [] firstName;
    }
    if (lastName != nullptr){
        delete [] lastName;
    }
    setFirstName(obj.getFirstName());
    setLastName(obj.getLastName());
    age = obj.getAge();
    isDead = obj.getIsDead();
    isMarried = obj.getIsMarried();
    return *this;
}

Person::~Person()
{
    delete [] firstName;
    delete [] lastName;
}

std::ostream& operator<<(std::ostream &out, const Person &person)
{
    return out << "Person("
               << person.firstName << ", "
               << person.lastName << ", "
               << person.age <<", "
               << person.isDead <<", "
               << person.isMarried<<")" << endl;
}

std::istream& operator>>(std::istream &in, Person &person)
{
    cout << "First name:";
    char bufFirstName[255];
    in >> bufFirstName;
    person.setFirstName(bufFirstName);

    cout << "Last name:";
    char bufLastName[255];
    in >> bufLastName;
    person.setLastName(bufLastName);

    cout << "Age:";
    in >> person.age;

    cout << "Is dead (1 - true, 0 - false):";
    in >> person.isDead;

    cout << "Is married (1 - true, 0 - false):";
    in >> person.isMarried;
    return in;
}
