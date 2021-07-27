#include "../includes/bank_account_managing.h"
#include <iostream>
#include <cstring>

using namespace	std;


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

// Account::Account(Account &&rhs) : addr(rhs.addr), balance(rhs.balance)
// {
// 	cout << "Move Constructor" << endl;
// 	this->name = rhs.name;
// 	rhs.name = NULL;
// }

// Account Destructor
Account::~Account()
{
	delete[] name;
}

AccountHandler::AccountHandler() : current_count(0) {};

// Overloaded Operator
// Account &Account::operator=(const Account &rhs)
// {
// 	cout << "Copy Assignment Operator" << endl;
// 	if (this != &rhs)
// 	{
// 		delete[] this->name;
// 		this->addr = rhs.addr;
// 		this->balance = rhs.balance;
// 		this->name = new char[strlen(rhs.name) + 1];
// 		strcpy(this->name, rhs.name);
// 	}
// 	return (*this);
// }

// Account &Account::operator=(Account &&rhs)
// {
// 	cout << "Move Assignment Operator" << endl;
// 	this->addr = rhs.addr;
// 	this->balance = rhs.balance;
// 	this->name = rhs.name;
// 	rhs.name = NULL;
// 	return (*this);
// }

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

/*
	NormalAccount Class Definition Area
	= Parent class of HighCreditAccount
*/
// can reuse Account Constructor.
NormalAccount::NormalAccount(const int addr, const char *name, const double balance, const double int_ratio)
	: Account(addr, name, balance), int_ratio(int_ratio) {}
// can reuse Account Copy Constructor.
NormalAccount::NormalAccount(const NormalAccount &rhs) : Account(rhs), int_ratio(rhs.int_ratio) {}
// NormalAccount::NormalAccount(NormalAccount &&rhs) : Account(rhs), int_ratio(rhs.int_ratio) {}
/*
	If the child class is inherited by the parent,
	and a virtual keyword is not declared to the parent's destructor when the destructor is called,
	the parent destructor is called instead of the child destructor.
*/
// 		In this case, it is not clear that the program function properly when a child destructor does not be implemented.
NormalAccount::~NormalAccount() {}

bool		NormalAccount::add_balance(const double balance)
{
	bool	succeed = false;
	// after calling existed function of Base Class
	succeed = Account::add_balance(balance);

	// processing added member variable of Derived Class
	if (balance > 0)
		succeed = Account::add_balance(balance * (this->int_ratio / 100.0));
	return (succeed);
}

void		NormalAccount::show_info() const
{
	// after calling existed function of Base Class
	Account::show_info();
	// processing added member variable of Derived Class
	cout << "Rate : " << this->int_ratio << endl;
}

/*
	HighCreditAccount Class Definition Area
*/
HighCreditAccount::HighCreditAccount(const int addr, const char *name, const double balance, const double int_ratio, const char grade)
	: NormalAccount(addr, name, balance, int_ratio), grade(grade) {}
HighCreditAccount::HighCreditAccount(const HighCreditAccount &rhs) : NormalAccount(rhs), grade(rhs.grade) {}
// HighCreditAccount::HighCreditAccount(HighCreditAccount &&rhs) : NormalAccount(rhs), grade(grade) {}
/*
	If the child class is inherited by the parent,
	and a virtual keyword is not declared to the parent's destructor when the destructor is called,
	the parent destructor is called instead of the child destructor.
*/
// 		In this case, it is not clear that the program function properly when a child destructor does not be implemented.
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


/*
	AccountHandler Class Definition Area
*/
// AccountHandler Method
Account		*AccountHandler::create_account(void)
{
	Account	*pAccount;
	int		kind_of_account = 0;
	int		addr;
	char	name[NAME_LENGHT];
	double	balance;
	double	int_ratio;
	char	grade;

	cout << endl;
	cout << "	----Select Account----" << endl;
	cout << "	1. Normal 2. High Credit" << endl;
	cout << "	>> ";
	cin >> kind_of_account;

	if (this->current_count >= ACCOUNT_NUMBER)
	{
		cout << "	[ERROR] No more make account" << endl;
		return (NULL);
	}
	switch(kind_of_account)
	{
		case 1:
			cout << "	[Normal Account]" << endl;
			break;
		case 2:
			cout << "	[High Credit Account]" << endl;
			break;
		default:
			cout << "	please, select within 1 or 2" << endl;
			return (NULL);
	}

	cout << "	Account Id : ";
	cin >> addr;
	cout << "	Name : ";
	cin >> name;
	cout << "	Deposit money : ";
	cin >> balance;
	cout << "	Ratio : ";
	cin >> int_ratio;

	if (kind_of_account == 2)
	{
		cout << "	grade : ";
		cin >> grade;
	}
	
	switch(kind_of_account)
	{
		case 1:
			pAccount = new NormalAccount(addr, name, balance, int_ratio);
			break;
		case 2:
			pAccount = new HighCreditAccount(addr, name, balance, int_ratio, grade);
			break;
		default:
			break;
	}
	this->pAccounts[this->current_count++] = pAccount;
	cout << "	[" << pAccount->get_address() << "]" << ": complete to register account" << endl;
	return (pAccount);
}

void		AccountHandler::deposit(void)
{
	int		addr;
	int		balance;
	int		i = -1;

	cout << endl;
	cout << "	Type id : ";
	cin >> addr;
	while (++i < this->current_count)
	{
		if (this->pAccounts[i]->get_address() == addr)
			break;
	}
	if (i == this->current_count)
	{
		cout << "	[ERROR] " << addr << " does not exist" << endl;
		return ;
	}
	cout << "	Type money : ";
	cin >> balance;
	if (this->pAccounts[i]->add_balance(balance))
		cout << "	[REMAIN] " << this->pAccounts[i]->get_balance() << endl;
}

void		AccountHandler::withdrawal(void)
{
	int		addr;
	int		money;
	int		i = -1;
	
	cout << endl;
	cout << "	Type id : ";
	cin >> addr;
	while (++i < this->current_count)
	{
		if (this->pAccounts[i]->get_address() == addr)
			break;
	}
	if (i == this->current_count)
	{
		cout << "	[ERROR] " << addr << " does not exist" << endl;
		return ;
	}
	cout << "	[REMAIN] " << this->pAccounts[i]->get_balance() << endl;
	cout << "	Type money : ";
	cin >> money;
	if (money > this->pAccounts[i]->get_balance())
	{
		cout << "	[ERROR] remain is not enough" << endl;
		return ;
	}
	if (this->pAccounts[i]->add_balance(-money))
		cout << "	[REMAIN] " << this->pAccounts[i]->get_balance() << endl;
}

void		AccountHandler::all_print(void)
{
	int		i = -1;

	while (++i < this->current_count)
	{
		cout << endl;
		this->pAccounts[i]->show_info();
	}
}

void		AccountHandler::show_menu(void)
{
	cout << endl;
	cout << "---- [Main Menu] ----" << endl;
	cout << "[1] Create Account" << endl;
	cout << "[2] Deposit" << endl;
	cout << "[3] Withdraw" << endl;
	cout << "[4] Print" << endl;
	cout << "[5] Exit" << endl;
}

void		AccountHandler::prog_exit(void)
{
	int		i = -1;
	while (++i < this->current_count)
		delete this->pAccounts[i];
}
