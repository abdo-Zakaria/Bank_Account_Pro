#include <iostream>

 #include"clsLogInScreen.h"
using namespace std;




int main()
{
    while (true)
    {
    clsLogInScreen::logInScreen();
    }
    // cout << TextEncriptionMethod1("mkmk3")<<endl;
    // cout << TextEncriptionMethod1("dimno4")<<endl;
    // cout << TextEncriptionMethod1("3rq32r")<<endl;
    // cout << TextEncriptionMethod1("lolo2")<<endl;
    // cout << TextEncriptionMethod1("yoyo5")<<endl;
    // cout << TextEncriptionMethod1("r4r4")<<endl;
    // cout << TextEncriptionMethod1("e3ee3")<<endl;
    // cout << TextEncriptionMethod1("pop")<<endl;
    //clsTransferLog a("10","10","10",10,10,01);
        

    return 0;
}






// void CleintsOfList()
// {
//     vector<clsBankClient> allClients  =  clsBankClient::CleintsList();
//     cout << "\nClient List : ";
//         cout <<setw(18)<< "\n___________________\n";
//         cout << "FirstName   | " <<setw(6) ;
//         cout << "LastName    | " <<setw(22) ;
//         cout << "Full Name   | " <<setw(9);
//         cout << "Email       | " <<setw(10) ;
//         cout << "Phone       | " <<setw(10) ;
//         cout << "Acc. Number | " <<setw(7) ;
//         cout << "Password    | " <<setw(7) ;
//         cout << "Balance      \n";
//         cout <<endl;
//         for (int i = 0; i < allClients.size() ; i++)
//         {
//         cout << allClients[i]._FirstName       <<setw(5) <<"|";//setw(8) ;
//         cout << allClients[i]._LastName        <<setw(3)<<"|" ;//setw(6) ;
//         cout << allClients[i].FullName()       <<setw(2) <<"|";//setw(14);
//         cout << allClients[i]._Email           <<setw(4)<<"|" ;//setw(7) ;
//         cout << allClients[i]._Phone           <<setw(6)<<"|" ;//setw(7) ;
//         cout << allClients[i].AccountNumber()  <<setw(10) <<"|";//setw(4) ;
//         cout << allClients[i]._PinCode         <<setw(10) <<"|";//setw(5) ;
//         cout << allClients[i]._AccountBalance  <<setw(7);//setw(5) ;
//         cout <<endl;
//         }
// }


// CleintsOfList();

// DeleteCleint();
// clsBankClient::UpdateClient("A101");
// cout << "========================================================================================== \n";
// clsBankClient ali = clsBankClient::Find("A101");
// ali.Print();
// AddNewClient();

