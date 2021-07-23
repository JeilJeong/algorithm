#include "../includes/bank_account_managing.h"
#include <iostream>
#include <cstring>

using namespace	std;

// Account Constructor
Account::Account()
{
	this->addr = 0;
	this->balance = 0;
	this->name = NULL;
}

Account::Account(int addr, const char *name, double balance) : addr(addr), balance(balance)
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

Account::Account(Account &&rhs) : addr(rhs.addr), balance(rhs.balance)
{
	cout << "Move Constructor" << endl;
	this->name = rhs.name;
	rhs.name = NULL;
}

// Account Destructor
Account::~Account()
{
	delete[] name;
}

AccountHandler::AccountHandler() : current_count(0) {};

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

Account &Account::operator=(Account &&rhs)
{
	cout << "Move Assignment Operator" << endl;
	this->addr = rhs.addr;
	this->balance = rhs.balance;
	this->name = rhs.name;
	rhs.name = NULL;
	return (*this);
}

// Member Method
bool	Account::add_balance(const double balance)
{
	this->balance += balance;
	return (true);
}

int	Account::get_address() const { return (this->addr); }
const char	*Account::get_name() const { return (this->name); }
int	Account::get_balance() const { return (this->balance); }
void	Account::show_info() const
{
	cout << "Account : " << this->addr << endl;
	cout << "Name : " << this->name << endl;
	cout << "balance : " << this->balance << endl;
}

// AccountHandler Method
Account	*AccountHandler::create_account(void)
{
	int		addr;
	char	name[NAME_LENGHT];
	double	balance;

	cout << endl;
	// adding "this->" expression to AccountHandler member
	if (this->current_count >= ACCOUNT_NUMBER)
	{
		cout << "	[ERROR] No more make account" << endl;
		return (NULL);
	}
	cout << "	Account Id : ";
	cin >> addr;
	cout << "	Name : ";
	cin >> name;
	cout << "	Deposit money : ";
	cin >> balance;

	Account	*pReturn = new Account(addr, name, balance);
	// adding "this->" expression to AccountHandler member
	this->pAccount[this->current_count++] = pReturn;
	cout << "	[" << pReturn->get_address() << "]" << ": complete to register account" << endl;
	return (pReturn);
}

void	AccountHandler::deposit(void)
{
	int		addr;
	int		balance;
	int		i = -1;

	cout << endl;
	cout << "	Type id : ";
	cin >> addr;
	// adding "this->" expression to AccountHandler member
	while (++i < this->current_count)
	{
		if (this->pAccount[i]->get_address() == addr)
			break;
	}
	// adding "this->" expression to AccountHandler member
	if (i == this->current_count)
	{
		cout << "	[ERROR] " << addr << " does not exist" << endl;
		return ;
	}
	cout << "	Type money : ";
	cin >> balance;
	if (this->pAccount[i]->add_balance(balance))
	// adding "this->" expression to AccountHandler member
		cout << "	[REMAIN] " << this->pAccount[i]->get_balance() << endl;
}

void	AccountHandler::withdrawal(void)
{
	int		addr;
	int		money;
	int		i = -1;
	
	cout << endl;
	cout << "	Type id : ";
	cin >> addr;
	// adding "this->" expression to AccountHandler member
	while (++i < this->current_count)
	{
		// adding "this->" expression to AccountHandler member
		if (this->pAccount[i]->get_address() == addr)
			break;
	}
	// adding "this->" expression to AccountHandler member
	if (i == this->current_count)
	{
		cout << "	[ERROR] " << addr << " does not exist" << endl;
		return ;
	}
	// adding "this->" expression to AccountHandler member
	cout << "	[REMAIN] " << this->pAccount[i]->get_balance() << endl;
	cout << "	Type money : ";
	cin >> money;
	// adding "this->" expression to AccountHandler member
	if (money > this->pAccount[i]->get_balance())
	{
		cout << "	[ERROR] remain is not enough" << endl;
		return ;
	}
	// adding "this->" expression to AccountHandler member
	if (this->pAccount[i]->add_balance(-money))
		cout << "	[REMAIN] " << this->pAccount[i]->get_balance() << endl;
}

void	AccountHandler::all_print(void)
{
	int		i = -1;

	// adding "this->" expression to AccountHandler member
	while (++i < this->current_count)
	{
		cout << endl;
		cout << "	Id: " << this->pAccount[i]->get_address() << endl;
		cout << "	Name: " << this->pAccount[i]->get_name() << endl;
		cout << "	Remain: " << this->pAccount[i]->get_balance() << endl;
	}
}

void	AccountHandler::show_menu(void)
{
	cout << endl;
	cout << "---- [Main Menu] ----" << endl;
	cout << "[1] Create Account" << endl;
	cout << "[2] Deposit" << endl;
	cout << "[3] Withdraw" << endl;
	cout << "[4] Print" << endl;
	cout << "[5] Exit" << endl;
}

// for preventing memory leak
void	AccountHandler::prog_exit(void)
{
	int		i = -1;
	// adding "this->" expression to AccountHandler member
	while (++i < this->current_count)
		delete this->pAccount[i];
}
