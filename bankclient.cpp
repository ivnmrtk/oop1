#include "bankclient.h"


BankClient::BankClient(): Person ()
{
    currentAccount = 0;
    servicePackageTitle[0] = '\0';
    isActive = false;
}

BankClient::BankClient(char *_firstName,
                       char *_lastName,
                       unsigned short _age,
                       bool _isDead,
                       bool _isMarried,
                       unsigned long _currentAccount,
                       char *_servicePackageTitle,
                       bool _isActive)
    :Person(_firstName, _lastName, _age, _isDead, _isMarried)
{
    currentAccount = _currentAccount;
    setServicePackageTitle(_servicePackageTitle);
    isActive = _isActive;
}

BankClient::BankClient(const BankClient &obj)
{
    setAll(obj.getFirstName(), obj.getLastName(),
           obj.getAge(), obj.getIsDead(),
           obj.getIsMarried(), obj.getCurrentAccount(),
           obj.getServicePackageTitle(), obj.getIsActive());
}

unsigned long BankClient::getCurrentAccount() const
{
    return currentAccount;
}

void BankClient::setCurrentAccount(unsigned long value)
{
    currentAccount = value;
}

char *BankClient::getServicePackageTitle() const
{
    return servicePackageTitle;
}

void BankClient::setServicePackageTitle(char *value)
{
    if (this->servicePackageTitle != nullptr){
        delete [] this->servicePackageTitle;
    }
    this->servicePackageTitle = new char [strlen(value + 1)];
    strcpy(this->servicePackageTitle, value);
}

bool BankClient::getIsActive() const
{
    return isActive;
}

void BankClient::setIsActive(bool value)
{
    isActive = value;
}

void BankClient::setAll(char *_firstName,
                        char *_lastName,
                        unsigned short _age,
                        bool _isDead,
                        bool _isMarried,
                        unsigned long _currentAccount,
                        char *_servicePackageTitle,
                        bool _isActive)
{
    Person::setAll(_firstName, _lastName, _age, _isDead, _isMarried);
    currentAccount = _currentAccount;
    setServicePackageTitle(_servicePackageTitle);
    isActive = _isActive;
}

BankClient::~BankClient()
{
    delete [] servicePackageTitle;
}

std::ostream& operator<<(std::ostream &out, const BankClient &bankClient)
{
    return out << "BankClient("
               << bankClient.firstName << ", "
               << bankClient.lastName << ", "
               << bankClient.age <<", "
               << bankClient.isDead <<", "
               << bankClient.isMarried<<", "
               << bankClient.currentAccount<<", "
               << bankClient.servicePackageTitle<<", "
               << bankClient.isActive<<")";
}

std::istream& operator>>(std::istream &in, BankClient &bankClient)
{
    //Вроде должно работать, но надо бы переделать
    in >> *bankClient.firstName;
    in >> *bankClient.lastName;
    in >> bankClient.age;
    in >> bankClient.isDead;
    in >> bankClient.isMarried;
    in >> bankClient.currentAccount;
    in >> bankClient.servicePackageTitle;
    in >> bankClient.isActive;
    return in;
}
