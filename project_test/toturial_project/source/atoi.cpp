#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <math.h>
#include <pthread.h>
using namespace std;
int find(char letter, string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == letter)
            return i;
    }
    return -1;
}
int findduplicates(string s, char letter)
{
    int numberofletter = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (letter == s[i])
            numberofletter += 1;
        if (numberofletter > 1)
            return numberofletter;
    }
    return 0;
}
int checkvalidstring(string s)
{
    string validvalue = "1234567890.-+ ";
    string digitalValidvalue = ".1234567890";
    bool iswhitespace;
    bool isdigit;
    if (s[0] == '+' || s[0] == '.' || s[0] == '-' || s[0] == ' ' || find(s[0], digitalValidvalue) != -1)
        isdigit = 1;
    if (s[0] == ' ')
        iswhitespace = 1;
    for (int i = 0; i < s.length(); i++)
    {

        // cout << "s[i]" << s[i] << endl;
        if (i > 0)
        {
            if (s[i - 1] == ' ' && iswhitespace == 1)
                iswhitespace = 1;
            else
            {
                iswhitespace = 0;
            }
            if (find(s[i], digitalValidvalue) != -1 && isdigit == 1 || iswhitespace == 1)
            {
                isdigit = 1;
            }
            else
            {
                return i; //return value before trouble is not digital
            }
        }
        if (find(s[i], validvalue) == -1)
            return -1;
        if (i > 0 && (s[i] == '-' || s[i] == '+') && iswhitespace != 1)
        {
            cout<<__LINE__<<endl;
            return -1;
        }
    }
    return -2;
}
long long int tolong(string s)
{
    long long int ret = 0;
    int findAdot = find('.', s);
    int afterdot = 0;
    int lengcheck = s.length();
    double afterdotnumber = 0;
    if (findAdot != -1)
    {
        afterdot = int(s[findAdot + 1]);
        lengcheck = findAdot;
    }
    unsigned long long int m = 1;
    for (int i = lengcheck - 1; i >= 0; i--)
    {
        if (i == 0 && s[0] == '-')
            ret *= -1;
        else if (i == 0 && s[0] == '+')
            ret *= 1;
        else
        {
            if (s[i] == '0')
            {
                ret += m;
            }
            else
                ret += ((int)s[i] - (int)'0') * m;
            
        }
        m *= 10;
        long long int numcmp=ret-4294967295;
        if (numcmp > 0)
        {
            cout << "dung"<<endl;
            if (s[0] == '-')
                return (-2147483647);
            else
                return 4294967295;
        }
    }
    float n = 0.1;
    int roundafterfloat = 0;
    if (findAdot > 1)
    {
        for (int i = findAdot + 1; i < s.length(); i++)
        {
            afterdotnumber += ((int)s[i] - (int)'0') * n;
            n *= 0.1;
        }
        if (s[0] == '-')
            roundafterfloat = (-1) * round(afterdotnumber);
        else
            roundafterfloat = round(afterdotnumber);
    }
    ret += roundafterfloat;
    return ret;
}
int getnumber(string s)
{
    int stringChecking = checkvalidstring(s);
    string temp;
    if (stringChecking > 0)
    {
        for (int i = 0; i < stringChecking; i++)
        {
            if (s[i] != ' ')
                temp += s[i];
        }
    }
    else if (stringChecking == -1)
    {
        // cout << "here=line=" << __LINE__ << endl;
        return 0;
    }
    else if (stringChecking == -2)
    {
        // cout << "here=line=" << __LINE__ << endl;
        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] != ' ')
            {
                temp += s[i];
            }
        }
    }

    float fout;
    int iout = 0;
    long long int lout = tolong(temp);
    cout << "temp="<<temp<<endl;
    cout <<"dfdf"<<lout<<endl;
    if (findduplicates(temp, '.') > 1)
    {
        return 0;
    }
    if (lout >= 2147483647)
    {
        return 2147483647;
    }

    else if (lout <= -2147483648)
    {

        return -2147483648;
    }
    else
    {
        iout = (int)(lout);
    }
    return iout;
}
