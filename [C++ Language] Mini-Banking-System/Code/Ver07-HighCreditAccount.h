#ifndef _HIGHCREDITACCOUNT_H_
#define _HIGHCREDITACCOUNT_H_

#include "Ver07-Account.h"

class HighCreditAccount :public Account
{
private:
	int accID;					//계좌번호
	int balance;				//잔액
	char creditLevel;			//신용등급
	double interestRatio=0.03;	//이자
public:
	HighCreditAccount(const String name, int num, char level, int initMoney);		 //생성자
	HighCreditAccount(const HighCreditAccount & copy);					 //default 복사 생성자
	void SetDepositbalance(int money, const char level);			//입금 후 잔액 set
	void SetWithdrawbalance(int money);			//출금 후 잔액 set
	int GetaccID(void) const;					//계좌번호 반환
	int Getbalance(void) const;					//잔액 반환
	char Getlevel(void) const;					//신용등급 반환
	~HighCreditAccount(void);					//소멸자
};

#endif // !_NORMALACCOUNT_H_