#ifndef SERVICE_H
#define SERVICE_H
#include "person.h"
#include <fstream>
#include "bankclient.h"

class Service
{
private:
    unsigned int recordsCount = 0;
    Person ** records;
    unsigned int getWordsCount(char * str);
public:
    Service();
    void addRecord(Person *obj);
    void deleteRecordById(unsigned int id);
    void showAllRecords();
    void updateRecord(unsigned int id, Person* obj);
    Person &operator[](int index);
    ~Service();
    unsigned int getRecordsCount();
    bool readFromFile(char* path);
    void saveToFile(char* path);
};

#endif // SERVICE_H
