#pragma once
#include <iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsBankCleint.h"
#include"clsShowCleintScreen.h"
#include"clsAddNewCleint.h"
#include"clsDeleteCleint.h"
#include"clsUpdateCleintInfo.h"
#include"clsFindCleint.h"
#include"clsTransaction.h"
#include"clsManageUserScreen.h"
#include"clsLogInScreen.h"
#include"ShowRegistersList.h"
using namespace std;

/*
        if ((binaryPermsission[binaryPermsission.length()-1]-'0') == 1 || ali.Permssion == -1)
        {
        printCleintDataFromVector(allCleintData);
        break;
        }
        else
        {
            cout <<"This is not allowed for you , Please go to The Main Menu \n";
            break;
        }
*/

class clsMainScreen  : protected clsBankUser
{
    private : 
    
static string ConvertToBinary(int Num)
{
    float remider = 0;
    string result ="";
    for (int i = 0; Num > 0; i++)
    {
        remider = Num % 2 ;
        result = to_string(int(remider))+result;
        Num = Num / 2;
    }
    return result;
}

        enum clsBankOptions {ShowCleintsScreen=1,AddNewCleint=2,DeleteCleint=3,
        UpdateCleintInfo=4,FindCleint=5,Transaction=6,ManageUsers=7,RegisterList=8,LogOut=9 };
        static void performMainMenueScreen(clsBankOptions Choice , string user  , string pass)
        {
            clsBankUser ali = clsBankUser::Find(user);
            string binaryPermsission = ConvertToBinary(ali._Permssion);
            
            switch (Choice)
                {
                case clsBankOptions::ShowCleintsScreen :
                if ((binaryPermsission[binaryPermsission.length()-clsBankOptions::ShowCleintsScreen]-'0') == 1 || ali._Permssion == -1)
                {
                    clsShowCleintScreen::CleintsOfList();
                    break;
                }
                else
                {
                    cout <<"This is not allowed for you , Please go to The Main Menu \n";
                    break;
                }
                case clsBankOptions::AddNewCleint :
                if ((binaryPermsission[binaryPermsission.length()-clsBankOptions::AddNewCleint]-'0') == 1 || ali._Permssion == -1)
                {
                    clsAddNewCleint::AddNewClient();
                break;
                }
                else
                {
                    cout <<"This is not allowed for you , Please go to The Main Menu \n";
                    break;
                }
                case clsBankOptions::DeleteCleint :
                if ((binaryPermsission[binaryPermsission.length()-clsBankOptions::DeleteCleint]-'0') == 1 || ali._Permssion == -1)
                {
                    clsDeleteCleint::DeleteCleint();
                    break;
                }
                else
                {
                    cout <<"This is not allowed for you , Please go to The Main Menu \n";
                    break;
                }
                case clsBankOptions::UpdateCleintInfo :
                if ((binaryPermsission[binaryPermsission.length()-clsBankOptions::UpdateCleintInfo]-'0') == 1 || ali._Permssion == -1)
                {
                    clsUpdateCleintInfo::UpdateCleintInfo();
                    break;
                }
                else
                {
                    cout <<"This is not allowed for you , Please go to The Main Menu \n";
                    break;
                }
                case clsBankOptions::FindCleint :
                if ((binaryPermsission[binaryPermsission.length()-clsBankOptions::FindCleint]-'0') == 1 || ali._Permssion == -1)
                {
                    clsFindCleint::Find(clsInputValidate::readStirng("Enter Account Number "));
                    break;
                }
                else
                {
                    cout <<"This is not allowed for you , Please go to The Main Menu \n";
                    break;
                }
                case clsBankOptions::Transaction :
                if ((binaryPermsission[binaryPermsission.length()-clsBankOptions::Transaction]-'0') == 1 || ali._Permssion == -1)
                {
                    clsTransaction::_ShowTransactionMenue();
                    break;
                }
                else
                {
                    cout <<"This is not allowed for you , Please go to The Main Menu \n";
                    break;
                }
                case clsBankOptions::ManageUsers:
                if ((binaryPermsission[binaryPermsission.length()-clsBankOptions::ManageUsers]-'0') == 1 || ali._Permssion == -1)
                {
                    clsManageUserScreen::_ShowUserMenue();
                    break;
                }
                else
                {
                    cout <<"This is not allowed for you , Please go to The Main Menu \n";
                    break;
                }
                case clsBankOptions::RegisterList :
                if ((binaryPermsission[binaryPermsission.length()-clsBankOptions::RegisterList]-'0') == 1 || ali._Permssion == -1)
                {
                    ShowRegistersList::RegistersOfList();
                    break;
                }
                else
                {
                    cout <<"This is not allowed for you , Please go to The Main Menu \n";
                    break;
                }
                // cout << "Fuck it :'-) ManageUsers \n";
                case clsBankOptions::LogOut :
               //  clsLogInScreen::logInScreen();
                break;
                default:
                break;
                }
        }
    public : 

    static void _ShowMainMenue(string user  , string pass)
    {
        char desire;
        do
        {
            clsScreen::BigHeader("Main Screen");
            cout <<"           ====================================================================\n";
            cout <<"                                       Main Menue                             \n";
            cout <<"           ====================================================================\n";
            cout <<"           [1] Show Cleint Screen \n";
            cout <<"           [2] Add New Cleint  \n";
            cout <<"           [3] Delete Cleint  \n";
            cout <<"           [4] Update Cleint Info \n";
            cout <<"           [5] Find Cleint  \n";
            cout <<"           [6] Transaction   \n";
            cout <<"           [7] Manage Users \n";
            cout <<"           [8] Register List   \n";
            cout <<"           [9] Log Out   \n";
            cout <<"           ====================================================================\n";
            cout <<"           choose the option you want : [1-8]   \n";
            performMainMenueScreen((clsBankOptions)(clsInputValidate::ReadIntNumberBetween(1,8)) , user , pass);
            cout << "          Do you want to continue [y/n] ?  \n           ";
                cin >> desire;
        }while(tolower(desire) == 'y');
    }
};
