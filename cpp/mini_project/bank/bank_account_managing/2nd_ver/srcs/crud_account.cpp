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

Account::Account(int addr, char *name, double balance) : addr(addr), balance(balance)
{
	int	len = strlen(name) + 1;
	this->name = new char[len];
	strcpy(this->name, name);
}

Account::~Account()
{
	delete[] name;
}

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

void	prog_exit(void)
{
	int		i = -1;
	while (++i < current_count)
		delete pAccount[i];
}