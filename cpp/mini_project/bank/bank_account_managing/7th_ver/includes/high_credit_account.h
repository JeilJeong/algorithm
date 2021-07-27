#ifndef HIGH_CREDIT_ACCOUNT_H
# define HIGH_CREDIT_ACCOUNT_H

# include "normal_account.h"

class HighCreditAccount : public NormalAccount{
public:
	HighCreditAccount(const int addr, const char *name, const double balance, const double int_ratio, const char grade);
	HighCreditAccount(const HighCreditAccount &rhs);
	~HighCreditAccount();

	bool	add_balance(const double balance);
	void	show_info() const;
private:
	char	grade;
};

#endif