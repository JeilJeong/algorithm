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

class Account {
public:
	Account();
	// adding const keyword
	Account(int addr, const char *name, double balance);
	Account(const Account &rhs);
	Account(Account &&rhs);
	~Account();

	Account &operator=(const Account &rhs);
	Account &operator=(Account &&rhs);

	bool	add_balance(const double balance);
	int	get_address() const;
	const char	*get_name() const;
	int		get_balance() const;
	void	show_info() const;

private:
	int		addr;
	char	*name;
	double	balance;
};

void	show_menu(void);
Account	*create_account(void);
void	deposit(void);
void	withdrawal(void);
void	all_print(void);
void	prog_exit(void);

#endif