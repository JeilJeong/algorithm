#ifndef BANK_ACCOUNT_MANAGING_H
# define BANK_ACCOUNT_MANAGING_H

# define NAME_LENGHT	20
# define ACCOUNT_NUMBER	10

typedef struct	s_account {
	int			id;
	char		name[NAME_LENGHT];
	double		money;
}				t_account;

enum	{MAKE=1, DEPOSIT, WITHDRAW, PRINT, EXIT};

void	show_menu(void);
void	create_account(void);
void	deposit(void);
void	withdrawal(void);
void	all_print(void);

#endif