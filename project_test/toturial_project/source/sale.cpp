#include "sale.h"
#include <stdio.h>

sale::~sale()
{
}
void sale::checkAsscess()
{
    char hasacount;
    const char* valid = "01";
    
    cout << "do you have account press? yes=1, no =0 \nif you input more than one letter\nwe will take the first letter" << endl;
    cin >> hasacount;
    while (!checkhasLetter(valid, hasacount))
    {
        cout << "Input wrongly, please make sure that you are right!!!" << endl;
        cin >> hasacount;
    }
    int hasacountint = (int)hasacount - 48;
    if (hasacountint ==0)
        this->saleMember.makeaccount();
    do
    {
        canAccess = this->saleMember.getAccessPermision();
        // cout << canAccess << endl;
        if (canAccess)
        {
            // cout << "can access" << endl;
        }
        else
        {
            cout << "please login to access system" << endl;
            this->saleMember.login();
        }
        if (this->saleMember.getTimesInput() > 5)
            break;
    } while (!canAccess);
    if (canAccess == 0)
    {
        cout << "you don't have access permission" << endl;
        exit(1);
    }
#if defined(_LINUX_)
        system("clear");
#else
        system("cls");
#endif
}
void sale::showMenu()
{
    if (!this->saleMember.getAccessPermision())
    {
        this->checkAsscess();
    }
    cout << "\n\n\nPlease input your select number" << endl;
    cout << "-------------------------------" << endl;
    cout << "|1. Check the product is availble now " << endl;
    cout << "|2. Start shopping" << endl;
    cout << "|3. View your bill" << endl;
    cout << "|4. Change your selection" << endl;
    cout << "|5. Print your bill" << endl;
    cout << "|6. Make Payment" << endl;
    cout << "|7. logout" << endl;
    cout << "|8. Out of our shop" << endl;
}
void sale::showMenufrom2nd()
{
    if (!this->saleMember.getAccessPermision())
    {
        this->checkAsscess();
    }
    cout << "\n\n\nPlease input your select number" << endl;
    cout << "-------------------------------" << endl;
    cout << "|1. Check the product is availble now " << endl;
    cout << "|2. Start shopping" << endl;
    cout << "|3. View your bill" << endl;
    cout << "|4. Change your selection" << endl;
    cout << "|5. Print your bill" << endl;
    cout << "|6. Make Payment" << endl;
    cout << "|7. Keep on shopping" << endl;
    cout << "|8. logout" << endl;
    cout << "|9. Out of our shop" << endl;

}
bool checkhasLetter(const char* data, char letter)
{
    for (int i = 0; i < strlen(data); i++)
    {
        if (letter == data[i]) {/*cout<<"true"<<endl;*/ return true; }
    }
    return false;
}
int sale::checkValidInput()
{
    char inputbyuser;
    cin >> inputbyuser;
    const char* invalid = "123456789";
    if (checkhasLetter(invalid, inputbyuser))
    {
        this->selection = inputbyuser - 48;
        //cout << "-------" <<  this->selection << endl;
    }
    return (this->selection);
}
void sale::getRequest()
{
    if (this->isfristTime)
    {
        this->showMenu();
        while (!checkValidInput()) { cout << "There are no your select please input again" << endl; }
    }
    else
    {
        this->showMenufrom2nd();
        while (!checkValidInput()) { cout << "There are no your select please input again" << endl; }
    }
    //this->checkValidInput();
    
}

void sale::dorequestfrom2nd()
{
    switch (this->selection)
    {
    case 1:
#if defined(_LINUX_)
        system("clear");
#else
        system("cls");
#endif
        cus.queryAlltable();
        break;
    case 2:
#if defined(_LINUX_)
        system("clear");
#else
        system("cls");
#endif
        cus.test();
        break;
    case 3:
#if defined(_LINUX_)
        system("clear");
#else
        system("cls");
#endif
        cus.viewBill();
        break;
    case 4:
    {
#if defined(_LINUX_)
        system("clear");
#else
        system("cls");
#endif
        cus.viewBill();
        cout << "input your ProductID you want to change" << endl;
        mystring pID;
        cin >> pID;
        cus.deleteAproduct(pID);
        break;
    }
    case 5:
#if defined(_LINUX_)
        system("clear");
#else
        system("cls");
#endif
        cus.printBill();
        break;
    case 6:
#if defined(_LINUX_)
        system("clear");
#else
        system("cls");
#endif
        cout << "this feature is not availble now" << endl;
        break;
    case 7:
#if defined(_LINUX_)
        system("clear");
#else
        system("cls");
#endif
        cus.keeponShopping(); break;
    case 8:
#if defined(_LINUX_)
        system("clear");
#else
        system("cls");
#endif
        this->saleMember.logout();
        this->canAccess = 0;
        this->isfristTime = 1;
        remove("tmp.txt");
        break;
    case 9:
#if defined(_LINUX_)
        system("clear");
#else
        system("cls");
#endif
        cout << "Good bye :)" << endl;
        break;
    }
}
void sale::dorequest()
{
    switch (this->selection)
    {
    case 1:
#if defined(_LINUX_)
        system("clear");
#else
        system("cls");
#endif
        cus.queryAlltable();
        break;
    case 2:
    {
#if defined(_LINUX_)
        system("clear");
#else
        system("cls");
#endif
        cus.test();
        this->isfristTime = 0;
        break; 
    }
    case 3:
#if defined(_LINUX_)
        system("clear");
#else
        system("cls");
#endif
        cus.viewBill();
        break;
    case 4:
    {
#if defined(_LINUX_)
        system("clear");
#else
        system("cls");
#endif
        cus.viewBill();
        cout << "input your ProductID you want to change" << endl;
        mystring pID;
        cin >> pID;
        cus.deleteAproduct(pID);
        break;
    }
    case 5:
#if defined(_LINUX_)
        system("clear");
#else
        system("cls");
#endif
        cus.printBill();
        break;
    case 6:
#if defined(_LINUX_)
        system("clear");
#else
        system("cls");
#endif
        cout << "this feature is not availble now" << endl;
        break;
    case 7:
#if defined(_LINUX_)
        system("clear");
#else
        system("cls");
#endif
        this->saleMember.logout();
        this->canAccess = 0;
        this->isfristTime = 1;
        remove("tmp.txt");

        break;
    case 8:
#if defined(_LINUX_)
        system("clear");
#else
        system("cls");
#endif
        cout <<"Good bye :)"<<endl;
        break;
    }
}
void sale::run()
{

    if(!this->canAccess) this->checkAsscess();
    
    while (this->canAccess)
    {
        if (this->isfristTime)
        {
            this->getRequest();
            this->dorequest();
            if (this->selection == 8) break;
        }
        else
        {
            this->getRequest();
            this->dorequestfrom2nd();
            if (this->selection == 9) break;
        }
        if(!this->canAccess) this->checkAsscess();
    }
}