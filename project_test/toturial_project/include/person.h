#ifndef _PERSON_H
#define _PERSON_H
#include <mystring.h>
#include "sqlhandle.h"
struct personinfor
{
    mystring ID;
    mystring fistname;
    mystring lastname;
    mystring address;
    mystring cellNumber;
    personinfor()
    {
        ID="ID101";
        fistname="A";
        lastname="nguyen";
        address="Hanoi, Hoan Kiem, xxx";
        cellNumber="+84xxxxxxx";
    }
};

typedef personinfor personinfor;
class person : public sqlhandle
{
private:
    sqlite3 *DB;
    personinfor data;
    static int IDnum;
public:
    mystring getID();
    personinfor getInformation();
    virtual int inputInfor();
    virtual void setDB();
    virtual void setID();
    int checkLeastID(mystring database, mystring datatable, void *out);
    virtual int selectbyID(mystring database, mystring datatable,mystring ID, void *out);
    int showinformation(mystring database, mystring datatable,mystring ID);
    int getPos(personinfor data_);
    static void setIDnum(int num)
    {
        person::IDnum=num;

    }
    static int getIDnum()
    {
        return person::IDnum;
    }
    person()
    {
        this->setDB();
    }
};
#endif