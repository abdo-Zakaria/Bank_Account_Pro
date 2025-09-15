#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsBankCleint.h"
using namespace std;

class clsDeposite
{
    private:
    public:
    static void Deposite()
    {

        char desireToDepsoite= 'y';
        int DepositeBalance = 0;
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
        
        cout<<"\nare you srue to Deposite => Yes[y] or No[n] ?  "; cin >> desireToDepsoite;

        if (tolower(char(desireToDepsoite)) == 'y')
        {
            cout <<"Balance you want to Deposite : "; cin >> DepositeBalance;cout<<endl;
            clsBankClient::Deposite(AccountNumber,DepositeBalance);
            cout << "Your New Balance is:  "<<ali._AccountBalance+DepositeBalance<<endl;
        }
    }
};
// fstream BankFile;
// BankFile.open(fileName,ios::out);
// if (BankFile.is_open())
// {
// string cleintDataInString;
//     for (int  i = 0; i < allCleintData.size(); i++)
//     {
//         if (allCleintData[i].AccountNumber == AccountNumber)
//         {
//             cout <<"Balance you want to Deposite : "; cin >> DepositeBalance;cout<<endl;
//             allCleintData[i].AccountBalance = allCleintData[i].AccountBalance + DepositeBalance;
//             cleintDataInString = ConvertStructureToString(allCleintData[i]);
//             BankFile << cleintDataInString<<endl;
//         }
//         else
//         {
//             cleintDataInString = ConvertStructureToString(allCleintData[i]);
//             BankFile << cleintDataInString<<endl;
//         }
//     }
//     BankFile.close();
// }