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

BankClient::BankClient(const BankClient &obj):Person(obj.firstName, obj.lastName, obj.age, obj.isDead, obj.isMarried)
{
    currentAccount = obj.currentAccount;
    setServicePackageTitle(obj.servicePackageTitle);
    isActive = obj.isActive;
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
    if (servicePackageTitle != nullptr){
        delete [] servicePackageTitle;
    }
    servicePackageTitle = new char [strlen(value + 1)];
    strcpy(servicePackageTitle, value);
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
               << bankClient.isActive<<")" << endl;
}

std::istream& operator>>(std::istream &in, BankClient &bankClient)
{
    //Вроде должно работать, но надо бы переделать
    cout << "First name: ";
    in >> bankClient.firstName;
    cout << "Last name: ";
    in >> bankClient.lastName;
    cout << "Age:";
    in >> bankClient.age;
    cout << "Is dead (1 - true, 0 - false): ";
    in >> bankClient.isDead;
    cout << "Is married (1 - true, 0 - false): ";
    in >> bankClient.isMarried;
    cout << "Current account: ";
    in >> bankClient.currentAccount;
    cout << "Service package title: ";
    in >> bankClient.servicePackageTitle;
    cout << "Is active (1 - true, 0 - false): ";
    in >> bankClient.isActive;
    return in;
}
