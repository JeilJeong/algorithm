#ifndef ACCOUNT_HANDLER_H
# define ACCOUNT_HANDLER_H

# include "banking_common_data.h"
# include "account.h"
# include "normal_account.h"
# include "high_credit_account.h"
# include "account_ptr_array.h"

class AccountHandler {
public:
	AccountHandler();
	static void	show_menu(void);
	Account	*create_account(void);
	void	deposit(void);
	void	withdrawal(void);
	void	all_print(void);
	void	prog_exit(void);

private:
	AccountPtrArray	arr;
	int				current_count;
};

#endif