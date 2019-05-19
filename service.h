#ifndef SERVICE_H
#define SERVICE_H
#include "person.h"


class Service
{
private:
    static unsigned int recordsCount;
    Person * records;
public:
    Service();
    void addRecord(Person *obj);
    void deleteRecordById(unsigned int id);
    void showAllRecords();
    Person &operator[](int index);
    ~Service();
};

#endif // SERVICE_H
