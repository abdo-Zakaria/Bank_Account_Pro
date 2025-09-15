#pragma once
#include <iostream>
#include"clsBankCleint.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;

class clsAddNewCleint : public clsBankClient
{
    public : 

    static void AddNewClient()
    {
        char desire ;
        cout << "Do you want to add new cleint ? \n";
        cin >> ws >> desire;
        while (tolower(desire) == 'y')
        {
            clsBankClient ali = clsBankClient::NewCleint();
            cout << "The New Cleint is : \n";
            ali.Print();
            cout << "\n Do you want to add new cleint ? \n";
            cin >> ws >> desire;
        }

    }

};