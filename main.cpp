#include <QCoreApplication>
#include <person.h>
#include <bankclient.h>
#include <service.h>

#pragma GCC diagnostic ignored "-Wwrite-strings"

void printSpecification();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Service mainService = Service();

    printSpecification();

    char operation[255];

    while (strcmp(operation, "exit") != 0) {

        cout << "Enter necessary operation" << endl;
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
            mainService.getRecordsCount();
        }
        else if (strcmp(operation, "delete") == 0) {
            mainService.getRecordsCount();
        }
        else if (strcmp(operation, "save") == 0) {
            mainService.saveToFile();
        }
        else if (strcmp(operation, "update") == 0) {
            cout << "Enter element index" << endl;
            int index;
            cin >> index;

            mainService.updateRecord(index - 1);
        }
    }

    return a.exec();
}

void printSpecification(){
    cout << "WELCOME!" << endl;
    cout << "Type one of operations listed below:" << endl;
    cout << "addPerson - to add new person" << endl;
    cout << "addBankClient - to add new bank client" << endl;
    cout << "show - to print all of array data" << endl;
    cout << "count - to show count of records" << endl;
    cout << "delete - to delete record by index (input will appears after entering)" << endl;
    cout << "save - to save to file \"output.txt\"" << endl;
    cout << "update - to update record by index (input will appears after entering)" << endl;
}
