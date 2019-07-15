#include "BankingSysCommon.h"
#include "Ver07-NormalAccount.h"
#include "Ver07-AccountException.h"
#include "Ver07-cusNameString.h"

//NormalAccount class
NormalAccount::NormalAccount(const String name, int accNum, int initMoney)
	:Account(name), interestRatio(0.03)
{
	accID = 101 + accNum;
	balance = initMoney;
}



NormalAccount::NormalAccount(const NormalAccount & copy)
	:Account(copy.GetcusName()), accID(copy.accID), balance(copy.balance), interestRatio(copy.interestRatio)
{}

void NormalAccount::SetDepositbalance(int money, const char level)
{
	balance = balance + (int)(money + money * interestRatio);
}

void NormalAccount::SetWithdrawbalance(int money)
{
	balance -= money;
}

int NormalAccount::GetaccID(void) const
{
	return accID;
}

int NormalAccount::Getbalance(void) const
{
	return balance;
}

char NormalAccount::Getlevel(void) const
{
	return 'N';
}

NormalAccount::~NormalAccount(void)
{}