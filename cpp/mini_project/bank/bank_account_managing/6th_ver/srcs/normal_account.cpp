#include "../includes/normal_account.h"

/*
	NormalAccount Class Definition Area
	= Parent class of HighCreditAccount
*/
NormalAccount::NormalAccount(const int addr, const char *name, const double balance, const double int_ratio)
	: Account(addr, name, balance), int_ratio(int_ratio) {}
NormalAccount::NormalAccount(const NormalAccount &rhs) : Account(rhs), int_ratio(rhs.int_ratio) {}
NormalAccount::~NormalAccount() {}

bool		NormalAccount::add_balance(const double balance)
{
	bool	succeed = false;
	succeed = Account::add_balance(balance);
	if (balance > 0)
		succeed = Account::add_balance(balance * (this->int_ratio / 100.0));
	return (succeed);
}

void		NormalAccount::show_info() const
{
	Account::show_info();
	cout << "Rate : " << this->int_ratio << endl;
}