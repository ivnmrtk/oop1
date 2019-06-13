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

    char * operation = "";

    cout << "Enter necessary operation";
    cin >> operation;

    while (!strcmp(operation, "exit")){
        if (strncmp(operation, "add Person", strlen("add Person"))) {
            //TODO
        }
        else if (strncmp(operation, "add BankClient", strlen("add BankClient"))) {

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
