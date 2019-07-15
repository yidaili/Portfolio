#ifndef _ACCOUNTEXCEPTION_H
#define _ACCOUNTEXCEPTION_H

#include "BankingSysCommon.h"

class AccountException
{
public:
	virtual void ShowExceptionReason() = 0;
};

//입금예외 class
class DepositException :public AccountException
{
private:
	int depositMoney;
public:
	DepositException(int money);	//생성자
	void ShowExceptionReason();		//예외 메시지 출력
};

//0보다 작은 출금예외 class
class MinusWithdrawException :public AccountException
{
private:
	int balance;
public:
	MinusWithdrawException(int money);	//생성자
	void ShowExceptionReason();		//예외 메시지 출력
};

//잔액보다 작은 출금예외 class
class balanceWithdrawException :public AccountException
{
private:
	int balance;
public:
	balanceWithdrawException(int money);	//생성자
	void ShowExceptionReason();		//예외 메시지 출력
};

//계좌 저장공간 예외 class
class accNumException :public AccountException
{
public:
	accNumException();	//생성자
	void ShowExceptionReason();		//예외 메시지 출력
};
#endif // !_ACCOUNTEXCEPTION_H
