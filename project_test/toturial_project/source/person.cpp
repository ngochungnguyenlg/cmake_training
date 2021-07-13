#include "person.h"
int person::IDnum = 0;
mystring person::getID()
{
    return this->data.ID;
}
personinfor person::getInformation()
{
    return this->data;
}

int person::getPos(personinfor data_)
{
    mystring ID = data_.ID;
    int len = ID.len();
    string pos("");
    for (int i = 8; i < len; i++)
    {
        pos += ID.c_str()[i];
    }
    int ret = std::atoi(pos.c_str());
    return ret;
}

void person::setDB()
{
    DB = this->getPersonDB();
    personinfor data;
    int ret = checkLeastID("person", "person", &data);
    //cout << ret << endl;
    if (ret != 1)
    {
        setIDnum(0);
    }
    else
    {
        int pos = getPos(data);
        pos += 1;
        setIDnum(pos);
    }
}
int person::inputInfor()
{

    cout << "please input first name" << endl;
    cin >> this->data.fistname;
    cout << "please input last name" << endl;
    cin >> this->data.lastname;
    cout << "please input address" << endl;
    cin >> this->data.address;
    cout << "please input cell phone number" << endl;
    cin >> this->data.cellNumber;
    this->setID();
    int exit = sqlite3_initialize();
    mystring sql = "CREATE TABLE IF NOT EXISTS person("
                   "ID TEXT PRIMARY KEY NOT NULL,"
                   "NAME TEXT NOT NULL,"
                   "LASTNAME TEXT NOT NULL,"
                   "ADDRESS TEXT NOT NULL,"
                   "PHONENUMBER TEXT NOT NULL);";
    exit = sqlite3_open("person.db", &this->DB);
    char *errMess;
    exit = sqlite3_exec(this->DB, sql.c_str(), NULL, 0, &errMess);
    if (exit != SQLITE_OK)
    {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(errMess);
    }
    mystring query_("INSERT INTO person VALUES");
    query_ = query_ + "('" + this->data.ID + "','" + this->data.fistname + "','" + this->data.lastname + "','" + this->data.address + "','" + this->data.cellNumber + "');";
    // cout << query_ << endl;
    exit = sqlite3_exec(this->DB, query_.c_str(), NULL, NULL, &errMess);
    if (exit != SQLITE_OK)
    {
        cout << errMess << endl;
    }
    else
    {
        cout << "input information successfully" << endl;
        cout << "ID is provided is:" << this->data.ID << endl;
        return 1;
    }
    return -1;
}

int person::checkLeastID(mystring database, mystring datatable, void *out)
{
    sqlite3_stmt *stmt;
    mystring dataname = database + ".db";
    int exit = sqlite3_open(dataname.c_str(), &this->DB);
    char *err;
    mystring data;
    mystring query_ = data + "SELECT * FROM " + datatable;
    exit = sqlite3_prepare_v2(this->DB, query_.c_str(), -1, &stmt, 0);

    personinfor *ret = (personinfor *)out;
    if (exit == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, 6);
        // cout << "aaaaaaaaaaaaaaaaa" << endl;
    }
    else
    {
        // cout << "LOIX" << endl;
        return -1;
    }
    // sqlite3_step(stmt);
    while (sqlite3_step(stmt) != SQLITE_DONE)
    {
        const unsigned char *ID_ = sqlite3_column_text(stmt, 0);
        const unsigned char *name = sqlite3_column_text(stmt, 1);
        const unsigned char *lastname = sqlite3_column_text(stmt, 2);
        const unsigned char *addr = sqlite3_column_text(stmt, 3);
        const unsigned char *phonenumber = sqlite3_column_text(stmt, 4);
        ret->ID = mystring(ID_);
        ret->fistname = name;
        ret->lastname = lastname;
        ret->address = addr;
        ret->cellNumber = phonenumber;
    }

    if (strncmp(ret->ID.c_str(), "ID101", ret->ID.len() - 1) != 0)
        return 1;
    return -1;
}

int person::selectbyID(mystring database, mystring datatable, mystring ID, void *out)
{
    sqlite3_stmt *stmt;
    mystring dataname = database + ".db";
    int exit = sqlite3_open(dataname.c_str(), &this->DB);
    char *err;
    mystring data;
    mystring query_ = data + "SELECT * FROM " + datatable;
    exit = sqlite3_prepare_v2(this->DB, query_.c_str(), -1, &stmt, 0);

    personinfor *ret = (personinfor *)out;
    if (exit == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, 6);
        // cout << "aaaaaaaaaaaaaaaaa" << endl;
    }
    else
    {
        // cout << "LOIX" << endl;
        return -1;
    }
    // sqlite3_step(stmt);
    while (sqlite3_step(stmt) != SQLITE_DONE)
    {
        if (strcmp((const char *)sqlite3_column_text(stmt, 0), (const char *)ID.c_str()) == 0)
        {
            const unsigned char *ID_ = sqlite3_column_text(stmt, 0);
            const unsigned char *name = sqlite3_column_text(stmt, 1);
            const unsigned char *lastname = sqlite3_column_text(stmt, 2);
            const unsigned char *addr = sqlite3_column_text(stmt, 3);
            const unsigned char *phonenumber = sqlite3_column_text(stmt, 4);
            ret->ID = mystring(ID_);
            ret->fistname = name;
            ret->lastname = lastname;
            ret->address = addr;
            ret->cellNumber = phonenumber;
            break;
            return 1;
        }
    }
    return -1;
}

int person::showinformation(mystring database, mystring datatable, mystring ID)
{
    sqlite3_stmt *stmt;
    mystring dataname = database + ".db";
    int exit = sqlite3_open(dataname.c_str(), &this->DB);
    char *err;
    mystring data;
    mystring query_ = data + "SELECT * FROM " + datatable;
    exit = sqlite3_prepare_v2(this->DB, query_.c_str(), -1, &stmt, 0);

    if (exit == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, 6);
        // cout << "aaaaaaaaaaaaaaaaa" << endl;
    }
    else
    {
        // cout << "LOIX" << endl;
        return -1;
    }
    // sqlite3_step(stmt);
    while (sqlite3_step(stmt) != SQLITE_DONE)
    {
        if (strcmp((const char *)sqlite3_column_text(stmt, 0), (const char *)ID.c_str()) == 0)
        {
            const unsigned char *ID_ = sqlite3_column_text(stmt, 0);
            const unsigned char *name = sqlite3_column_text(stmt, 1);
            const unsigned char *lastname = sqlite3_column_text(stmt, 2);
            const unsigned char *addr = sqlite3_column_text(stmt, 3);
            const unsigned char *phonenumber = sqlite3_column_text(stmt, 4);
            cout << "ID=" << ID << endl;
            cout << "first name=" << name << endl;
            cout << "last name=" << lastname << endl;
            cout << "address=" << addr << endl;
            cout << "phone number=" << phonenumber << endl;
            return 1;
        }
    }

    return -1;
}

void person::setID()
{
    stringstream data;
    std::string str("");
    int idnum = this->getIDnum();
    data << idnum;
    data >> str;
    mystring id;
    this->data.ID = id + "HUBK0000" + str.c_str();
    idnum += 1;
    this->setIDnum(idnum);
}