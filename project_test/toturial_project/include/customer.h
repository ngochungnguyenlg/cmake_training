#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include <iostream>
#include "sqlhandle.h"
#include "person.h"
#include <fstream>

const int maxproduct=100;
struct selectProduct_
{
    mystring ID;
    mystring name;
    int quantity=0;
    double price=0;
    int promote=0;
    double money=0;

};
typedef selectProduct_ selectProduct;

class customer : public person
{
    int numberofboughtProduct;
    personinfor customerInfor;
    mystring customerID;
    selectProduct beBought[maxproduct];
    bool hasbill=false;
public:
    void byProduct();
    void byAProduct(mystring ID);
    void makeBill();
    void printBill();
    void viewBill();
    void deleteBuill();
    void deleteAproduct(mystring pID);
    personinfor getCustomerInfor(mystring ID);
    void showCustomerInfor() const;
    void priceofAproduct(selectProduct &proname);
    customer()
    {
        numberofboughtProduct=0;
    }
};
#endif