#ifndef _SALE_H
#define _SALE_H  
#include "sqlhandle.h"
#include "saler.h"

class sale
{
private:
    saler saleMember;
public:
    void searchGoods(mystring ID);
    sale();
    ~sale();
};


// sale::~sale()
// {
// }
#endif