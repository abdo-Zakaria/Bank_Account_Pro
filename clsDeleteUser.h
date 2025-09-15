#pragma once
#include <iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankUser.h"
using namespace std;



class clsDeleteUser 
{
    public : 
    static  void DeleteCleint()
    {
        string Names;
        char desire ;
        cout << "Enter an  Name \n";
        cin >> Names;
        clsBankUser ali = clsBankUser::Find(Names);
        while (ali._Name == "" )
        {
            cout << "This Account Number is not found , please Enter anohter Number \n\n\n";
            cout << "Enter an Account Number \n";
            cin >> Names;
            ali = clsBankUser::Find(Names);
        }
        ali.Print();
        cout<<"Do you want to Delete this Data ? \n";
        cin >> desire;
        if (tolower(desire) == 'y')
        {
            clsBankUser::DeleteUser(Names);
        }
    }
};