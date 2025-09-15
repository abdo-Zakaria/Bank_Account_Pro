#pragma once
#include <iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankUser.h"
#include<string>
using namespace std;
class clsTransferLog
{
private:

static clsTransferLog _ConvertLinetoClientclsTransferLogObject(string Line, string Seperator = "#//#")
{
    vector<std::string> vRegisterData;
    vRegisterData = clsString::Split(Line, Seperator);
    return clsTransferLog (vRegisterData[0],vRegisterData[1],vRegisterData[2],
        stoi(vRegisterData[3]), stoi(vRegisterData[4]),stoi(vRegisterData[5]));

};

static string _ConverClientclsTransferLogObjectToLine(clsTransferLog User, string Seperator = "#//#")
{

    std::string stClientRecord = "";
    stClientRecord += User._date + Seperator;
    stClientRecord += User._Account_Number1 + Seperator;
    stClientRecord += User._Account_Number2 + Seperator;
    stClientRecord += to_string(User._TransferedMoney)+Seperator;
    stClientRecord += to_string(User._User1_Balances)+Seperator;
    stClientRecord += to_string(User._User2_Balances);
    return stClientRecord;

}

static  vector <clsTransferLog> _LoadUsersclsTransferLogDataFromFile()
{

    vector <clsTransferLog> vClients;

    fstream MyFile;
    MyFile.open("FileTransferDate.txt", ios::in);//read Mode

    if (MyFile.is_open())
    {

        std::string Line;


        while (getline(MyFile, Line))
        {

            clsTransferLog Client = _ConvertLinetoClientclsTransferLogObject(Line);

            vClients.push_back(Client);
        }

        MyFile.close();

    }

    return vClients;

}

static void _SaveUsersclsTransferLogDataToFile(vector <clsTransferLog> vClients)
{

    fstream MyFile;
    MyFile.open("FileTransferDate.txt", ios::out);//overwrite

    std::string DataLine;

    if (MyFile.is_open())
    {

        for (clsTransferLog C : vClients)
        {
            
                DataLine = _ConverClientclsTransferLogObjectToLine(C);
                MyFile << DataLine << endl;
        }

        MyFile.close();

    }

}

 public:
    string _date;
    string _Account_Number1,string ,_Account_Number2;
    float _TransferedMoney;
    float _User1_Balances;
    float _User2_Balances;
    clsTransferLog(std::string date ,std::string Account_Number1,std::string Account_Number2, float TransferedMoney,float User1_Balances , float User2_Balances)
    {  
        _Account_Number1 = Account_Number1;
        _Account_Number2 = Account_Number2;
        _TransferedMoney = TransferedMoney;
        _User1_Balances= User1_Balances;
        _User2_Balances=User2_Balances ;
        _date = date;
    };
//     clsTransferLog()
//     {
//         _date = "d";
//     }

static void fromUserToclsTransferLog(std::string Acc1 ,std::string Acc2, int Transfered)
{
    clsBankClient User1 = clsBankClient::Find(Acc1);
    clsBankClient User2 = clsBankClient::Find(Acc2);
    clsTransferLog hani( clsDate::DateToString(clsDate::GetSystemDate()), User1._AccountNumber,User2._AccountNumber 
                        ,Transfered,User1.GetAccountBalance(),User2.GetAccountBalance());
        vector<clsTransferLog> vRegisters = _LoadUsersclsTransferLogDataFromFile();
        vRegisters.push_back(hani);
            _SaveUsersclsTransferLogDataToFile(vRegisters);
}
static vector<clsTransferLog> TransterList()
{
    return _LoadUsersclsTransferLogDataFromFile();
}
// static void ali(clsTransferLog ali)
// {
    
//     cout<<"Alo";
// }
};

