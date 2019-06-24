#include "service.h"



unsigned int Service::getRecordsCount()
{
    return recordsCount;
}

unsigned int Service::getWordsCount(char *str)
{
    unsigned int count = 0;
    unsigned int j = 0;
    if (strlen(str) == 0)
        return 0;
    while (str[j]) {
        if(str[j] == ' ')
            count++;
        j++;
    }
    return ++count;
}

Service::Service()
{

}

void Service::addRecord(Person *obj)
{
    if (recordsCount == 0) {
        records = new Person*[1];
        records[0] = obj;
    }
    else {
        Person **bufferArray = new Person*[recordsCount];
        for (int i=0; i< recordsCount; i++) {
            bufferArray[i] = records[i];
        }
        //FIXME
        delete []  records;
        records = new Person*[recordsCount + 1];
        for (int i =0; i< recordsCount; i++) {
            records[i] = bufferArray [i];
        }
        records[recordsCount] = obj;
        delete [] bufferArray;
    }
    recordsCount++;
}

void Service::deleteRecordById(unsigned int id)
{
    if (recordsCount == 0) return;
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
    if (recordsCount != 0) {
        for (unsigned int i=0; i < recordsCount; i++) {
            cout << i + 1 << ". "<< *records [i] << endl;
        }
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

bool Service::readFromFile(char *path)
{
    ifstream in;
    const int length = 256;
    in.open(path);
    char inputLine[length];
    in.getline(inputLine, length);
    if (getWordsCount(inputLine) == 5) {
        Person p;
        p.setFirstName(strtok(inputLine, " "));
        p.setLastName(strtok(nullptr, " "));
        p.setAge(atoi(strtok(nullptr, " ")));
        short isDead = atoi(strtok(nullptr, " "));
        p.setIsDead(isDead==1 ? true : false);
        short isMarried = atoi(strtok(nullptr, " "));
        p.setIsMarried(isMarried==1 ? true : false);
        return true;
    }
    if (getWordsCount(inputLine) == 8){
        BankClient bc;
        bc.setFirstName(strtok(inputLine, " "));
        bc.setLastName(strtok(nullptr, " "));
        bc.setAge(atoi(strtok(nullptr, " ")));
        short isDead = atoi(strtok(nullptr, " "));
        bc.setIsDead(isDead==1 ? true : false);
        short isMarried = atoi(strtok(nullptr, " "));
        bc.setIsMarried(isMarried==1 ? true : false);
        bc.setCurrentAccount(atol(strtok(nullptr, " ")));
        bc.setServicePackageTitle(strtok(nullptr, " "));
        short isActive = atoi(strtok(nullptr, " "));
        bc.setIsActive(isActive==1 ? true : false);
        return true;
    }
    else return false;
}

void Service::saveToFile(char *path)
{
    ofstream out;
    out.open(path);
    for (int i = 0; i < recordsCount-1; ++i) {
        out << records[i];
    }
}

Service::~Service()
{
    delete [] records;
    recordsCount = 0;
}
