#include "bankclient.h"

BankClient::BankClient(MyString *_firstName,
                       MyString *_lastName,
                       unsigned short _age,
                       bool _isDead,
                       bool _isMarried,
                       unsigned long _currentAccount,
                       MyString *_servicePackageTitle,
                       bool _isActive)
    :Person(_firstName, _lastName, _age, _isDead, _isMarried)
{
    currentAccount = _currentAccount;
    servicePackageTitle = new MyString(*_servicePackageTitle);
    isActive = _isActive;
}
