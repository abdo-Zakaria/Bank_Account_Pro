#pragma once
#include <iostream>
#include <iomanip>
#include"clsScreen.h"
#include"clsBankCleint.h"
using namespace std;

class clsTotalBalances 
{
    public: 

    static void TotalBalances() {
        vector<clsBankClient> allClients = clsBankClient::CleintsList();
        vector<string> headers = {"Full Name", "Acc. Number", "Balance"};

        // حساب أطوال الأعمدة
        vector<size_t> widths(headers.size(), 0);
        for (size_t i = 0; i < headers.size(); i++) {
            widths[i] = headers[i].size();
        }

        for (clsBankClient  &c : allClients) {
            widths[0] = max(widths[0], c.FullName().size());
            widths[1] = max(widths[1], c.AccountNumber().size());
            widths[2] = max(widths[2], to_string(c._AccountBalance).size());
        }

        // طباعة العناوين
        cout << "\nClient List:\n";
        for (size_t i = 0; i < headers.size(); i++) {
            cout << left << setw(widths[i] + 3) << headers[i] << "| ";
        }
        cout << "\n";

        // خط فاصل
        int totalWidth = 0;
        for (int w : widths) totalWidth += w + 3;
        cout << string(totalWidth + headers.size() * 2, '-') << "\n";

        // طباعة البيانات
        int totalBalance = 0;
        for (clsBankClient  &c : allClients) {
            cout << left << setw(widths[0] + 3) << c.FullName() << "| ";
            cout << left << setw(widths[1] + 3) << c.AccountNumber() << "| ";
            cout << left << setw(widths[2] + 3) << c._AccountBalance << "| ";
            cout << "\n";
            totalBalance += c._AccountBalance;
        }

        // خط تحت البيانات
        cout << string(totalWidth + headers.size() * 2, '-') << "\n";

        // طباعة الإجمالي
        cout << left << setw(widths[0] + widths[1] + 8) << "Total Balances" 
             << "| " << totalBalance << "\n";
    }
    
    // static void TotalBalances()
    // {
    //     int totalBalance = 0;
    //     vector<clsBankClient> allClients  =  clsBankClient::CleintsList();
    //     cout << "\nClient List : ";
    //         cout <<setw(18)<< "\n___________________\n";
    //         cout << "Full Name   | " <<setw(9);
    //         cout << "Acc. Number | " <<setw(7) ;
    //         cout << "Balance      \n";
    //         cout <<endl;
    //         for (int i = 0; i < allClients.size() ; i++)
    //         {
    //         cout << allClients[i].FullName()       <<setw(2) <<"|";//setw(14);
    //         cout << allClients[i].AccountNumber()  <<setw(10) <<"|";//setw(4) ;
    //         cout << allClients[i]._AccountBalance  <<setw(7);//setw(5) ;
    //         cout <<endl;
    //         totalBalance += allClients[i]._AccountBalance;
    //         }
    //             cout <<"                 Total Balances are = [["<<totalBalance<<"]]"<<endl;
    // }
};