#include <bits/stdc++.h>
#include <fstream>

using namespace std;

class shoping
{
    int product_code;
    float price;
    float dis;
    string Name;
    string product_name;

    void menu();
    void administrator();
    void add();
    void buyer();
    void edit();
    void list();
    void reciept();
    void
}

void
shopping ::menu()
{
m:
    int choice;
    string email;
    string password;
    cout << "\t\t\t\t\t____________________________________________________\n";
    cout << "\t\t\t\t\t                                                    \n";
    cout << "\t\t\t\t\t          SuperMarket Main Menu                     \n";
    cout << "\t\t\t\t\t                                                    \n";
    cout << "\t\t\t\t\t____________________________________________________\n";
    cout << "\t\t\t\t\t                                                    \n";
    cout << "\t\t\t\t\t    1.)  Administrator     |\n";
    cout << "\t\t\t\t\t                           |\n";
    cout << "\t\t\t\t\t    2.)  Buyer             |\n";
    cout << "\t\t\t\t\t                           |\n";
    cout << "\t\t\t\t\t    3.)  Exit              |\n";
    cout << "\t\t\t\t\t                           |\n";
    cout << "\n\t\t\t Please Select";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t Please login \n";
        cout << "\t\t\t Enter Email     \n";
        cin >> email;
        cout << "\t\t\t Password         \n";
        cin >> password;
        validate_id_password();
        break;

    case 2:
        buyer();
        break;

    case 3:
        exit(0);
        break;

    default:
        cout << "Please select from given options";
    }
    goto m:
}

void shopping::administrator()
{
m:
    cout << "\n\n\n\t\t____________________________________________________|";
    cout << "\n\t\t\t\t                                                    |";
    cout << "\n\t\t\t\t          Administrator Menu                        |";
    cout << "\n\t\t\t\t                                                    |";
    cout << "\n\t\t\t\t____________________________________________________|";
    cout << "\n\t\t\t\t                                                    |";
    cout << "\n\t\t\t\t|______1.) Add the product_______|";
    cout << "\n\t\t\t\t                                 |";
    cout << "\n\t\t\t\t|______2.) Modify the product_____|";
    cout << "\n\t\t\t\t                           |";
    cout << "\n\t\t\t\t|______3.) Delete the product_____|";
    cout << "\n\t\t\t\t|                          |";
    cout << "\n\t\t\t\t|______4.) Back to main menu______|";
    cout << "\n\n\t  Please enter your choice of product_____|";
    int choice = 0;
    cin >> choice;
    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        remove();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "Invalid choice";
    }
    goto m:
}

void shopping::buyer()
{
m:
    cout << "\n\n\n\t\t___________________________________________________|";
    cout << "\n\t\t\t\t                                                   |";
    cout << "\n\t\t\t\t                     Buyer  MEnu                   |";
    cout << "\n\t\t\t\t                                                   |";
    cout << "\n\t\t\t\t___________________________________________________|";
    cout << "\n\t\t\t\t                                                   |";
    cout << "\n\t\t\t\t|______1.) Buy Product_______  |";
    cout << "\n\t\t\t\t                               |";
    cout << "\n\t\t\t\t|______2.) Go Back ____________|";
    cout << "\n\t\t\t\t                           |";
    cout << "\n\n\t  Please enter your choice of product_____|";
    int choice = 0;
    cin >> choice;
    switch (choice)
    {
    case 1:
        reciept();
        break;
    case 2:
        menu();
        break;

    default:
        cout << "Invalid choice";
    }
    goto m:
}

void shopping::add()
{
m:
    fstream data;
    int c;
    int tokens();
    float p;
    float d;
    string n;
    cout << "\n\n\t\t\t Add new product";
    cout << "\n\n\t Product code of product";
    cin >> product_code;
    cout << "\n\n\t Price of the Product";
    cin >> price;

    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << product_code << " " << product_name << " " << price << ;
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == product_code)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }
    if (token == 1)
    {
        goto m:
    }
    else
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << product_code << " " << product_name << " " << price << ;
        data.close();
    }
    cout << "RECORD INSERTED"
         << "\n";
}

void shopping::edit()
{
    fstream data1, data2;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    cout << "\n\t\t\t  Modify the record";
    cout << "\n\n\n\t Product code ";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n File does not exist.\n";
    }
    else
    {
        data1.open("database.txt", ios::app | ios::out);
        data >> product_code >> pname >> price >> dis;
        while (!data1.eof())
        {
            if (pkey == product_code)
            {
                cout << "\n\t\t Product new code :";
                cin >> c;
            }
        }
    }
}