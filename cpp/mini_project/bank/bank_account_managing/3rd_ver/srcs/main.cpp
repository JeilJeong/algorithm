#include "../includes/bank_account_managing.h"
#include <iostream>

using namespace	std;

	// 이 경우 reference로 사용될 수 있는 객체가 return 시 해제되기 때문에 수행할 수 없음
// Account	&ret_ref(void)
// {
// 	cout << "ret_ref" << endl;
// 	Account ret(2, NULL, 1000);
// 	return (ret);
// }

	// 이동 생성자와 이동 대입 연산자 테스트용
Account	ret_normal(void)
{
	cout << "ret_normal" << endl;
	char s[] = "noraml";
	Account ret(2, s, 1000);
	return (ret);
}

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
		// 생성, 대입 연산자 테스트용
	// Account *p = create_account();
	// Account p2(*p);
	// Account p3;
	// p3 = ret_normal();
	// Account p4 = ret_ref();
	return (0);
}