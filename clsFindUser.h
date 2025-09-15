#pragma once
#include <iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankUser.h"
using namespace std;

class clsFindUser 
{
    public: 
    static clsBankUser Find(string Name)
    {
        clsBankUser cleint = clsBankUser::Find(Name);
        cleint.Print();
        return cleint;
    }
};