#include "../includes/bank_account_managing.h"
#include <iostream>

using namespace	std;

int		main(void)
{
	int		select;
	AccountHandler handler;
	while (1)
	{
		AccountHandler::show_menu();
		cout << "Type Number : ";
		cin >> select;
		
		switch(select)
		{
			case MAKE :
				handler.create_account();
				break;
			case DEPOSIT :
				handler.deposit();
				break;
			case WITHDRAW :
				handler.withdrawal();
				break;
			case PRINT :
				handler.all_print();
				break;
			case EXIT :
				handler.prog_exit();
				return (0);
			default :
				cout << select << ": wrong number" << endl;
				break;
		}
	}
	return (0);
}