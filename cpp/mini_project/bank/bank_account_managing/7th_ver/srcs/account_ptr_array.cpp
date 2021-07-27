#include "../includes/account_ptr_array.h"

AccountPtrArray::AccountPtrArray(const AccountPtrArray &rhs) { (void)rhs; }
AccountPtrArray &AccountPtrArray::operator=(const AccountPtrArray &rhs)
{
	(void)rhs;
	return (*this);
}

AccountPtrArray::AccountPtrArray(int arrlen) : arrlen(arrlen) {	this->arr = new ACCOUNT_PTR[arrlen]; }
AccountPtrArray::~AccountPtrArray() { delete[] this->arr; }

ACCOUNT_PTR &AccountPtrArray::operator[] (int index) 
{
	if (index < 0 || index >= arrlen)
	{
		cout << "	[Error] index out of range" << endl;
		exit(1);
	}
	return (arr[index]);
}

ACCOUNT_PTR AccountPtrArray::operator[] (int index) const
{
	if (index < 0 || index >= arrlen)
	{
		cout << "	[Error] index out of range" << endl;
		exit(1);
	}
	return (arr[index]);
}

int		AccountPtrArray::length() const { return (this->arrlen); }
