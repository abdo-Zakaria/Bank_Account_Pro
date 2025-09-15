#pragma once
#include <iostream>
#include"clsMainScreen.h"
#include"clsBankUser.h"
#include"clsManageUserScreen.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsDate.h"
#include"clsRegister.h"
using namespace std;

class clsLogInScreen  
{
private:
    
public:

    static void logInScreen()
    {

        string _UserName;
        string _PassWord;
        clsScreen::BigHeader("Log In Screen");
            cout <<"           ====================================================================\n";
            cout <<"                                       Log In                             \n";
            cout <<"           ====================================================================\n";
            cout << "           User : \n";
            cout << "           Date : "<<clsDate::DateToString(clsDate::GetSystemDate())<<endl;
            cout << "           Enter here the User Name \n           ";
            cin >> _UserName;
            cout <<"           ====================================================================\n";

            cout << "           Enter here the User Password \n           ";
            cin >> _PassWord;
        
        while ( !(clsBankUser::IsUserExist(_UserName,_PassWord)))
        {
            cout << "           Sorry , There is wrong Email or Password \n";
            cout <<"           Enter here the User Name \n           ";
            cin >> _UserName;
            cout <<"           ====================================================================\n";
            cout << "           Enter here the User Password \n           ";
            cin >> _PassWord;
        }
        cout << "           User : "<<_UserName<<endl;
        cout << "           Date : "<<clsDate::DateToString(clsDate::GetSystemDate())<<endl;
        clsRegister::fromUserToRegister(_UserName,_PassWord);
        clsMainScreen::_ShowMainMenue(_UserName,_PassWord);
    }
};

// clsLogInScreen::logInScreen();