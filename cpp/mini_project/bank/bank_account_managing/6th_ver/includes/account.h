#ifndef ACCOUNT
# define ACCOUNT

# include "banking_common_data.h"

class Account {
public:
	Account();
	Account(const int addr, const char *name, const double balance);
	Account(const Account &rhs);
	virtual ~Account();

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

#endif