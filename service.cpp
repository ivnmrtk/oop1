#include "service.h"

unsigned int Service::recordsCount = 0;

unsigned int Service::getRecordsCount()
{
    return recordsCount;
}

Service::Service()
{

}

void Service::addRecord(Person *obj)
{
    recordsCount++;
    if (records == nullptr){
        records = new Person*[recordsCount];
        records[recordsCount] = obj;
    }
    else {
        Person **bufferArray = new Person*[recordsCount];
        for (unsigned int i=0; i< recordsCount - 2; i++) {
            bufferArray[i] = records[i];
        }
        bufferArray[recordsCount - 1] = obj;
        delete [] records;
        records = new Person*[recordsCount];
        for (unsigned int i=0; i< recordsCount - 1; i++) {
            records[i] = bufferArray[i];
        }
        delete []  bufferArray;
    }
}

void Service::deleteRecordById(unsigned int id)
{
    recordsCount--;
    Person **bufferArray = new Person*[recordsCount];
    unsigned int newIndex;
    for (unsigned int i=0; i<recordsCount;) {
        if (i >= (id - 1)) {
            newIndex = i -1;
        }
        else {
            newIndex = i;
        }
        bufferArray[i] = records[newIndex];
    }
    delete [] records;
    records = new Person*[recordsCount];
    for (unsigned int i = 0; i< recordsCount; i++) {
        records[i] = bufferArray[i];
    }
    delete [] bufferArray;
}

void Service::showAllRecords()
{
    for (unsigned int i=0; i < recordsCount - 1; i++) {
        cout << i << ". "<< records [i] << endl;
    }
}

void Service::updateRecord(unsigned int id, Person *obj)
{
    records[id-1] = obj;
}

Person &Service::operator[](int index)
{
    return *records[index];
}

Service::~Service()
{
    delete [] records;
    recordsCount = 0;
}
