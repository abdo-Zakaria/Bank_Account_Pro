#pragma once
#include <iostream>
#include"clsBankCleint.h"
#include"clsInputValidate.h"
using namespace std;


class clsScreen 
{
    public : 

    static void BigHeader(string Title)
    {
        
        cout <<"           ___________________________________________________________________\n";
        cout <<"                                       "<<Title<<"                             \n";
        cout <<"           ___________________________________________________________________\n";
    }
};