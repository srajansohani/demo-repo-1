#include <bits/stdc++.h>
#include <fstream>

using namespace std;

class shopping
{
public:
    // All the attributes of a product are declared here.
    int product_code;
    float price;
    float discount;
    string product_name;
    // All the functaionalities are declared here whcih are defined outside using scope resolution
    void menu();
    void administrator();
    void add_product();
    void buyer();
    void modify_product();
    void list();
    void reciept();
    void delete_product();
    bool validate_id_password();
};

bool shopping ::validate_id_password() // It takes email id and password form user and validates it.
{
    string email;
    string password;
    cout << "\t\t\t Please login \n";
    cout << "\t\t\t Enter Email : ";
    cin >> email;
    cout << "\t\t\t Password : ";
    cin >> password;
    if (email == "srajansohani999@gmail.com" && password == "srajan")
    {
        return 1;
    }
    cout << "\n\t\t INVALID ID PASSWORD\n";
    return 0;
}
void shopping ::menu() // It opens the menu for user
{
m:
    int choice;
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
    cout << "\n\t\t\t Please Select : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        // If user is administartor he has to enter login id and password
        if (validate_id_password())
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
        cout << "Please select from given options"; // if the user does not select from given options
    }
    goto m;
}

void shopping::administrator() // opens the administrator menu and takes choice of administartor
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
    cout << "\n\n\t  Please enter your choice : ";
    int choice = 0;
    cin >> choice;
    // depending on choice from above different methods are called
    switch (choice)
    {
    case 1:
        add_product();
        break;
    case 2:
        modify_product();
        break;
    case 3:
        delete_product();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "Invalid choice";
    }
    goto m; // if invalid choice the we again want same function to repeated
}

void shopping::buyer() // opens buyer menu
{
m:
    cout << "\n\t\t\t\t___________________________________________________|";
    cout << "\n\t\t\t\t                                                   |";
    cout << "\n\t\t\t\t                     Buyer  MEnu                   |";
    cout << "\n\t\t\t\t                                                   |";
    cout << "\n\t\t\t\t___________________________________________________|";
    cout << "\n\t\t\t\t                                                   |";
    cout << "\n\t\t\t\t|______1.) Buy Product_________|";
    cout << "\n\t\t\t\t|                              |";
    cout << "\n\t\t\t\t|______2.) Go Back ____________|";
    cout << "\n\t\t\t\t                           ";
    cout << "\n\t\t  Please enter your choice : ";
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

void shopping::add_product()
{
m:
    fstream data; // data object for file handling
    // the below variables are decalred to contain the values aleready present in database.txt file
    // this is done to check that the product code entered by user is aleready present or not.
    int code_to_check;
    int token = 0; // token acts as a flag if the value is present or not.
    float price_to_check;
    float discount_to_check;
    string name_to_check;
    cout << "\n\n\t\t\t Add new product";
    cout << "\n\n\t Product code of product: ";
    cin >> product_code;
    cout << "\n\n\t Product Name of product: ";
    cin >> product_name;
    cout << "\n\n\t Price of the Product: ";
    cin >> price;
    cout << "\n\n\t Discount on product: ";
    cin >> discount;

    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << product_code << " " << product_name << " " << price << " " << discount << "\n";
        data.close();
    }
    else
    {
        data >> code_to_check >> name_to_check >> price_to_check >> discount_to_check;
        while (!data.eof())
        {
            if (code_to_check == product_code)
            {
                token++;
            }
            data >> code_to_check >> name_to_check >> price_to_check >> discount_to_check;
        }
        data.close();

        if (token == 1)
        {
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << product_code << " " << product_name << " " << price << " " << discount << "\n";
            data.close();
        }
    }
    cout << "\t\tRECORD INSERTED"
         << "\n";
}

