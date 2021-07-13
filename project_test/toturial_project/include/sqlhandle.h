#ifndef _SQLHANDLE_H
#define _SQLHANDLE_H

#include <sqlite3.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <mystring.h>

using namespace std;

struct rowData_
{
    mystring ID;
    mystring name;
    float price;
    int promote;
    int quantity;
    mystring from;
};
struct adminInfor_
{
    mystring name;
    mystring ID;
    mystring password;
};
typedef adminInfor_ adminInfor;
typedef rowData_  row;

class sqlhandle
{
private:
    sqlite3 *DB, *DBad, *PersonDB;
    sqlite3_stmt *query = NULL;
public:
    void shutdown();
    void createtable();
    void initializedataFROMCSV();
    void queryAlltable();
    virtual int selectbyID(mystring database, mystring datatable,mystring ID, void *out);
    int inputAdminInfor(adminInfor input);
    sqlite3 *getPersonDB() { return PersonDB;}
    sqlite3 *getSupermakerDB() { return DB;}
    sqlite3 *getAdminDB() { return DBad;}
    virtual ~sqlhandle()
    {}
};
#endif