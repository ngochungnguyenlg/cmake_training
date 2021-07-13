#ifndef _MySTRING_H
#define _MySTRING_H

#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

class mystring
{
private:
    char *data;
public:
    mystring();
    mystring(const char *h);
    mystring(const unsigned char *h);
    int len() const;
    mystring operator+(const mystring hstr2);
    mystring operator+(const char *hstr2);
    mystring operator+=(const mystring hstr2);
    mystring operator+=(char hstr2);
    mystring operator-(const mystring hstr2);
    bool operator==(const mystring hstr2);
    bool operator==(const char* hstr2);
    friend ostream &operator<<(ostream &os, const mystring hstr2);
    friend istream &operator>>(istream &is, mystring hstr2);
    char *c_str();
};
#endif