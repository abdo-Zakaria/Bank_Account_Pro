#pragma once
#include <iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankUser.h"
using namespace std;




class clsUsersList 
{
    public:
    // static void UserAllList()
    // {
    //     vector<clsBankUser> allClients  =  clsBankUser::UserList();
    //     cout << "\nClient List : ";
    //         cout <<setw(18)<< "\n___________________\n";
    //         cout << "Name   | " <<setw(6) ;
    //         cout << "Password    | " <<setw(7) ;
    //         cout << "Persmission      \n";
    //         cout <<endl;
    //         for (int i = 0; i < allClients.size() ; i++)
    //         {
    //         cout << allClients[i]._Name       <<setw(5) <<"|";//setw(8) ;
    //         cout << allClients[i]._Password        <<setw(3)<<"|" ;//setw(6) ;
    //         cout << allClients[i]._Permssion         <<setw(10) <<"|";//setw(5) ;
    //         cout <<endl;
    //         }
    // }
     static void UserAllList() {
        vector<clsBankUser> allClients = clsBankUser::UserList();

        // أسماء الأعمدة
        vector<string> headers = {"Name", "Password", "Permission"};

        // حساب طول الأعمدة
        vector<size_t> widths(headers.size(), 0);
        for (size_t i = 0; i < headers.size(); i++) {
            widths[i] = headers[i].size();
        }

        for (const auto &u : allClients) {
            widths[0] = max(widths[0], u._Name.size());
            widths[1] = max(widths[1], u._Password.size());
            widths[2] = max(widths[2], to_string(u._Permssion).size());
        }

        // طباعة العناوين
        cout << "\nClient List:\n";
        for (size_t i = 0; i < headers.size(); i++) {
            cout << left << setw(widths[i] + 3) << headers[i] << "| ";
        }
        cout << "\n";

        // خط فاصل
        size_t totalWidth = 0;
        for (auto w : widths) totalWidth += w + 3;
        cout << string(totalWidth + headers.size() * 2, '-') << "\n";

        // طباعة المستخدمين
        for (const auto &u : allClients) {
            cout << left << setw(widths[0] + 3) << u._Name << "| ";
            cout << left << setw(widths[1] + 3) << u._Password << "| ";
            cout << left << setw(widths[2] + 3) << u._Permssion << "| ";
            cout << "\n";
        }
    }
};