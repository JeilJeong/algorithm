#include "../includes/high_credit_account.h"

/*
	HighCreditAccount Class Definition Area
*/
HighCreditAccount::HighCreditAccount(const int addr, const char *name, const double balance, const double int_ratio, const char grade)
	: NormalAccount(addr, name, balance, int_ratio), grade(grade) {}
HighCreditAccount::HighCreditAccount(const HighCreditAccount &rhs) : NormalAccount(rhs), grade(rhs.grade) {}
HighCreditAccount::~HighCreditAccount() {}

bool		HighCreditAccount::add_balance(const double balance)
{
	double	plus_ratio = 0;
	bool	succeed = false;

	succeed = NormalAccount::add_balance(balance);

	if (balance > 0)
	{
		switch(this->grade)
		{
			case 'A':
				plus_ratio = 7.0;
				break;
			case 'B':
				plus_ratio = 4.0;
				break;
			case 'C':
				plus_ratio = 2.0;
				break;
			default:
				break;
		}
		succeed = Account::add_balance(balance * (plus_ratio / 100.0));
	}
	return (succeed);
}
void		HighCreditAccount::show_info() const
{
	NormalAccount::show_info();
	cout << "grade : " << this->grade << endl;
}