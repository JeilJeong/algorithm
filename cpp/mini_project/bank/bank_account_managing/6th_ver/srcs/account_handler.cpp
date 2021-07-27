#include "../includes/account_handler.h"

/*
	AccountHandler Class Definition Area
*/
// AccountHandler Constructor
AccountHandler::AccountHandler() : current_count(0) {};

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
