#include "mystring.h"

ostream &operator<<(ostream &os, const mystring hstr2)
{
    os << hstr2.data;
    return os;
}
istream &operator>>(istream &is,  mystring hstr2)
{
    is>>hstr2.data;
    return is;
}
mystring mystring::operator+(const mystring hstr2)
{
    strcat(this->data, hstr2.data);
}
mystring mystring::operator+(const char *hstr2)
{
    strcat(this->data, hstr2);
}
mystring mystring::operator+=(char hstr2)
{
    this->data[this->len()-1]=hstr2;
    this->data[this->len()+1]='\0';
}
bool mystring::operator==(const mystring hstr2)
{
    if (this->data == hstr2.data)
        return true;
    return false;
}
bool mystring::operator==(const char* hstr2)
{
    if (this->data == hstr2)
        return true;
    return false;
}

int mystring::len() const
{
    for (int i = 0; i < 256; i++)
    {
        if (data[i] == '\0')
        {
            return i + 1;
        }
    }
    return 255;
}
mystring::mystring(const char *h)
{
    data = new char[256];
    strcpy(data, h);
    // cout << data << endl;
}

mystring::mystring(const unsigned char *h)
{
    data = new char[256];
    strcpy(data, (const char*)h);
    // cout << data << endl;
}
mystring::mystring()
{
    data= new char[256];
    strcpy(this->data,"");
}

char* mystring::c_str()
{
    return data;
}