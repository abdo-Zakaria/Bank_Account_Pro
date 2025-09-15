// #pragma once
// #include <iostream>
// #include <string>
// #include "clsPerson.h"
// #include "clsString.h"
// #include <vector>
// #include <fstream>

// using namespace std;

// class clsBankClient : public clsPerson
// {
// private:

//     enum enMode { EmptyMode = 0, UpdateMode = 1 };
//     enMode _Mode;


//     string _AccountNumber;
//     string _PinCode;
//     float _AccountBalance;

//     static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
//     {
//         vector<string> vClientData;
//         vClientData = clsString::Split(Line, Seperator);

//         return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
//             vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

//     }

//     static clsBankClient _GetEmptyClientObject()
//     {
//         return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
//     }

// public:

//     clsBankClient(enMode Mode, string FirstName, string LastName,
//         string Email, string Phone, string AccountNumber, string PinCode,
//         float AccountBalance) :
//         clsPerson(FirstName, LastName, Email, Phone)

//     {
//         _Mode = Mode;
//         _AccountNumber = AccountNumber;
//         _PinCode = PinCode;
//         _AccountBalance = AccountBalance;

//     }

//     bool IsEmpty()
//     {
//         return (_Mode == enMode::EmptyMode);
//     }


//     string AccountNumber()
//     {
//         return _AccountNumber;
//     }

//     void SetPinCode(string PinCode)
//     {
//         _PinCode = PinCode;
//     }

//     string GetPinCode()
//     {
//         return _PinCode;
//     }
//     __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

//     void SetAccountBalance(float AccountBalance)
//     {
//         _AccountBalance = AccountBalance;
//     }

//     float GetAccountBalance()
//     {
//         return _AccountBalance;
//     }
//     __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

//     void Print()
//     {
//         cout << "\nClient Card:";
//         cout << "\n___________________";
//         cout << "\nFirstName   : " << FirstName;
//         cout << "\nLastName    : " << LastName;
//         cout << "\nFull Name   : " << FullName();
//         cout << "\nEmail       : " << Email;
//         cout << "\nPhone       : " << Phone;
//         cout << "\nAcc. Number : " << _AccountNumber;
//         cout << "\nPassword    : " << _PinCode;
//         cout << "\nBalance     : " << _AccountBalance;
//         cout << "\n___________________\n";

//     }

   #pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include"clsInputValidate.h"
#include <vector>
#include <fstream>

using namespace std;
class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1 };
  

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

    }

    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client._FirstName + Seperator;
        stClientRecord += Client._LastName + Seperator;
        stClientRecord += Client._Email + Seperator;
        stClientRecord += Client._Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client._PinCode + Seperator;
        stClientRecord += to_string(Client._AccountBalance);

        return stClientRecord;

    }

    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C.AccountNumber() != "")
                {
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:
enMode _Mode;
string _AccountNumber;
string _PinCode;
float _AccountBalance;

    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }


    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    
    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }
    
    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    #ifdef _MSC_VER
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;
   
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;
    #endif
    
    void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << _FirstName;
        cout << "\nLastName    : " << _LastName;
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << _Email;
        cout << "\nPhone       : " << _Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";

    }


   static clsBankClient Find(string AccountNumber)
    {
       

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {

     

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client._PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
              
            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
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

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        
        return (!Client1.IsEmpty());
    }

    static void up(clsBankClient& cleint)
    {
        cout << "Enter your First name \n";
        cin >>ws>> cleint._FirstName;
        cout << "Enter your Last name \n";
        cin >>ws>> cleint._LastName;
        cout << "Enter your Email  \n";
        cin >>ws>> cleint._Email;
        cout << "Enter your Phone  \n";
        cin >>ws>> cleint._Phone;
        cout << "Enter your Pincode  \n";
        cin >>ws>> cleint._PinCode;
        cout << "Enter your Account Balance  \n";
        cin >>ws>> cleint._AccountBalance;
       // cleint.AccountNumber() = clsInputValidate::readStirng("Enter Account number \n");
    } 

    static void UpdateClient(string AccountNumber)
    {
        vector<clsBankClient> allCLeints = _LoadClientsDataFromFile();
        for (int i = 0; i < allCLeints.size(); i++)
        {
            if ( allCLeints[i].AccountNumber() == AccountNumber)
            {
                up(allCLeints[i]);
            }
        }
        _SaveCleintsDataToFile(allCLeints);
    }

    static void DeleteClient(string AccountNumber)
    {
        vector<clsBankClient> allCLeints = _LoadClientsDataFromFile();
        for (int i = 0; i < allCLeints.size(); i++)
        {
            if ( allCLeints[i].AccountNumber() == AccountNumber)
            {
                allCLeints[i] = clsBankClient::_GetEmptyClientObject();
            }
        }
        _SaveCleintsDataToFile(allCLeints);
    }
    static void  Deposite(string AccountNumber,int DepositeBalance)
    {
        vector<clsBankClient> allCLeints = _LoadClientsDataFromFile();
        for (int i = 0; i < allCLeints.size(); i++)
        {
            if ( allCLeints[i].AccountNumber() == AccountNumber)
            {
                allCLeints[i]._AccountBalance += DepositeBalance;
                // AccountNumber = allCLeints[i]._AccountBalance;
            }
        }
        _SaveCleintsDataToFile(allCLeints);
    }
    static void Withdraw(string AccountNumber,int WithdrawBalance)
    {
        vector<clsBankClient> allCLeints = _LoadClientsDataFromFile();
        for (int i = 0; i < allCLeints.size(); i++)
        {
            if ( allCLeints[i].AccountNumber() == AccountNumber)
            {
                allCLeints[i]._AccountBalance = allCLeints[i]._AccountBalance - WithdrawBalance;
            }
        }
        _SaveCleintsDataToFile(allCLeints);
    }


    static clsBankClient NewCleint()
    {
        vector<clsBankClient> allCLeints = _LoadClientsDataFromFile();
        clsBankClient CLeint =  clsBankClient::Find("A101");
            CLeint._AccountNumber = clsInputValidate::readStirng("Enter Account Number ");
            up(CLeint);
        allCLeints.push_back(CLeint);
        _SaveCleintsDataToFile(allCLeints);
        return CLeint;
    }
    
    static vector<clsBankClient> CleintsList()
    {
        vector<clsBankClient> allCLeints = _LoadClientsDataFromFile();
        return allCLeints;
    }

};


