#include "../includes/bank_account_managing.h"
#include <iostream>
#include <cstring>

using namespace	std;

Account *pAccount[ACCOUNT_NUMBER];
int		current_count = 0;

void	show_menu(void)
{
	cout << endl;
	cout << "---- [Main Menu] ----" << endl;
	cout << "[1] Create Account" << endl;
	cout << "[2] Deposit" << endl;
	cout << "[3] Withdraw" << endl;
	cout << "[4] Print" << endl;
	cout << "[5] Exit" << endl;
}

// Constructor
Account::Account()
{
	this->addr = 0;
	this->balance = 0;
	this->name = NULL;
}

Account::Account(int addr, char *name, double balance) : addr(addr), balance(balance)
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

// Destructor
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

// Global Method
Account	*create_account(void)
{
	int		addr;
	char	name[NAME_LENGHT];
	double	balance;

	cout << endl;
	if (current_count >= ACCOUNT_NUMBER)
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
	pAccount[current_count] = pReturn;
	current_count++;
	cout << "	[" << addr  << "]" << ": complete to register account" << endl;
	return (pReturn);
}

void	deposit(void)
{
	int		addr;
	int		balance;
	int		i = -1;

	cout << endl;
	cout << "	Type id : ";
	cin >> addr;
	while (++i < current_count)
	{
		if (pAccount[i]->get_address() == addr)
			break;
	}
	if (i == current_count)
	{
		cout << "	[ERROR] " << addr << " does not exist" << endl;
		return ;
	}
	cout << "	Type money : ";
	cin >> balance;
	if (pAccount[i]->add_balance(balance))
		cout << "	[REMAIN] " << pAccount[i]->get_balance() << endl;
}

void	withdrawal(void)
{
	int		addr;
	int		money;
	int		i = -1;
	
	cout << endl;
	cout << "	Type id : ";
	cin >> addr;
	while (++i < current_count)
	{
		if (pAccount[i]->get_address() == addr)
			break;
	}
	if (i == current_count)
	{
		cout << "	[ERROR] " << addr << " does not exist" << endl;
		return ;
	}
	cout << "	[REMAIN] " << pAccount[i]->get_balance() << endl;
	cout << "	Type money : ";
	cin >> money;
	if (money > pAccount[i]->get_balance())
	{
		cout << "	[ERROR] remain is not enough" << endl;
		return ;
	}
	if (pAccount[i]->add_balance(-money))
		cout << "	[REMAIN] " << pAccount[i]->get_balance() << endl;
}

void	all_print(void)
{
	int		i = -1;

	while (++i < current_count)
	{
		cout << endl;
		cout << "	Id: " << pAccount[i]->get_address() << endl;
		cout << "	Name: " << pAccount[i]->get_name() << endl;
		cout << "	Remain: " << pAccount[i]->get_balance() << endl;
	}
}

// for preventing memory leak
void	prog_exit(void)
{
	int		i = -1;
	while (++i < current_count)
		delete pAccount[i];
}