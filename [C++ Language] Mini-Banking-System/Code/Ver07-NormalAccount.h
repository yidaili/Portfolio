#ifndef _NORMALACCOUNT_H_
#define _NORMALACCOUNT_H_

#include "Ver07-Account.h"

class NormalAccount :public Account
{
private:
	int accID;				//계좌번호
	int balance;			//잔액
	double interestRatio;	//이자
public:
	NormalAccount(const String name, int num, int initMoney);			 //생성자
	NormalAccount(const NormalAccount & copy);							 //default 복사 생성자
	void SetDepositbalance(int money, const char level);			//입금 후 잔액 set
	void SetWithdrawbalance(int money);			//출금 후 잔액 set
	int GetaccID(void) const;					//계좌번호 반환
	int Getbalance(void) const;					//잔액 반환
	virtual char Getlevel(void) const;			//신용등급 반환
	~NormalAccount(void);						//소멸자
};

#endif // !_NORMALACCOUNT_H_