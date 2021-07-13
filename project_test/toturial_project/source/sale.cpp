#include "sale.h"

sale::sale()
{
    this->saleMember.login();
}
sale::~sale()
{
}
void sale::searchGoods(mystring ID)
{
    bool canAccess=0;
    do{
        canAccess=this->saleMember.getAccessPermision();
        cout << canAccess<<endl;
        if(canAccess)
        {
            cout <<"can access"<<endl;
        }
        else
        {
            cout <<"please login to access system"<<endl;
            this->saleMember.login();
        }
        if(this->saleMember.getTimesInput()>5) break;
    }while(!canAccess);
    if(canAccess==0)
    {
        cout <<"you don't have access permission"<<endl;
        system("exit");
    }
    cout <<"searchGoods complete"<<endl;
}