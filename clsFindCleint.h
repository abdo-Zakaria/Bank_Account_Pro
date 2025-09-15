#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsBankCleint.h"
using namespace std;

class clsFindCleint : public clsBankClient 
{
    public: 
    static clsBankClient Find(string AccountNumber)
    {
        clsBankClient cleint = clsBankClient::Find(AccountNumber);
        cleint.Print();
        return cleint;
    }
};