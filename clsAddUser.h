#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsBankUser.h"
using namespace std;

class clsAddNewUser 
{
    public : 

    static void AddNewUser()
    {
        char desire ;
        cout << "Do you want to add new User ? \n";
        cin >> ws >> desire;
        while (tolower(desire) == 'y')
        {
            clsBankUser ali = clsBankUser::NewUser();
            cout << "The New User is : \n";
            ali.Print();
            cout << "\n Do you want to add new User ? \n";
            cin >> ws >> desire;
        }

    }

};