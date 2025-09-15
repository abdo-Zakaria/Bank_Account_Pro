#pragma once
#include <iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankUser.h"
using namespace std;


class clsUpdateUserData
{
    public: 

    static void UpdateCleintInfo()
    {
        string Name = clsInputValidate::readStirng("Enter the  Name ");
        char desire ;
       clsBankUser ali =clsBankUser::Find(Name);
        while (ali._Name == "" )
        {
            cout << "This Account Number is not found , please Enter anohter Number \n\n\n";
            cout << "Enter an Account Number \n";
            cin >> Name;
            ali =clsBankUser::Find(Name);
        }
        ali.Print();
        cout<<"Do you want to update this Data ? \n";
        cin >> desire;
        if (tolower(desire) == 'y')
        {
           clsBankUser::UpdateUser(Name);
        }
    }
};