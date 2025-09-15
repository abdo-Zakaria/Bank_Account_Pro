#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsBankCleint.h"
#include"clsTransferLog.h"
 #include"clsTransferLog.h"
using namespace std;

class clsTransfer
{
    private:
    public:
    static void Transfer()
    {

        char desireToDepsoite= 'y';
        int DepositeBalance = 0;
        string AccountNumber1;
        string AccountNumber2;
        cout << "Enter an Account Number \n";
        cin >> AccountNumber1;
        clsBankClient User1 = clsBankClient::Find(AccountNumber1);
        while (User1._FirstName == "" )
        {
            cout << "This Account Number is not found , please Enter anohter Number \n\n\n";
            cout << "Enter an Account Number \n";
            cin >> AccountNumber1;
            User1 = clsBankClient::Find(AccountNumber1);
        }
        cout<<endl;
        User1.Print();

        cout << "Enter an Account Number \n";
        cin >> AccountNumber2;
        clsBankClient User2 = clsBankClient::Find(AccountNumber2);
        while (User2._FirstName == "" )
        {
            cout << "This Account Number is not found , please Enter anohter Number \n\n\n";
            cout << "Enter an Account Number \n";
            cin >> AccountNumber2;
            User2 = clsBankClient::Find(AccountNumber2);
        }
        cout<<endl;
        User2.Print();

        cout<<"\nare you srue to Transfer => Yes[y] or No[n] ?  "; cin >> desireToDepsoite;
        // function to validate the money transfered is in the range
        if (tolower(char(desireToDepsoite)) == 'y')
        {
            cout <<"Balance you want to Transfer : "; cin >> DepositeBalance;cout<<endl;
            clsBankClient::Withdraw(AccountNumber1,DepositeBalance);
            clsBankClient::Deposite(AccountNumber2,DepositeBalance);
            cout << "Full Name   : "<<User1.FullName() <<"\n" ;
        cout << "Acc. Number  : "<< User1.AccountNumber()<<endl ;
        cout << "Balance      :"<<User1._AccountBalance-DepositeBalance<<endl;
        cout << "Full Name   : "<<User2.FullName() <<"\n" ;
        cout << "Acc. Number  : "<< User2.AccountNumber()<<endl ;
        cout << "Balance      :"<<User2._AccountBalance+DepositeBalance<<endl;
            // cout << "Your New Balance is:  "<<ali._AccountBalance+DepositeBalance<<endl;
        clsTransferLog::fromUserToclsTransferLog(AccountNumber1,AccountNumber2,DepositeBalance);
        }
    }

};
//clsTransfer.