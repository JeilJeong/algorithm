#include "../includes/account.h"

/*
	Account Class Definition Area
	= Base class of NormalAccount & HighCreditAccount
*/
// Constructor
Account::Account()
{
	this->addr = 0;
	this->balance = 0;
	this->name = NULL;
}

Account::Account(const int addr, const char *name, double const balance) : addr(addr), balance(balance)
{
	int	len = strlen(name) + 1;
	this->name = new char[len];
	strcpy(this->name, name);
}

Account::Account(const Account &rhs) : addr(rhs.addr), balance(rhs.balance)
{
	cout << "Copy Constructor" << endl;
	this->name = new char[strlen(rhs.name) + 1];
	strcpy(this->name, rhs.name);
}

// Account Destructor
Account::~Account()
{
	delete[] name;
}

// Overloaded Operator
Account &Account::operator=(const Account &rhs)
{
	cout << "Copy Assignment Operator" << endl;
	if (this != &rhs)
	{
		delete[] this->name;
		this->addr = rhs.addr;
		this->balance = rhs.balance;
		this->name = new char[strlen(rhs.name) + 1];
		strcpy(this->name, rhs.name);
	}
	return (*this);
}

// Member Method
bool		Account::add_balance(const double balance)
{
	this->balance += balance;
	return (true);
}

int			Account::get_address() const { return (this->addr); }
const char	*Account::get_name() const { return (this->name); }
int			Account::get_balance() const { return (this->balance); }
void		Account::show_info() const
{
	cout << "Account : " << this->addr << endl;
	cout << "Name : " << this->name << endl;
	cout << "Balance : " << this->balance << endl;
}