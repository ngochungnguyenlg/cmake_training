#ifndef _SALE_H
#define _SALE_H  
#include "sqlhandle.h"
#include "saler.h"
#include "customer.h"

bool checkhasLetter(const char* data, char letter);
class sale
{
private:
    saler saleMember;
    int selection;
    customer cus;
    bool canAccess;
    int checkValidInput();
    bool isfristTime;
public:
    void checkAsscess();
    void showMenu();
    void dorequest();
    void showMenufrom2nd();
    void dorequestfrom2nd();
    void getRequest();
    void run();
    sale()
    {
        canAccess = 0;
        isfristTime = 1;
    }
    ~sale();
};


// sale::~sale()
// {
// }
#endif