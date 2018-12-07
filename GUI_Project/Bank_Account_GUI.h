#pragma once
#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include "Account_GUI.h"
class Bank_Account_GUI : public Account_GUI
{
public:
	Bank_Account_GUI();
	double get_Bank_Balance();
	void view_account_balance();
	void deposit_money(double);
	void withdraw_money(double);
	void update_transaction_on_account(int, double);			//1-deposit,0-withdraw;double:money deposit or withdraw
	CString print_out_history();
private:
	double Total_Cash_Balance;
};

#endif 

