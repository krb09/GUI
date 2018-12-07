#pragma once
#pragma once
#include "stdafx.h"
#ifndef ACCOUNT_GUI_H
#define ACCOUNT_GUI_H
class Account_GUI {
public:
	Account_GUI();
	void setCashBalance_from_txt();
	void setCashBalance_new(double);
	double getCashBalance();
	void Update_CashBalance_into_txt(double);
protected:
	double CashBalance;
};
#endif 
