#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include "BankingSysCommon.h"
#include "Ver07-cusNameString.h"

class Account
{
private:
	String cusName;
public:
	Account(const String name);	//������
	virtual void SetDepositbalance(int money, const char level) = 0;	//�Ա� �� �ܾ� set
	virtual void SetWithdrawbalance(int money) = 0;	//��� �� �ܾ� set
	virtual int GetaccID(void) const = 0;			//���¹�ȣ ��ȯ
	virtual int Getbalance(void) const = 0;			//�ܾ� ��ȯ
	virtual char Getlevel(void) const = 0;			//�ſ��� ��ȯ
	String GetcusName(void) const;				//���̸� ��ȯ
	~Account(void);				//�Ҹ���
};

#endif // !_ACCOUNT_H_
