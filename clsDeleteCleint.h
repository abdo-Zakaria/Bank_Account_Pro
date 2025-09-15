#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsBankCleint.h"
using namespace std;

class clsDeleteCleint : public clsBankClient 
{
    public : 
    static  void DeleteCleint()
    {
        string AccountNumber;
        char desire ;
        cout << "Enter an Account Number \n";
        cin >> AccountNumber;
        clsBankClient ali = clsBankClient::Find(AccountNumber);
        while (ali._FirstName == "" )
        {
            cout << "This Account Number is not found , please Enter anohter Number \n\n\n";
            cout << "Enter an Account Number \n";
            cin >> AccountNumber;
            ali = clsBankClient::Find(AccountNumber);
        }
        ali.Print();
        cout<<"Do you want to Delete this Data ? \n";
        cin >> desire;
        if (tolower(desire) == 'y')
        {
            clsBankClient::DeleteClient(AccountNumber);
        }
    }
    
    
};