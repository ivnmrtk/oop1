#include <QCoreApplication>
#include <person.h>
#include <bankclient.h>
#include <service.h>

#pragma GCC diagnostic ignored "-Wwrite-strings"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Service mainService = Service();

    //Person *obj;

    //obj = new BankClient("name", "last_name", 23, true, true, 200, "opt", true);

    //cout << obj;

    char operation[255];

    while (strcmp(operation, "exit") != 0) {

        cout << "Enter necessary operation" << endl;
        cin >> operation;

        cout << "entering the loopp" << endl;

        if (strcmp(operation, "addPerson") == 0) {
            Person p;
            cin >> p;
            mainService.addRecord(&p);
        }
        else if (strcmp(operation, "addBankClient") == 0) {
            BankClient bc;
            cin >> bc;
            mainService.addRecord(&bc);
        }
        else if (strcmp(operation, "show") == 0) {
            mainService.showAllRecords();
        }
        else if (strcmp(operation, "count") == 0) {
            mainService.getRecordsCount();
        }
        cout << "exit the loop" << endl;
    }

    return a.exec();
}
