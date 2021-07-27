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
	Account(const int addr, const char *name, const double balance);
	Account(const Account &rhs);
// make Account (move constructor, copy & move operator) to comment.
	// Account(Account &&rhs);
	virtual ~Account();

	// Account &operator=(const Account &rhs);
	// Account &operator=(Account &&rhs);

	virtual bool	add_balance(const double balance);
	int				get_address() const;
	const char		*get_name() const;
	int				get_balance() const;
	virtual void	show_info() const;

private:
	int		addr;
	char	*name;
	double	balance;
};

class NormalAccount : public Account{
public:
	NormalAccount(const int addr, const char *name, const double balance, const double int_ratio);
	NormalAccount(const NormalAccount &rhs);
	NormalAccount(NormalAccount &&rhs);
	~NormalAccount();

// because of upcasting, operator does not be implemented
	// NormalAccount &operator=(const NormalAccount &rhs);
	// NormalAccount &operator=(NormalAccount &&rhs);

	bool	add_balance(const double balance);
	void	show_info() const;
private:
	double	int_ratio;
};

class HighCreditAccount : public NormalAccount{
public:
	HighCreditAccount(const int addr, const char *name, const double balance, const double int_ratio, const char grade);
	HighCreditAccount(const HighCreditAccount &rhs);
	HighCreditAccount(HighCreditAccount &&rhs);
	~HighCreditAccount();

// because of upcasting, operator does not be implemented 
	// HighCreditAccount &operator=(const HighCreditAccount &rhs);
	// HighCreditAccount &operator=(HighCreditAccount &&rhs);

	bool	add_balance(const double balance);
	void	show_info() const;
private:
	char	grade;
};

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
	Account	*pAccounts[ACCOUNT_NUMBER];
	int		current_count;
};

#endif