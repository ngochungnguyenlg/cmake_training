#include <saler.h>
#include <mystring.h>
 #include <sqlhandle.h>
#include <sale.h>
#include <person.h>
#include <customer.h>
int main()
{
    customer d;

    // d.getCustomerInfor("HUBK00001");
    d.byProduct();
    // d.showCustomerInfor();
    d.makeBill();
    d.viewBill();
    return 0;
    
}