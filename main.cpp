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

    cout << "Enter necessary operation" << endl;
    cin >> operation;
    cout << operation;

    while (!strcmp(operation, "exit")){
        cout << "entering the loopp";
        if (strncmp(operation, "addPerson", strlen("add Person"))) {
            Person p;
            cin >> p;
            mainService.addRecord(&p);
        }
        else if (strncmp(operation, "addBankClient", strlen("add BankClient"))) {
            BankClient bc;
            cin >> bc;
            mainService.addRecord(&bc);
        }
        else if (strncmp(operation, "show", strlen("show"))) {
            mainService.showAllRecords();
        }
        else if (strncmp(operation, "count", strlen("count"))) {
            mainService.getRecordsCount();
        }
    }

    return a.exec();
}