void shopping::modify_product()
{
    fstream data, data1; // using 2 data objects
    // the reason is that the below code is copying all the data from database to database 1 except the product to modify
    int product_key; // product code of product which is to modify.
    int token = 0;
    // th new attributes for the product to modify
    int new_code;
    float new_price;
    float new_discount;
    string new_name;
    cout << "\n\t\t\t  Modify the record";
    cout << "\n\n\n\t Product code ";
    cin >> product_key;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n File does not exist.\n";
    }
    else
    {
        data1.open("database.txt", ios::app | ios::out);
        data >> product_code >> product_name >> price >> discount;
        while (!data1.eof())
        {
            if (product_key == product_code)
            {
                cout << "\n\t\t Product new code :";
                cin >> new_code;
                cout << "\n\t\t Name of the Product :";
                cin >> new_name;
                cout << "\n\t\t Price :";
                cin >> new_price;
                cout << "\n\t\t Discount :";
                cin >> new_discount;
                data1 << " " << new_code << " " << new_name << " " << new_price << " " << new_discount << "\n";
                cout << "\n\t\t RECORD EDITED\n";
                token++;
            }
            else
            {
                data1 << " " << product_code << " " << product_name << " " << price << " " << discount << "\n";
            }
            data >> product_code >> product_name >> price >> discount;
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

void shopping::delete_product()
{
    fstream data, data1; // same logic as modify
    int product_key;     // the product code of product to delete.
    int token = 0;
    cout << "\n\n\t   Delete Product";
    cout << "\n\n\t   Product Code";
    cin >> product_key;
    data.open("databse.txt", ios::in);
    if (!data)
    {
        cout << "File doesn't exist";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> product_code >> product_name >> price >> discount;
        while (!data.eof())
        {
            if (product_code == product_key)
            {
                cout << "\n\n\t Product deleted Succesfully";
                token++;
            }
            else
            {
                data1 << " " << product_code << " " << product_name << " " << price << " " << discount << "\n";
            }
            data >> product_code >> product_name >> price >> discount;
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

void shopping ::list() // It displays the lsit of availaible products
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\t\t PRODUCT LIST\n";
    cout << "\n\n_______________________________________________\n";
    cout << "Product code\t\tName\t\tPrice\n";
    cout << "\n\n________________________________________________ \n";
    data >> product_code >> product_name >> price >> discount;
    while (!data.eof())
    {
        cout << product_code << "\t\t" << product_name << "\t\t" << price << "\t\t" << discount << "\n";
        data >> product_code >> product_name >> price >> discount;
    }
    data.close();
}

void shopping ::reciept() // It displays the complete shopping menu where you have to enter product code and quantity to buy
{
    fstream data;

    int arrC[100];
    int arrQ[100];
    char choice;
    int current_index = 0;
    float amount = 0;
    float final_price = 0;
    float total = 0;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n Nothing in Store ";
    }
    else
    {
        data.close();
        list();
        cout << "\n_______________________________\n";
        cout << "\n                               \n";
        cout << "\n     Please Place The Order    \n";
        cout << "                                   ";
        cout << "\n_______________________________\n";
        do
        {
        m:

            cout << "\n\n Enter the Proudct code: ";
            cin >> arrC[current_index];
            cout << "\n\n Enter the product quantity: ";
            cin >> arrQ[current_index];
            for (int i = 0; i < current_index; i++)
            {
                if (arrC[i] == arrC[current_index])
                {
                    cout << "\n\n Duplicate product code. Please try again." << endl;
                    goto m;
                }
            }
            current_index++;
            cout << "\n\n Do you want to buy another product ? if yes y else no n : ";
            cin >> choice;
        } while (choice == 'y');

        cout << "\n\n\t\t\t_______________RECIEPT_____________\n";
        cout << "\nProduct No\t Product Name\t Product Quantity\tprice\tAmount\t discount\t Final price\n";
        for (int i = 0; i < current_index; i++)
        {
            data.open("database.txt", ios::in);
            data >> product_code >> product_name >> price >> discount;
            while (!data.eof())
            {
                if (product_code == arrC[i])
                {
                    amount = price * arrQ[i];
                    final_price = amount - (amount * discount / 100);
                    total = total + final_price;
                    cout << "\n"
                         << product_code << "\t\t " << product_name << "\t\t\t" << arrQ[i] << "\t\t" << price << "\t" << amount << "\t\t" << discount << "%\t\t" << final_price;
                }
                data >> product_code >> product_name >> price >> discount;
            }
            data.close();
        }
    }
    cout << "\n\n______________________________________";
    cout << "\n Total Amount : " << total;
}

int main()
{
    shopping s;
    s.menu();
}