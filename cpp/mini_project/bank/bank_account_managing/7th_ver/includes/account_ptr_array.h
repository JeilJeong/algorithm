#ifndef ACCOUNT_PTR_ARRAY_H
# define ACCOUNT_PTR_ARRAY_H

# include "account.h"

typedef Account *	ACCOUNT_PTR;

class AccountPtrArray {
public:

private:
	ACCOUNT_PTR	*arr;
	int			arrlen;
	// prevent accessing copy_constructor & copy_assignment_operator by using private keyword
	AccountPtrArray(const AccountPtrArray &rhs);
	AccountPtrArray &operator=(const AccountPtrArray &rhs);
public:
	AccountPtrArray(int arrlen = 100);
	~AccountPtrArray();
	// for editing
	ACCOUNT_PTR	&operator[](int index);
	// for making an inquiry
	ACCOUNT_PTR operator[](int index) const;
	int			length() const;
};

#endif