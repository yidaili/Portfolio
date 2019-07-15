#include "BankingSysCommon.h"
#include "Ver07-HighCreditAccount.h"

//HighCreditAccount class
HighCreditAccount::HighCreditAccount(const String name, int accNum, const char level, int initMoney)
	:Account(name), interestRatio(0.03)
{
	accID = 101 + accNum;
	creditLevel = level;
	balance = initMoney;
}

HighCreditAccount::HighCreditAccount(const HighCreditAccount & copy)
	:Account(copy.GetcusName()), accID(copy.accID), balance(copy.balance), interestRatio(copy.interestRatio)
{}

void HighCreditAccount::SetDepositbalance(int money, const char level)
{
	switch (level)
	{
	case 'A':
		balance = balance + money + (int)(money * interestRatio) + (int)(money * A * 0.01);
		break;
	case 'B':
		balance = balance + money + (int)(money * interestRatio) + (int)(money * B * 0.01);
		break;
	case 'C':
		balance = balance + money + (int)(money * interestRatio) + (int)(money * C * 0.01);
		break;
	}	
}

void HighCreditAccount::SetWithdrawbalance(int money)
{
	balance -= money;
}

int HighCreditAccount::GetaccID(void) const
{
	return accID;
}

int HighCreditAccount::Getbalance(void) const
{
	return balance;
}

char HighCreditAccount::Getlevel(void) const
{
	return creditLevel;
}

HighCreditAccount::~HighCreditAccount(void)
{}