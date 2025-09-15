#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsBankCleint.h"
#include"clsDeposite.h"
#include"clsWithdraw.h"
#include"clsTransfer.h"
#include"clsTotalBalances.h"
using namespace std;

class clsTransaction : public clsBankClient 
{
    private:
    
    
    enum clsTransactionOptions {Deposite=1,Withdraw=2,TotalBalances=3,Transfer=4,LogOut=5};
        static void performTransactionMenueScreen(clsTransactionOptions Choice)
        {
                switch (Choice)
                {
                case clsTransactionOptions::Deposite :
                clsDeposite::Deposite();
                //cout << "Deposite \n";
                break;
                case clsTransactionOptions::Withdraw :
                clsWithdraw::Withdraw();
                // cout << "Withdraw \n";
                break;
                case clsTransactionOptions::TotalBalances :
                clsTotalBalances::TotalBalances();
                // cout << "TotalBalances \n";
                break;
                case clsTransactionOptions::Transfer :
                clsTransfer::Transfer();
                // cout << "Transfer \n";
                break;
                case clsTransactionOptions::LogOut :
                break;
                default:
                break;
                }
        }
    public:
    static void _ShowTransactionMenue()
    {
        char desire;
        do
        {
            cout <<"           ====================================================================\n";
            cout <<"                                   Transactions Menue                             \n";
            cout <<"           ====================================================================\n";
            cout <<"           [1] Deposite \n";
            cout <<"           [2] Withdraw  \n";
            cout <<"           [3] Show TotalBalances Screen  \n";
            cout <<"           [4] Transfer  \n";
            cout <<"           [5] Log Out   \n";
            cout <<"           ====================================================================\n";
            cout <<"           choose the option you want : [1-4]   \n";
            performTransactionMenueScreen((clsTransactionOptions)(clsInputValidate::ReadIntNumberBetween(1,4)));
                cout << "Do you want to continue In Transaction ?  \n";
                cin >>ws>> desire;
        }while(tolower(desire) == 'y');
    }
    
};