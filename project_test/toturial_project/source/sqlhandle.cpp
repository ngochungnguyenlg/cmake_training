#include "sqlhandle.h"
#include <mystring.h>
static int callback(void *data, int argc, char **argv, char **azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char *)data);

    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}
int sqlhandle::selectbyID(mystring database, mystring datatable,mystring ID, void *out)
{
    sqlite3_stmt *stmt;
    mystring dataname = database+".db";
    int exit = sqlite3_open(dataname.c_str(), &this->DB);
    char *err;
    mystring data;
    mystring query_ = data + "SELECT * FROM "+datatable;
    exit = sqlite3_prepare_v2(this->DB, query_.c_str(), -1, &stmt, 0);

    row *ret=(row*)out;
    if (exit == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, 6);
        // cout << "aaaaaaaaaaaaaaaaa" << endl;
    }
    else
    {
        cout << "LOIX" << endl;
    }

    while (sqlite3_step(stmt) != SQLITE_DONE)
    {
        // cout << strcmp((const char *)sqlite3_column_text(stmt, 0), ID.c_str()) << endl;
        if (strcmp((const char *)sqlite3_column_text(stmt, 0), (const char *)ID.c_str()) == 0)
        {
            const unsigned char *ID = sqlite3_column_text(stmt, 0);
            const unsigned char *name = sqlite3_column_text(stmt, 1);
            float price = (float)sqlite3_column_double(stmt, 2);
            int promote = sqlite3_column_int(stmt, 3);
            int quantity = sqlite3_column_int(stmt, 4);
            const unsigned char *from = sqlite3_column_text(stmt, 5);
            ret->ID = (mystring)ID;
            ret->name = (mystring)name;
            ret->price = price;
            ret->promote = promote;
            ret->quantity = quantity;
            ret->from = from;
            return 1;
            break;

        }
    }
    return -1;
}
void sqlhandle::queryAlltable()
{
    int exit = sqlite3_open("supermaket.db", &this->DB);
    string query_ = "SELECT * FROM GOODSTB1st;";
    row row;
    sqlite3_exec(this->DB, query_.c_str(), callback, &row, NULL);
    // cout <<":da in"<<row.ID<<endl;
}
void sqlhandle::initializedataFROMCSV()
{
    fstream fb;
    fb.open("../datacsv/data.csv", std::ios::in);
    if (fb.fail())
    {
        cerr << "open file failed exit program " << __LINE__ << endl;
    }
    //open database
    int exit = sqlite3_open("supermaket.db", &this->DB);
    string query_ = "SELECT * FROM GOODSTB1st;";
    string includepos = "INSERT INTO GOODSTB1st VALUES";

    string line, temp, word;
    string sql;
    int countrow = 0;
    while (fb >> temp)
    {

        getline(fb, line);
        stringstream s;
        s << temp;
        string trytoin = "";
        string valuetmp = "(";
        int Isnumeric[] = {0, 0, 1, 1, 1, 0};
        int count = 0;

        while (getline(s, word, ','))
        {
            string add;
            if (Isnumeric[count] == 0)
            {
                add = "'" + word + "'";
            }
            else
            {
                add = word;
            }
            if (count != 5)
                valuetmp += add + ",";
            else
            {
                valuetmp += add;
            }

            count += 1;
        }
        valuetmp += ");";
        if (countrow != 0)
        {
            sql += includepos + valuetmp + " ";
            trytoin = includepos + valuetmp;
            sqlite3_exec(this->DB, query_.c_str(), callback, NULL, NULL);
            char *messaggeError;
            exit = sqlite3_exec(this->DB, trytoin.c_str(), NULL, NULL, &messaggeError);
            if (exit != SQLITE_OK)
            {
                cout << "cannot insert value " << messaggeError << endl;
            }
        }
        countrow += 1;
    }
}
void sqlhandle::shutdown()
{
    if (this->query != NULL)
        sqlite3_finalize(query);
    if (this->DB != NULL)
        sqlite3_close(DB);
    sqlite3_shutdown();
}

void sqlhandle::createtable()
{
    int ret = sqlite3_initialize();
    string sql = "CREATE TABLE IF NOT EXISTS GOODSTB1st("
                 "ID TEXT PRIMARY KEY     NOT NULL, "
                 "NAME           TEXT    NOT NULL, "
                 "PRICE          REAL     NOT NULL, "
                 "PROMOTE            INT     NOT NULL, "
                 "QUANTITY        INT NOT NULL, "
                 "fromContry         TEXT NOT NULL );";
    int exit = 0;
    exit = sqlite3_open("supermaket.db", &DB);
    char *messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK)
    {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messaggeError);
    }
    // else
    // std::cout << "Table created Successfully" << std::endl;

    sqlite3_close(DB);
}
int sqlhandle::inputAdminInfor(adminInfor input)
{
    int ret = sqlite3_initialize();
    string sql = "CREATE TABLE IF NOT EXISTS admininfor("
                 "ID TEXT PRIMARY KEY     NOT NULL, "
                 "NAME           TEXT    NOT NULL, "
                 "password       TEXT NOT NULL );";
    int exit = 0;
    exit = sqlite3_open("admininfor.db", &this->DBad);
    char *messaggeError;
    exit = sqlite3_exec(this->DBad, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK)
    {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messaggeError);
    }
    // else
    //     // std::cout << "Table created Successfully" << std::endl;
    mystring query_("INSERT INTO admininfor VALUES");
    query_ = query_ + "('" + input.ID + "','" + input.name + "','" + input.password + "');";
    // cout << query_ << endl;
    exit = sqlite3_exec(this->DBad, query_.c_str(), NULL, NULL, &messaggeError);
    if (exit != SQLITE_OK)
    {
        cout << "incorrect value or id already existed" << endl;
        cout << "please input again"<<endl;
        return 0;
    }
    sqlite3_close(DBad);
    return 1;
}
