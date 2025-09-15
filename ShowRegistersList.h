#pragma once
#include <iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsRegister.h"
#include"clsBankUser.h"
using namespace std;
class ShowRegistersList
{
private:
    /* data */
public:

static void RegistersOfList()
    {
        vector<clsRegister> allClients  =  clsRegister::RegisterList();
        cout << "\nUsers List : ";
            cout <<setw(18)<< "\n___________________\n";
            cout << "Name   | " <<setw(6) ;
            cout << "Password    | " <<setw(7) ;
            cout << "Permission    | " <<setw(22) ;
            cout << "Date   | " <<setw(9);
            cout << "\n";
            cout <<endl;
            for (int i = 0; i < allClients.size() ; i++)
            {
            cout << allClients[i]._Name       <<setw(5) <<"|";//setw(8) ;
            cout << allClients[i]._Password        <<setw(3)<<"|" ;//setw(6) ;
            cout << allClients[i]._Permssion      <<setw(2) <<"|";//setw(14);
            cout << allClients[i]._date           <<setw(4)<<"|" ;//setw(7) ;
            cout <<endl;
            }
    }
};