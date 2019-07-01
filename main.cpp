#include <QCoreApplication>
#include <person.h>
#include <bankclient.h>
#include <service.h>
#include <windows.h>


#pragma GCC diagnostic ignored "-Wwrite-strings"

void printSpecification();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Service mainService = Service();

    printSpecification();

    char operation[255];

    while (strcmp(operation, "exit") != 0) {

        cout << "\nEnter necessary operation" << endl;
        cin >> operation;


        if (strcmp(operation, "addPerson") == 0) {
            Person *p = new Person();
            cin >> *p;
            mainService.addRecord(p);
        }
        else if (strcmp(operation, "addBankClient") == 0) {
            BankClient *bc = new BankClient();
            cin >> *bc;
            mainService.addRecord(bc);
        }
        else if (strcmp(operation, "show") == 0) {
            mainService.showAllRecords();
        }
        else if (strcmp(operation, "count") == 0) {
            cout << mainService.getRecordsCount() << endl;
        }
        else if (strcmp(operation, "delete") == 0) {
            cout << "Enter element index to delete" << endl;
            int index;
            cin >> index;

            mainService.deleteRecordById(index-1);

        }
        else if (strcmp(operation, "save") == 0) {
            mainService.saveToFile();
        }
        else if (strcmp(operation, "update") == 0) {
            cout << "Enter element index to update" << endl;
            int index;
            cin >> index;

            mainService.updateRecord(index - 1);
        }
        else if (strcmp(operation, "load") == 0) {
            mainService.readFromFile();
        }
        else if (strcmp(operation, "help") == 0) {
            printSpecification();
        }
        else if (strcmp(operation, "source") == 0) {
            mainService.showSourceRecords();
        }
        else if (strcmp(operation, "reset") == 0) {
            mainService.resetSort();
        }
        else if (strcmp(operation, "sort") == 0) {
            cout << "Enter field (firstName/lastName/age)" << endl;
            char field[32];
            cin >> field;
            cout << "Enter direction (asc/desc)" << endl;
            char direction[32];
            cin >> direction;

            if (strncmp(field, "firstName", 9) == 0) {
                if(strncmp(direction, "asc", 3) == 0 ) {
                    mainService.sortByFirstNameAsc();
                }
                if(strncmp(direction, "desc", 4) == 0 ) {
                    mainService.sortByFirstNameDesc();
                }
            }
            if (strncmp(field, "age", 3) == 0) {
                if(strncmp(direction, "asc", 3) == 0 ) {
                    mainService.sortByAgeAsc();
                }
                if(strncmp(direction, "desc", 4) == 0 ) {
                    mainService.sortByAgeDesc();
                }
            }

        }

    }
    exit(0);

    return a.exec();
}

void printSpecification(){
    cout << "=================================WELCOME!=============================" << endl;
    cout << "======================================================================" << endl;
    cout << "================ Type one of operations listed below:=================" << endl;
    cout << "1. addPerson - to add new person" << endl;
    cout << "2. addBankClient - to add new bank client" << endl;
    cout << "3. show - to print all of array data" << endl;
    cout << "4. count - to show count of records" << endl;
    cout << "5. delete - to delete record by index (input will appears after entering)" << endl;
    cout << "6. save - to save to file \"output.txt\"" << endl;
    cout << "7. load - to load from file \"output.txt\"" << endl;
    cout << "8. update - to update record by index (input will appears after entering)" << endl;
}
