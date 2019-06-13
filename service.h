#ifndef SERVICE_H
#define SERVICE_H
#include "person.h"


class Service
{
private:
    static unsigned int recordsCount;
    Person ** records;
public:
    Service();
    void addRecord(Person *obj);
    void deleteRecordById(unsigned int id);
    void showAllRecords();
    void updateRecord(unsigned int id, Person* obj);
    Person &operator[](int index);
    ~Service();
    static unsigned int getRecordsCount();
};

#endif // SERVICE_H
