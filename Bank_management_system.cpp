// To do : To connect with database

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class customer
{
    char name[30], fname[30], address[50], pin[4], phone[10], account_number[16];
    string dob, actual_pin = "3314";
    int deposit_amount, withdraw_amount, balance = 0;

public:
    int customerNo = 0;
    void detail();
    void show_detail();
    void new_account();
    void deposit_money();
    void withdraw_money();
    void storeData(); // to storeData the data in database
    // void getData(); // to fetch data from database
    // void change_pin();
    // Format to storeData data on database is : Account number, Name, Address, Father name, Phone number, DOB, Pin number
};

void customer ::detail()
{
    cout << "Enter name : ";
    gets(name);
    cout << "Enter your address : ";
    gets(address);
    cout << "Enter your father's name : ";
    gets(fname);
    cout << "Enter your phone number : ";
    cin >> phone;
    cout << "Enter date of birth : ";
    cin >> dob;
    cout << "Enter account number : ";
    cin >> account_number;
    cout << "Enter your 4 digit pin : ";
    cin >> pin;
};

void customer ::show_detail()
{
    cout << "Account number : " << account_number << endl;
    cout << "Name : " << name << endl;
    cout << "Address : " << address << endl;
    cout << "Father name : " << fname << endl;
    cout << "Phone number : " << phone << endl;
    cout << "DOB : " << dob << endl;
    cout << "Total balance : Rs. " << balance << endl;
}

void customer ::new_account()
{
    detail();
    cout << "Deposit amount : ";
    cin >> deposit_amount;
    balance += deposit_amount;
    cout << "Rs. " << deposit_amount << " is successfully deposited." << endl
         << "Total balance : Rs. " << balance << endl;
    customerNo++;
}

void customer ::deposit_money()
{
    cout << "Account number : ";
    cin >> account_number;
    cout << "Deposit amount : ";
    cin >> deposit_amount;
    balance += deposit_amount;
    cout << "Rs. " << deposit_amount << " is successfully deposited." << endl
         << "Total balance : Rs. " << balance << endl;
}

void customer ::withdraw_money()
{
    cout << "Account number : ";
    cin >> account_number;
    cout << "Withdraw amount : ";
    cin >> withdraw_amount;
    if (withdraw_amount > balance)
    {
        cout << "You don't have enough money in your bank account." << endl;
    }
    else
    {
        cout << "Enter your 4-digit PIN : ";
        cin >> pin;
        if (pin == actual_pin)
        {
            balance -= withdraw_amount;
            cout << "Successfully withdrawn Rs. " << withdraw_amount << endl
                 << "Remaining balance = Rs. " << balance << endl;
        }
        else
        {
            cout << "Wrong PIN" << endl;
        }
    }
}

void customer ::storeData()
{
    ofstream out;
    out.open("bank.txt");
    out << account_number << "\n"
        << name << "\n"
        << pin << "\n"
        << balance << "\n"
        << fname << "\n"
        << address << "\n"
        << dob << "\n"
        << phone;
    out.close();
    /*
     ---------- Way of storing the data --------------
        Account number
        Name
        Pin
        Balance
        Father name
        Address
        DOB
        Phone number
    */
}

int main()
{
    system("cls");
    customer c[100];
    int choice;

    system("Color 2");
    while (1)
    {
        cout << "1. Open a new account" << endl
             << "2. Deposit money" << endl
             << "3. Withdraw money" << endl
             << "4. Show your information" << endl
             << endl
             << "Enter your choice : ";
        cin >> choice;
        getchar();
        switch (choice)
        {
        case 1:
            c[c->customerNo].new_account();
            c->storeData();
            // getchar();
            break;
        case 2:
            c[c->customerNo].deposit_money();
            break;
        case 3:
            c[c->customerNo].withdraw_money();
            break;
        case 4:
            // c->getData();
            c[c->customerNo].show_detail();
            break;

        default:
            cout << "Invalid input" << endl;
            break;
        }
        cout << endl
             << endl
             << "Press enter to continue...";
        getchar();
        getchar();
        system("cls");
    }
    return 0;
}
