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

bool Service::readFromFile()
{
    //char * path = "C:/Users/ivano/qtprojects/oop1/output.txt";
    char * path = "C:/Users/Ivan/Documents/QtProjects/oop1/output.txt";
    ifstream in;
    //const int inputLength = 512;
    in.open(path);

    if(in.is_open()){
        char inputLine[256];
        while (in.getline(inputLine, 255)){

            if (strncmp(inputLine, "Person", 6) == 0) {
                Person * person = new Person();

                char * begin = strstr(inputLine, "firstName=");
                begin = begin + 10;
                char* end = begin;
                while (*end != ',') {
                    end++;
                }
                long long length = end - begin;
                char * firstName = new char[length + 1];
                strncpy(firstName, begin, length);
                firstName[length] = '\0';
                person->setFirstName(firstName);
                firstName = nullptr;

                begin = strstr(inputLine, "lastName=");
                begin = begin + 9;
                end = begin;
                while (*end != ',') {
                    end++;
                }
                length = end - begin;
                char * lastName = new char[length + 1];
                strncpy(lastName, begin, length);
                lastName[length] = '\0';
                person->setLastName(lastName);
                lastName = nullptr;

                begin = strstr(inputLine, "age=");
                begin = begin + 4;
                end = begin;
                while (*end != ',') {
                    end++;
                }
                length = end - begin;
                char* age = new char[length];
                strncpy(age, begin, length);
                person->setAge(atoi(age));
                age = nullptr;

                begin = strstr(inputLine, "isDead=");
                begin = begin + 7;
                end = begin;
                end++;
                char isDead;
                strncpy(&isDead, begin, 1);
                if (isDead == '1'){
                    person->setIsDead(true);
                }
                if (isDead == '0'){
                    person->setIsDead(false);
                }

                begin = strstr(inputLine, "isMarried=");
                begin = begin + 10;
                end = begin;
                end++;
                char isMarried;
                strncpy(&isMarried, begin, 1);
                if (isMarried == '1'){
                    person->setIsMarried(true);
                }
                if (isMarried == '0'){
                    person->setIsMarried(false);
                }
                begin = nullptr;
                end = nullptr;

                this->addRecord(person);
            }

            if (strncmp(inputLine, "BankClient", 10) == 0) {
                BankClient * bankClient = new BankClient();

                char * begin = strstr(inputLine, "firstName=");
                begin = begin + 10;
                char* end = begin;
                while (*end != ',') {
                    end++;
                }
                long long length = end - begin;
                char * firstName = new char[length + 1];
                strncpy(firstName, begin, length);
                firstName[length] = '\0';
                bankClient->setFirstName(firstName);
                firstName = nullptr;

                begin = strstr(inputLine, "lastName=");
                begin = begin + 9;
                end = begin;
                while (*end != ',') {
                    end++;
                }
                length = end - begin;
                char* lastName = new char[length + 1];
                strncpy(lastName, begin, length);
                lastName[length] = '\0';
                bankClient->setLastName(lastName);
                lastName = nullptr;

                begin = strstr(inputLine, "age=");
                begin = begin + 4;
                end = begin;
                while (*end != ',') {
                    end++;
                }
                length = end - begin;
                char * age = new char[length];
                strncpy(age, begin, length);
                bankClient->setAge(atoi(age));

                begin = strstr(inputLine, "isDead=");
                begin = begin + 7;
                end = begin;
                end++;
                char isDead;
                strncpy(&isDead, begin, 1);
                if (isDead == '1'){
                    bankClient->setIsDead(true);
                }
                if (isDead == '0'){
                    bankClient->setIsDead(false);
                }

                begin = strstr(inputLine, "isMarried=");
                begin = begin + 10;
                end = begin;
                end++;
                char isMarried;
                strncpy(&isMarried, begin, 1);
                if (isMarried == '1'){
                    bankClient->setIsMarried(true);
                }
                if (isMarried == '0'){
                    bankClient->setIsMarried(false);
                }

                begin = strstr(inputLine, "currentAccount=");
                begin = begin + 15;
                end = begin;
                while (*end != ',') {
                    end++;
                }
                length = end - begin;
                char* currentAccount = new char[length];
                strncpy(currentAccount, begin, length);
                bankClient->setCurrentAccount(atol(currentAccount));


                begin = strstr(inputLine, "servicePackageTitle=");
                begin = begin + 20;
                end = begin;
                while (*end != ',') {
                    end++;
                }
                length = end - begin;
                char* servicePackageTitle = new char[length + 1];
                strncpy(servicePackageTitle, begin, length);
                servicePackageTitle[length] = '\0';
                bankClient->setServicePackageTitle(servicePackageTitle);

                begin = strstr(inputLine, "isActive=");
                begin = begin + 10;
                end = begin;
                end++;
                char isActive;
                strncpy(&isActive, begin, 1);
                if (isActive == '1'){
                    bankClient->setIsActive(true);
                }
                if (isActive == '0'){
                    bankClient->setIsActive(false);
                }
                begin = nullptr;
                end = nullptr;

                this->addRecord(bankClient);
            }
            memset(inputLine, 0, sizeof (inputLine));
        }
    }

    in.close();
    return false;
}

void Service::saveToFile()
{
    //char * path = "C:/Users/ivano/qtprojects/oop1/output.txt";
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

bool compFirstNameAsc(const Person* a, const Person * b)
{
    return a->getFirstName()[0] < b->getFirstName()[0];
}

void Service::sortByFirstNameAsc()
{
    std::sort(records, records + recordsCount, compFirstNameAsc);
}
bool compFirstNameDesc(const Person* a, const Person * b)
{
    return a->getFirstName()[0] > b->getFirstName()[0];
}

void Service::sortByFirstNameDesc()
{
    std::sort(records, records + recordsCount, compFirstNameDesc);
}

bool compAgeAsc(const Person *a, const Person *b)
{
    return a->getAge() < b->getAge();
}

void Service::sortByAgeAsc()
{
    std::sort(records, records + recordsCount, compAgeAsc);
}

bool compAgeDesc(const Person *a, const Person *b)
{
    return a->getAge() > b->getAge();
}

void Service::sortByAgeDesc()
{
    std::sort(records, records + recordsCount, compAgeDesc);
}
