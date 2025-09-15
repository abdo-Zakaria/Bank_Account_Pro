#pragma once
#include <iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankUser.h"
using namespace std;
class clsRegister :public  clsBankUser
{
private:

static clsRegister _ConvertLinetoClientRegisterObject(string Line, string Seperator = "#//#")
{
    vector<string> vRegisterData;
    vRegisterData = clsString::Split(Line, Seperator);
    return clsRegister(enMode::UpdateMode, vRegisterData[0], vRegisterData[1], stoi(vRegisterData[2]), vRegisterData[3]);

};

static string _ConverClientRegisterObjectToLine(clsRegister User, string Seperator = "#//#")
{

    string stClientRecord = "";
    stClientRecord += User._Name + Seperator;
    stClientRecord += User._Password + Seperator;
    stClientRecord += to_string(User._Permssion)+Seperator;
    stClientRecord += User._date;
    return stClientRecord;

}

static  vector <clsRegister> _LoadUsersRegisterDataFromFile()
{

    vector <clsRegister> vClients;

    fstream MyFile;
    MyFile.open("fileUserREgister.txt", ios::in);//read Mode

    if (MyFile.is_open())
    {

        string Line;


        while (getline(MyFile, Line))
        {

            clsRegister Client = _ConvertLinetoClientRegisterObject(Line);

            vClients.push_back(Client);
        }

        MyFile.close();

    }

    return vClients;

}

static void _SaveUsersRegistersDataToFile(vector <clsRegister> vClients)
{

    fstream MyFile;
    MyFile.open("fileUserREgister.txt", ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {

        for (clsRegister C : vClients)
        {
            if (C._Mode != 0)
            {
                DataLine = _ConverClientRegisterObjectToLine(C);
                MyFile << DataLine << endl;
            }
        }

        MyFile.close();

    }

}

public:
string _date;

clsRegister(enMode Mode, string Name, string Password,int Permssion, string date) :
clsBankUser( Mode,  Name,  Password, Permssion)
{  
    _Mode=Mode;  _Name=Name;  _Password=Password; _Permssion=Permssion;  _date=date;
    
}
static void fromUserToRegister(string name , string Password)
{
    clsBankUser ali = clsBankUser::Find( name ,Password);
    clsRegister hani(ali._Mode , ali._Name , ali._Password ,ali._Permssion,clsDate::DateToString(clsDate::GetSystemDate()));
    vector<clsRegister> vRegisters = _LoadUsersRegisterDataFromFile();
    vRegisters.push_back(hani);
    _SaveUsersRegistersDataToFile(vRegisters);
}
static vector<clsRegister> RegisterList()
{
    return _LoadUsersRegisterDataFromFile();
}

};



/*// clsRegister();
// static void fromUserToRegister(string name , string Password)
// {
//     vector<clsRegister> vRegisters = _LoadUsersRegisterDataFromFile();
//     clsBankUser ali = clsBankUser::Find( name ,Password);
//     clsRegister hani;
//     hani._Name = ali._Name;
//     hani._Password = ali._Password;
//     hani._Permssion=  ali._Permssion;
//     hani._date =  clsDate::DateToString(clsDate::GetSystemDate());
//     vRegisters.push_back(hani);
//     _SaveUsersRegistersDataToFile();
// }

/*/// clsRegister()
// {
//    _date = "";
//      _Mode= enMode::EmptyMode;   _Name="";   _Password="";  _Permssion=0;   _date="";
// };


