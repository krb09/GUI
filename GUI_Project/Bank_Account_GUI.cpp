#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS

#include "Bank_Account_GUI.h"
#include <string>
#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;

Bank_Account_GUI::Bank_Account_GUI()
{
	Total_Cash_Balance = getCashBalance();							//this is actually a unnecessary part.
}
double Bank_Account_GUI::get_Bank_Balance()
{
	return getCashBalance();
}
void Bank_Account_GUI::view_account_balance()
{
	cout << "The current account balance is:$" << getCashBalance() << endl;
}
void Bank_Account_GUI::deposit_money(double deposit)
{
	setCashBalance_new(getCashBalance() + deposit);
	Update_CashBalance_into_txt(CashBalance);
	cout << "After deposit, the current account balance is:$" << getCashBalance() << endl;
	update_transaction_on_account(1, deposit);

}
void Bank_Account_GUI::withdraw_money(double money)
{
	setCashBalance_new(getCashBalance() - money);
	Update_CashBalance_into_txt(CashBalance);
	cout << "After withdrawal, the current account balance is:$" << getCashBalance() << endl;
	update_transaction_on_account(0, money);

}

void Bank_Account_GUI::update_transaction_on_account(int choice, double money)
{
	ofstream write_trans;
	write_trans.open("Bank_Account_History_GUI.txt", ios::app);			//append and add at the end
	if (choice == 1)						//share was bought
	{
		write_trans << "Deposit" << "		" << money << "		" << get_Bank_Balance() << "		"  << endl;
		write_trans.close();
	}
	else
	{
		write_trans << "Withdraw" << "	" << money << "		" << get_Bank_Balance() << "		" << endl;
		write_trans.close();

	}
}
CString Bank_Account_GUI::print_out_history()
{
	ifstream read_bank;
	string item,final_string;
	CString str;
	read_bank.open("Bank_Account_History_GUI.txt");
	while (getline(read_bank, item))
	{
		//cout << item << endl;
		final_string = final_string + item;
	}
	str = final_string.c_str();
	return str;
	read_bank.close();
}

