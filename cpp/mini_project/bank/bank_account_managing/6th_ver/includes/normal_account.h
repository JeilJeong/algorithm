#ifndef NORMAL_ACCOUNT_H
# define NORMAL_ACCOUNT_H

# include "account.h"

class NormalAccount : public Account{
public:
	NormalAccount(const int addr, const char *name, const double balance, const double int_ratio);
	NormalAccount(const NormalAccount &rhs);
	~NormalAccount();

	bool	add_balance(const double balance);
	void	show_info() const;
private:
	double	int_ratio;
};

#endif