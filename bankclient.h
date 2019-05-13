#ifndef BANKCLIENT_H
#define BANKCLIENT_H

#include "person.h"


class BankClient : Person
{
private:
    unsigned long currentAccount;
    MyString *servicePackageTitle;
    bool isActive;

public:
    BankClient();
    BankClient(MyString *_firstName,
               MyString *_lastName,
               unsigned short _age,
               bool _isDead,
               bool _isMarried,
               unsigned long _currentAccount,
               MyString *_servicePackageTitle,
               bool _isActive);

};

#endif // BANKCLIENT_H
