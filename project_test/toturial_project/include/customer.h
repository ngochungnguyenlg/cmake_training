#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include <iostream>
#include "sqlhandle.h"
#include "person.h"
#include <fstream>

const int maxproduct=100;
struct testdata
{
    mystring data;
    int qty;
};
typedef testdata testdata;
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
    selectProduct  *beBought= new selectProduct[maxproduct];
    bool hasbill=false;
public:
    void byProduct();
    void test();
    void byAProduct(mystring ID);
    void byAProducttest(mystring ID, int qty);
    void makeBill();
    void printBill();
    void viewBill();
    void deleteBill();
    void deleteAproduct(mystring pID);
    void modifyBeBought(selectProduct &productID, int qty);
    personinfor getCustomerInfor(mystring ID);
    void showCustomerInfor() const;
    void priceofAproduct(selectProduct &proname);
    void keeponShopping();
    customer()
    {
        numberofboughtProduct=0;
    }
    ~customer()
    {
        delete [] beBought;
    };
};
#endif