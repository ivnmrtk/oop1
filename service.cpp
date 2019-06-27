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

//Принимает индекс массива, а не отображаемый id.
void Service::deleteRecordById(unsigned int id)
{
    if (recordsCount == 0) {
        return;
    }
    Person **bufferArray = new Person*[recordsCount-1];
    bool isSkipped = false;
    unsigned int newIndex;
    for (unsigned int i=0; i<recordsCount-1; i++) {
        if (i == id) {
            isSkipped = true;
        }
        if (isSkipped == true){
            newIndex = i + 1;
        }
        if (isSkipped == false) {
            newIndex = i;
        }
        bufferArray[i] = records[newIndex];
    }
    delete records[id];
    delete [] records;
    records = new Person*[recordsCount-1];
    for (unsigned int i = 0; i< recordsCount-1; i++) {
        records[i] = bufferArray[i];
    }
    delete [] bufferArray;
    recordsCount--;
}

void Service::showAllRecords()
{
    if (recordsCount != 0) {
        for (unsigned int i=0; i < recordsCount; i++) {
            cout << i + 1 << ". "<< *records [i] << endl;
        }
    }
}

//Принимает индекс массива, а не отображаемый id.
void Service::updateRecord(unsigned int id)
{
    if (id > recordsCount){
        cout << "Invalid index";
        return;
    }

    char className = records[id]->getClass();
    delete records[id];
    if (className == 'P'){
        Person *p = new Person();
        cin >> *p;
        records[id] = p;
    }
    if (className == 'B'){
        BankClient *bc = new BankClient();
        cin >> *bc;
        records[id] = bc;
    }

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

void Service::saveToFile()
{
    char * path = "C:/Users/Ivan/Documents/QtProjects/oop1/output.txt";
    ofstream out;
    out.open(path);
    if (out.is_open()) {
    for (int i = 0; i < recordsCount; ++i) {
        out << *records[i];
    }
    cout << "Successfully written to file";
    }
}


Service::~Service()
{
    delete [] records;
    recordsCount = 0;
}
