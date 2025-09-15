#pragma once
#include <iostream>
#include <iomanip>
#include"clsScreen.h"
#include"clsBankCleint.h"
using namespace std;

class clsShowCleintScreen :protected clsBankClient
{
    public: 

    
   
static void CleintsOfList() {
        vector<clsBankClient> allClients  =  clsBankClient::CleintsList();

        // أسماء الأعمدة
        vector<string> headers = {
            "FirstName", "LastName", "Full Name", "Email", "Phone", "Acc. Number", "Password", "Balance"
        };

        // حساب طول الأعمدة
        vector<size_t> widths(headers.size(), 0);
        for (size_t i = 0; i < headers.size(); i++) {
            widths[i] = headers[i].size();
        }

        for (clsBankClient  &c : allClients) {
            widths[0] = max(widths[0], c._FirstName.size());
            widths[1] = max(widths[1], c._LastName.size());
            widths[2] = max(widths[2], c.FullName().size());
            widths[3] = max(widths[3], c._Email.size());
            widths[4] = max(widths[4], c._Phone.size());
            widths[5] = max(widths[5], c._AccountNumber.size());
            widths[6] = max(widths[6], c._PinCode.size());
            widths[7] = max(widths[7], to_string(c._AccountBalance).size());
        }

        // طباعة العناوين
        cout << "\nClient List:\n";
        for (size_t i = 0; i < headers.size(); i++) {
            cout << left << setw(widths[i] + 3) << headers[i] << "| ";
        }
        cout << "\n";

        // خط فاصل
        size_t totalWidth = 0;
        for (int w : widths) totalWidth += w + 3;
        cout << string(totalWidth + headers.size() * 2, '-') << "\n";

        // طباعة العملاء
        for ( clsBankClient &c : allClients) {
            cout << left << setw(widths[0] + 3) << c._FirstName << "| ";
            cout << left << setw(widths[1] + 3) << c._LastName << "| ";
            cout << left << setw(widths[2] + 3) << c.FullName() << "| ";
            cout << left << setw(widths[3] + 3) << c._Email << "| ";
            cout << left << setw(widths[4] + 3) << c._Phone << "| ";
            cout << left << setw(widths[5] + 3) << c._AccountNumber << "| ";
            cout << left << setw(widths[6] + 3) << c._PinCode << "| ";
            cout << left << setw(widths[7] + 3) << c._AccountBalance << "| ";
            cout << "\n";
        }
    }

};
