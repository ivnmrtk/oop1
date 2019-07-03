#ifndef SERVICE_H
#define SERVICE_H
#include "person.h"
#include <fstream>
#include "bankclient.h"
#include <algorithm>

class Service
{
private:
    unsigned int recordsCount = 0;
    unsigned int printedCount = 0;
    Person ** records = nullptr;
    Person ** sourceRecords = nullptr;
    unsigned int getWordsCount(char * str);
public:
    Service();
    void addRecord(Person *obj);
    void deleteRecordById(unsigned int id);
    void showAllRecords();
    void showSourceRecords();
    void resetSort();
    void updateRecord(unsigned int id);
    Person &operator[](int index);
    ~Service();
    unsigned int getRecordsCount();
    bool readFromFile();
    void saveToFile();
    friend bool compFirstNameAsc(const Person * a, const Person * b);
    void sortByFirstNameAsc();
    friend bool compFirstNameDesc(const Person * a, const Person * b);
    void sortByFirstNameDesc();

    friend bool compLastNameAsc(const Person * a, const Person * b);
    void sortByLastNameAsc();
    friend bool compLastNameDesc(const Person * a, const Person * b);
    void sortByLastNameDesc();

    friend bool compAgeAsc(const Person *a, const Person *b);
    void sortByAgeAsc();
    friend bool compAgeDesc(const Person *a, const Person *b);
    void sortByAgeDesc();
    void filterFirstName(char* str);
    void filterLastName(char* str);
};

#endif // SERVICE_H
