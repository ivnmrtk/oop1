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

        else if (strcmp(operation, "filter") == 0) {

            cout << "Enter filed (firstName/lastName)" << endl;
            char field[32];
            cin >> field;

            cout << "Enter substring for filter" << endl;
            char filter[32];
            cin >> filter;

            if (strcmp(field, "firstName") == 0){
                mainService.filterFirstName(filter);
            }

            if (strcmp(field, "lastName") == 0){
                mainService.filterLastName(filter);
            }


        }

    }
    exit(0);

    return a.exec();
}

void printSpecification(){
    cout << "=================================WELCOME!=============================" << endl;
    cout << "======================================================================" << endl;
    cout << "================ Enter one of operations listed below:=================" << endl;
    cout << " addPerson - to add new person" << endl;
    cout << " addBankClient - to add new bank client" << endl;
    cout << " show - to print all of array data" << endl;
    cout << " count - to show count of records" << endl;
    cout << " delete - to delete record by index (input will appears after entering)" << endl;
    cout << " save - to save to file \"output.txt\"" << endl;
    cout << " load - to load from file \"output.txt\"" << endl;
    cout << " update - to update record by index (input will appears after entering)" << endl;
    cout << " sort - to sort records by one of field by specified order" << endl;
    cout << " filter -  by substring on specified field" << endl;
    cout << " help -  by substring on specified field" << endl;

}
