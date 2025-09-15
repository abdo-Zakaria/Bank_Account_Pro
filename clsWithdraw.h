#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsBankCleint.h"
using namespace std;

class clsWithdraw
{
    private:
    public:
    static void Withdraw()
    {

        char desireToWithdraw= 'y';
        int WithdrawBalance = 0;
        string AccountNumber;
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
        cout << "Full Name   : "<<ali.FullName() <<"\n" ;
        cout << "Acc. Number  : "<< ali.AccountNumber()<<endl ;
        cout << "Balance      :"<<ali._AccountBalance<<endl;

        cout<<"\nare you srue to Withdraw => Yes[y] or No[n] ?  "; cin >> desireToWithdraw;

        if (tolower(char(desireToWithdraw)) == 'y')
        {
            cout <<"Balance you want to Withdraw : "; cin >> WithdrawBalance;cout<<endl;
            while (WithdrawBalance > (ali._AccountBalance))
                {
                    cout<<"Sorry the Balance you want is Bigger Than The Total Balance : "<<ali._AccountBalance<<endl; 
                    cout <<"Balance you want to WithDraw : "; cin >> WithdrawBalance;
                }
            clsBankClient::Withdraw(AccountNumber,WithdrawBalance);
        }
        cout << "Your New Balance is: "<<ali._AccountBalance-WithdrawBalance<<endl;
    }
};