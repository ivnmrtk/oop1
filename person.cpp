#include "person.h"



MyString *Person::getFirstName() const
{
    return firstName;
}

void Person::setFirstName(MyString *value)
{
    firstName = value;
}

MyString *Person::getLastName() const
{
    return lastName;
}

void Person::setLastName(MyString *value)
{
    lastName = value;
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

void Person::setAll(MyString *_firstName, MyString *_lastName, unsigned short _age, bool _isDead, bool _isMarried)
{
    firstName = _firstName;
    lastName = _lastName;
    age = _age;
    isDead = _isDead;
    isMarried = _isMarried;

}

Person::Person()
{
    firstName = new MyString("\0");
    lastName = new MyString("\0");
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

Person::Person(MyString *_firstName, MyString *_lastName,
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
               << person.isMarried<<")";
}

std::istream& operator>>(std::istream &in, Person &person)
{
    //Вроде должно работать, но надо бы переделать
    in >> *person.firstName;
    in >> *person.lastName;
    in >> person.age;
    in >> person.isDead;
    in >> person.isMarried;
    return in;
}
