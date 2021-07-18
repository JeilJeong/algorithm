#include "../includes/bank_account_managing.h"
#include <iostream>
#include <cstring>

using namespace	std;

int			current_count = 0;
t_account	accounts[ACCOUNT_NUMBER];

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

void	create_account(void)
{
	int		id;
	char	name[NAME_LENGHT];
	double	money;

	cout << endl;
	if (current_count >= ACCOUNT_NUMBER)
	{
		cout << "	[ERROR] No more make account" << endl;
		return ;
	}
	cout << "	Account Id : ";
	cin >> id;
	cout << "	Name : ";
	cin >> name;
	cout << "	Deposit money : ";
	cin >> money;

	accounts[current_count].id = id;
	strcpy(accounts[current_count].name, name);
	accounts[current_count].money = money;

	current_count++;
	cout << "	[" << id  << "]" << ": complete to register account" << endl;
}

void	deposit(void)
{
	int		id;
	int		money;
	int		i = -1;

	cout << endl;
	cout << "	Type id : ";
	cin >> id;
	while (++i < current_count)
	{
		if (accounts[i].id == id)
			break;
	}
	if (i == current_count)
	{
		cout << "	[ERROR] " << id << " does not exist" << endl;
		return ;
	}
	cout << "	Type money : ";
	cin >> money;
	accounts[i].money += money;

	cout << "	[REMAIN] " << accounts[i].money << endl;
}

void	withdrawal(void)
{
	int		id;
	int		money;
	int		i = -1;
	
	cout << endl;
	cout << "	Type id : ";
	cin >> id;
	while (++i < current_count)
	{
		if (accounts[i].id == id)
			break;
	}
	if (i == current_count)
	{
		cout << "	[ERROR] " << id << " does not exist" << endl;
		return ;
	}
	cout << "	[REMAIN] " << accounts[i].money << endl;
	cout << "	Type money : ";
	cin >> money;
	if (money > accounts[i].money)
	{
		cout << "	[ERROR] remain is not enough" << endl;
		return ;
	}
	accounts[i].money -= money;

	cout << "	[REMAIN] " << accounts[i].money << endl;
}

void	all_print(void)
{
	int		i = -1;

	while (++i < current_count)
	{
		cout << endl;
		cout << "	Id: " << accounts[i].id << endl;
		cout << "	Name: " << accounts[i].name << endl;
		cout << "	Remain: " << accounts[i].money << endl;
	}
}