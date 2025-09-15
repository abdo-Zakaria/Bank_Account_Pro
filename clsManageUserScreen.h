#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankUser.h"
#include"clsAddUser.h"
#include"clsUsersList.h"
#include"clsDeleteUser.h"
#include"clsUpdateUserData.h"
#include"clsFindUser.h"
using namespace std;

class clsManageUserScreen 
{
    private : 

     enum clsUserOptions {ShowUsersScreen=1,AddNewUser=2,DeleteUser=3,
        UpdateUserInfo=4,FindUser=5,MainMneue=6};
        static void performManageUserScreen(clsUserOptions Choice)
        {
                switch (Choice)
                {
                case clsUserOptions::ShowUsersScreen :
                // cout <<"ShowUsersScreen \n";
                clsUsersList::UserAllList();
                // clsShowCleintScreen::CleintsOfList();
                break;
                case clsUserOptions::AddNewUser :
                clsAddNewUser::AddNewUser();
                // cout <<"AddNewUser \n";
                // clsAddNewCleint::AddNewClient();
                break;
                case clsUserOptions::DeleteUser :
                clsDeleteUser::DeleteCleint();
                // cout <<"DeleteUser \n";
                // clsDeleteCleint::DeleteCleint();
                break;
                case clsUserOptions::UpdateUserInfo :
                clsUpdateUserData::UpdateCleintInfo();
                // cout <<"UpdateUserInfo \n";
                // clsUpdateCleintInfo::UpdateCleintInfo();
                break;
                case clsUserOptions::FindUser :
                clsFindUser::Find(clsInputValidate::readStirng("Enter User Name"));
                // cout <<"FindUser \n";
                // clsFindCleint::Find(clsInputValidate::readStirng("Enter Account Number "));
                break;
                case clsUserOptions::MainMneue :
                // clsTransaction::_ShowTransactionMenue();
                break;
                default:
                break;
                }
        }
    public : 

    static void _ShowUserMenue()
    {
        char desire;
        do
        {
            clsScreen::BigHeader("Manage User Screen");
            cout <<"           ====================================================================\n";
            cout <<"                                       Manage User                             \n";
            cout <<"           ====================================================================\n";
            cout <<"           [1] Show User Screen \n";
            cout <<"           [2] Add New User  \n";
            cout <<"           [3] Delete User  \n";
            cout <<"           [4] Update User Info \n";
            cout <<"           [5] Find User  \n";
            cout <<"           [6] Mai nMneue   \n";
            cout <<"           ====================================================================\n";
            cout <<"           choose the option you want : [1-6]   \n";
            performManageUserScreen((clsUserOptions)(clsInputValidate::ReadIntNumberBetween(1,6)));
                cout << "Do you want to continue In [ Manage -User- ]  ?  \n           ";
                cin >> desire;
        }while(tolower(desire) == 'y');
    }
};