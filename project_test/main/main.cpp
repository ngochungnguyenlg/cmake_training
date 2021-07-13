
#include <sale.h>
#include <sqlhandle.h>
#include <stdio.h>
#include <thread>
int main()
{
    sale sell;
    // sell.run();
   /* sqlhandle data;
    data.createtable();
    data.initializedataFROMCSV();*/
    thread t(&sale::run, &sell);
    t.join();
    // system("pause");
    // remove("./tmp.txt");
    return 0;

}
