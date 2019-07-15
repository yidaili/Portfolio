#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include "BankingSysCommon.h"
#include "Ver07-cusNameString.h"

class Account
{
private:
	String cusName;
public:
	Account(const String name);	//생성자
	virtual void SetDepositbalance(int money, const char level) = 0;	//입금 후 잔액 set
	virtual void SetWithdrawbalance(int money) = 0;	//출금 후 잔액 set
	virtual int GetaccID(void) const = 0;			//계좌번호 반환
	virtual int Getbalance(void) const = 0;			//잔액 반환
	virtual char Getlevel(void) const = 0;			//신용등급 반환
	String GetcusName(void) const;				//고객이름 반환
	~Account(void);				//소멸자
};

#endif // !_ACCOUNT_H_
