#include "../includes/bank_account_managing.h"
#include <iostream>

using namespace	std;

int		main(void)
{
	int		select;
	while (1)
	{
		show_menu();
		cout << "Type Number : ";
		cin >> select;
		
		switch(select)
		{
			case MAKE :
				create_account();
				break;
			case DEPOSIT :
				deposit();
				break;
			case WITHDRAW :
				withdrawal();
				break;
			case PRINT :
				all_print();
				break;
			case EXIT :
				prog_exit();
				return (0);
			default :
				cout << select << ": wrong number" << endl;
				break;
		}
	}
	return (0);
}