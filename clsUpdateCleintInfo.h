#pragma once
#include <iostream>
#include<fstream>
#include<string>
#include <iomanip>
#include"clsPeriod.h"
#include<vector>
#include"clsBankCleint.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
using namespace std;

class clsUpdateCleintInfo : public clsBankClient 
{
    public: 

    static void UpdateCleintInfo()
    {
        string AccountNumber = clsInputValidate::readStirng("Enter the Account Number ");
        char desire ;
        clsBankClient ali = clsBankClient::Find(AccountNumber);
        while (ali._FirstName == "" )
        {
            cout << "This Account Number is not found , please Enter anohter Number \n\n\n";
            cout << "Enter an Account Number \n";
            cin >> AccountNumber;
            ali = clsBankClient::Find(AccountNumber);
        }
        ali.Print();
        cout<<"Do you want to update this Data ? \n";
        cin >> desire;
        if (tolower(desire) == 'y')
        {
            clsBankClient::UpdateClient(AccountNumber);
        }
        
    }
};  