#include "saler.h"

saler::saler()
{
}
int saler::createAccount()
{
    adminInfor datainput;
    int ret = 0;

    do
    {
        cout << "your acount:" << endl;
        cin >> datainput.ID;
        cout << "your name:" << endl;
        cin >> datainput.name;
        cout << "your pass:" << endl;
        cin >> datainput.password;
        int countInvalidPw=0;
        while (datainput.password.len() < 9)
        {
            cout << "please make sure your pass word has length longer than 8" << endl;
            cout << "your pass again:" << endl;
            cin >> datainput.password;
            countInvalidPw+=1;
            if(countInvalidPw==2)
            {
                cout << "you have inputted too many times incorrect format of password "<<endl;
                break;
            }
        }
        if(countInvalidPw==2) break;
        ret = db.inputAdminInfor(datainput);
    } while (ret == 0);
}

void saler::makeaccount()
{
    cout << "Welcom to HHH shop as a new member of saler group" << endl;
    cout << "to complete of this thing, plese input your information to make" << endl;
    cout << "saler Account :" << endl;
    cout << "1st plese fill in form blow your information" << endl;
    this->inputInfor();
    int ret = this->createAccount();
}
int saler::selectbyID(mystring database, mystring datatable, mystring ID, void *out)
{
    sqlite3_stmt *stmt;
    mystring dataname = database + ".db";
    int exit = sqlite3_open(dataname.c_str(), &this->DB);
    mystring data;
    mystring query_ = data + "SELECT * FROM " + datatable;
    exit = sqlite3_prepare_v2(this->DB, query_.c_str(), -1, &stmt, 0);

    adminInfor *ret = (adminInfor *)out;
    if (exit == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, 6);
        // cout << "aaaaaaaaaaaaaaaaa" << endl;
    }
    else
    {
        // cout << "LOIX" << endl;
    }

    while (sqlite3_step(stmt) != SQLITE_DONE)
    {
        // cout << strcmp((const char *)sqlite3_column_text(stmt, 0), ID.c_str()) << endl;
        if (strcmp((const char *)sqlite3_column_text(stmt, 0), (const char *)ID.c_str()) == 0)
        {
            const unsigned char *ID = sqlite3_column_text(stmt, 0);
            const unsigned char *name = sqlite3_column_text(stmt, 1);
            const unsigned char *password = sqlite3_column_text(stmt, 2);
            ret->ID = ID;
            ret->name = name;
            ret->password = password;
            out = (void *)ret;
            return 1;
            break;
        }
    }
    return -1;
}
// ' or 1=1 --
void saler::login()
{
    adminInfor login, getdata;
    int ret = 1;
    do
    {
        cout <<"login system is starting"<<endl;
        cout << "please input your ID" << endl;
        cin >> login.ID;
        cout << "please input your password" << endl;
        cin >> login.password;
        int select_Ok = this->selectbyID("admininfor", "admininfor", login.ID, &getdata);

        ret = strncmp(getdata.password.c_str(), login.password.c_str(), getdata.ID.len() - 1);
        if (ret == 0 && select_Ok != -1)
        {
            this->isMember = 1;
            cout << "login successfuly" << endl;
            this->invalidTime = 0;
        }
        else
        {
            if (this->invalidTime < 5)
            {
                cout << "invalid user or password, please input again" << endl;
            }
            else
            {
                cout << "you have inputed 5 times continuously incorrect, please try later" << endl;
            }
            invalidTime += 1;
            ret = 1;
        }
    } while (ret != 0 && this->invalidTime <= 5);
}
