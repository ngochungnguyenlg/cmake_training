#ifndef _SALER_H
#define _SALER_H
#include <mystring.h>
#include <iostream>
#include "sqlhandle.h"
#include <sqlite3.h>
#include "person.h"

class saler: public sqlhandle, public person
{
    private:
        mystring name;
        mystring ID;
        mystring password;
        void createPassword();
        int createAccount();
        void invalidTimesLoginCheck(mystring ID);
        int invalidTime=0;
        sqlhandle db;
        sqlite3 *DB;
        bool isMember=0;
    public:
        void login();
        void logout();
        void makeaccount();
        mystring requestInput();
        virtual int selectbyID(mystring database, mystring datatable,mystring ID, void *out);
        bool getAccessPermision(){ return this->isMember;}
        int getTimesInput(){return invalidTime;}
        saler();    
};
#endif