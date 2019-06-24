#ifndef BANKCLIENT_H
#define BANKCLIENT_H

#include "person.h"


class BankClient : public Person
{
private:
    unsigned long currentAccount;
    char *servicePackageTitle;
    bool isActive;

public:
    BankClient();
    BankClient(char *_firstName,
               char *_lastName,
               unsigned short _age,
               bool _isDead,
               bool _isMarried,
               unsigned long _currentAccount,
               char *_servicePackageTitle,
               bool _isActive);
    BankClient(BankClient const &obj);
    unsigned long getCurrentAccount() const;
    void setCurrentAccount(unsigned long value);
    char *getServicePackageTitle() const;
    void setServicePackageTitle(char *value);
    bool getIsActive() const;
    void setIsActive(bool value);
    void setAll(char *_firstName,
                char *_lastName,
                unsigned short _age,
                bool _isDead,
                bool _isMarried,
                unsigned long _currentAccount,
                char *_servicePackageTitle,
                bool _isActive);
    ~BankClient();
    friend std::ostream& operator<<(std::ostream &out, const BankClient &person);
    friend std::istream& operator>>(std::istream &in, BankClient &person);
    virtual void toString(std::ostream &out) const;
};

#endif // BANKCLIENT_H
