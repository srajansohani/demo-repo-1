#include <bits/stdc++.h>
#include <fstream>

using namespace std;

class shopping
{
public:
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
    void rem();
    void validate_id_password();
};

void shopping ::menu()
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
        cout << "\t\t\t Enter Email  \n";
        cin >> email;
        cout << "\t\t\t Password     \n";
        cin >> password;
        if (email == "srajan" && password == "srajan")
        {
            administrator();
        }
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
    goto m;
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
    cout << "\n\t\t\t\t|______1.) Add the product________|";
    cout << "\n\t\t\t\t|                                 |";
    cout << "\n\t\t\t\t|______2.) Modify the product_____|";
    cout << "\n\t\t\t\t|                                 |";
    cout << "\n\t\t\t\t|______3.) Delete the product_____|";
    cout << "\n\t\t\t\t|                                 |";
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
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "Invalid choice";
    }
    goto m;
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
    goto m;
}

void shopping::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    cout << "\n\n\t\t\t Add new product";
    cout << "\n\n\t Product code of product";
    cin >> product_code;
    cout << "\n\n\t Product Name of product";
    cin >> product_name;
    cout << "\n\n\t Price of the Product";
    cin >> price;
    cout << "\n\n\t Discount on product";
    cin >> dis;

    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << product_code << " " << product_name << " " << price;
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

        if (token == 1)
        {
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << product_code << " " << product_name << " " << price;
            data.close();
        }
    }
    cout << "\t\tRECORD INSERTED"
         << "\n";
}

void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
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
        data >> product_code >> product_name >> price >> dis;
        while (!data1.eof())
        {
            if (pkey == product_code)
            {
                cout << "\n\t\t Product new code :";
                cin >> c;
                cout << "\n\t\t Name of the Product :";
                cin >> n;
                cout << "\n\t\t Price :";
                cin >> p;
                cout << "\n\t\t Discount :";
                cin >> d;
                data1 << " " << c << " " << n << " " << d << "\n";
            }
            else
            {
                data1 << " " << product_code << " " << price << " " << dis;
            }
            data >> product_code >> product_name >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("dtabase1.txt", "databse.txt");
        if (token == 0)
        {
            "Record Not Found";
        }
    }
}

void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t   Delete Product";
    cout << "\n\n\t   Product Code";
    cin >> pkey;
    data.open("databse.txt", ios::in);
    if (!data)
    {
        cout << "File doesn't exist";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> product_code >> product_name >> price >> dis;
        while (!data.eof())
        {
            if (product_code == pkey)
            {
                cout << "\n\n\t Product deleted Succesfully";
                token++;
            }
            else
            {
                data1 << " " << product_code << " " << product_name << " " << price << " " << dis << "\n";
            }
            data >> product_code >> product_name >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\n\n Record not found";
        }
    }
}

void shopping ::list()
{
    fstream data;
    data.open("dabase.txt", ios::in);
    cout << "\n\n_____________________________________\n";
    cout << "ProN\t\tName\t\tPrice\n";
    cout << "\n\n|n_____________________________________\n";
    data >> product_code >> product_name >> price >> dis;
    while (data.eof())
    {
        cout << product_code << "\t\t" << product_name << "\t" << price << "\n";
        data >> product_code >> product_name >> price >> dis;
    }
    data.close();
}

void shopping ::reciept()
{
    fstream data;

    int arrC[100];
    int arrQ[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;
    cout << "\n\n\t\t\t  RECIEPT";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n Empty database";
    }
    else
    {
        data.close();
        list();
        cout << "\n______________________________\n\n";
        cout << "\n                                \n";
        cout << "       Please Place The Order      \n";
        cout << "|                                   | ";
        cout << "\n___________________________________\n";
        do
        {
        m:
            cout << "\n\n Enter the Proudct code:";
            cin >> arrC[c];
            cout << "\n\n Enter the product quantity";
            cin >> arrQ[c];
            for (int i = 0; i < c; i++)
            {
                if (arrC[i] == arrC[c])
                {
                    cout << "\n\n Duplicate product code. Please try again." << endl;
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another product ? if yes y else no n";
            cin >> choice;
        } while (choice = 'y');

        cout << "\n\n\t\t\t_______________RECIEPT_____________\n";
        cout << "\nProduct No\t Product Name\t Product Quantity\tprice\tAmount\tAmount with discount\n";
        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> product_code >> product_name >> price >> dis;
            while (!data.eof())
            {
                if (product_code == arrC[i])
                {
                    amount = price * arrQ[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n"
                         << product_code << "\t\t" << product_name << "\t\t" << arrQ[i] << "\t\t" << price << "\t" << amount << "\t\t" << dis;
                }
                data >> product_code >> product_name >> price >> dis;
            }
        }
        data.close();
    }
    cout << "\n\n______________________________________";
    cout << "\n Total Amount : " << total;
}

int main()
{
    shopping s;
    s.menu();
}