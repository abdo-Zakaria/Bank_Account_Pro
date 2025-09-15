#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include"clsInputValidate.h"
#include <vector>
#include <fstream>

using namespace std;
class clsBankUser
{

    static string TextEncriptionMethod1(string name)
  {
    string textAfterEncription = "";
    for(int i = 0; i < name.length();i++)
    {
      textAfterEncription += char(int(name[i])+2);
    }
    
    return textAfterEncription;
  } // cout << TextEncriptionMethod1(readLetter())<<"\n";

  static string TextDecriptionMethod1(string name)
  {
    string TextDecription = "";
    for(int i = 0; i < name.length();i++)
    {
      TextDecription += char(int(name[i])-2);
    }
    return TextDecription;
  }// cout << TextDecriptionMethod1(TextEncriptionMethod1(readLetter()))<<"\n";

  protected:

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsBankUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pManageUsers;
        }
        cout << "\n RegisterList? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pShowRegisterList;
        }

        return Permissions;

    }

    static clsBankUser _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);
        vClientData[1] = TextDecriptionMethod1(vClientData[1]);
        return clsBankUser(enMode::UpdateMode, vClientData[0], vClientData[1], stoi(vClientData[2]) );

    };

    static string _ConverClientObjectToLine(clsBankUser User, string Seperator = "#//#")
    {
        User._Password = TextEncriptionMethod1(User._Password);
        string stClientRecord = "";
        stClientRecord += User._Name + Seperator;
        stClientRecord += User._Password + Seperator;
        stClientRecord += to_string(User._Permssion);

        return stClientRecord;

    }

    static  vector <clsBankUser> _LoadUsersDataFromFile()
    {

        vector <clsBankUser> vClients;

        fstream MyFile;
        MyFile.open("fileUser.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankUser Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveUsersDataToFile(vector <clsBankUser> vClients)
    {

        fstream MyFile;
        MyFile.open("fileUser.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankUser C : vClients)
            {
                if (C._Mode != 0)
                {
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();

        }

    }

    
        void _AddDataLineToFile(string  stDataLine)
        {
            fstream MyFile;
            MyFile.open("fileUser.txt", ios::out | ios::app);
    
            if (MyFile.is_open())
            {
    
                MyFile << stDataLine << endl;
    
                MyFile.close();
            }
    
        }

    void _Update()
    {
        vector <clsBankUser> _vClients;
        _vClients = _LoadUsersDataFromFile();

        for (clsBankUser& C : _vClients)
        {
            if (C._Name == GetName())
            {
                C = *this;
                break;
            }    

        }    

        _SaveUsersDataToFile(_vClients);

    }        
    static clsBankUser _GetEmptyUserObject()
    {
        return clsBankUser(enMode::EmptyMode, "", "",0);
    }

    protected:
    enum enMode { EmptyMode = 0, UpdateMode = 1 };
    enum enPermissions {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64 , pShowRegisterList=128
    };


public:
enMode _Mode;
string _Name;
string _Password;
int _Permssion;

clsBankUser(enMode Mode, string Name, string Password,int Permssion)
        

    {
        _Mode      = Mode;
        _Name      = Name;
        _Password  = Password;
        _Permssion = Permssion;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    void SetName(string Name)
    {
        _Name = Name;
    }

    string GetName()
    {
        return _Name;
    }
    
    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }
    
    void SetPermssion(int Permssion)
    {
        _Permssion = Permssion;
    }

    float GetPermssion()
    {
        return _Permssion;
    }
    #ifdef _MSC_VER
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;
   
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;
    #endif
    
    void Print()
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nName   : " << _Name;
        cout << "\nPassword    : " << _Password;
        cout << "\nPermssion       : " << _Permssion;
        cout << "\n___________________\n";

    }


   static clsBankUser Find(string Name)
    {
       

        fstream MyFile;
        MyFile.open("fileUser.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankUser User = _ConvertLinetoClientObject(Line);
                if (User._Name == Name)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _GetEmptyUserObject();
    }

    static clsBankUser Find(string Name, string Password)
    {
        fstream MyFile;
        MyFile.open("fileUser.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankUser User = _ConvertLinetoClientObject(Line);
                if (User._Name == Name && User._Password == Password)
                {
                    MyFile.close();
                    return User;
                }
            
            }

            MyFile.close();

        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
        
                return enSaveResults::svFaildEmptyObject;
        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }


        }



    }

    static bool IsUserExist(string AccountNumber)
    {

        clsBankUser User1 = clsBankUser::Find(AccountNumber);
        
        return (!User1.IsEmpty());
    }
    static bool IsUserExist(string AccountNumber,string Password)
    {

        clsBankUser User1 = clsBankUser::Find(AccountNumber,Password);
        
        return (!User1.IsEmpty());
    }


    static void up(clsBankUser& User)
    {
        User._Mode = enMode::UpdateMode;
        cout << "Enter your User name \n";
        cin >>ws>> User._Name;
        cout << "Enter your User Password \n";
        cin >>ws>> User._Password;
        cout << "Enter your Permssion  \n";
        User._Permssion =_ReadPermissionsToSet();
       // cleint.AccountNumber() = clsInputValidate::readStirng("Enter Account number \n");
    } 

    static void UpdateUser(string Name)
    {
        vector<clsBankUser> allCLeints = _LoadUsersDataFromFile();
        for (int i = 0; i < allCLeints.size(); i++)
        {
            if ( allCLeints[i]._Name == Name)
            {
                up(allCLeints[i]);
            }
        }
        _SaveUsersDataToFile(allCLeints);
    }

    static void DeleteUser(string Name)
    {
        vector<clsBankUser> allCLeints = _LoadUsersDataFromFile();
        for (int i = 0; i < allCLeints.size(); i++)
        {
            if ( allCLeints[i]._Name == Name)
            {
                allCLeints[i] = clsBankUser::_GetEmptyUserObject();
            }
        }
        _SaveUsersDataToFile(allCLeints);
    }

    // static void  Deposite(string AccountNumber,int DepositeBalance)
    // {
    //     vector<clsBankUser> allCLeints = _LoadClientsDataFromFile();
    //     for (int i = 0; i < allCLeints.size(); i++)
    //     {
    //         if ( allCLeints[i].AccountNumber() == AccountNumber)
    //         {
    //             allCLeints[i]._AccountBalance += DepositeBalance;
    //             // AccountNumber = allCLeints[i]._AccountBalance;
    //         }
    //     }
    //     _SaveCleintsDataToFile(allCLeints);
    // }

    // static void Withdraw(string AccountNumber,int WithdrawBalance)
    // {
    //     vector<clsBankUser> allCLeints = _LoadClientsDataFromFile();
    //     for (int i = 0; i < allCLeints.size(); i++)
    //     {
    //         if ( allCLeints[i].AccountNumber() == AccountNumber)
    //         {
    //             allCLeints[i]._AccountBalance = allCLeints[i]._AccountBalance - WithdrawBalance;
    //         }
    //     }
    //     _SaveCleintsDataToFile(allCLeints);
    // }


    static clsBankUser NewUser()
    {
        vector<clsBankUser> allCLeints = _LoadUsersDataFromFile();
        clsBankUser CLeint =  clsBankUser::_GetEmptyUserObject();
            // CLeint._Name = clsInputValidate::readStirng("Enter Name ");
            up(CLeint);
        allCLeints.push_back(CLeint);
        _SaveUsersDataToFile(allCLeints);
        return CLeint;
    }
    
    static vector<clsBankUser> UserList()
    {
        vector<clsBankUser> allCLeints = _LoadUsersDataFromFile();
        return allCLeints;
    }

};


