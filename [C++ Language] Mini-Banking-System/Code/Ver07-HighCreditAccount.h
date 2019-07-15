#ifndef _HIGHCREDITACCOUNT_H_
#define _HIGHCREDITACCOUNT_H_

#include "Ver07-Account.h"

class HighCreditAccount :public Account
{
private:
	int accID;					//���¹�ȣ
	int balance;				//�ܾ�
	char creditLevel;			//�ſ���
	double interestRatio=0.03;	//����
public:
	HighCreditAccount(const String name, int num, char level, int initMoney);		 //������
	HighCreditAccount(const HighCreditAccount & copy);					 //default ���� ������
	void SetDepositbalance(int money, const char level);			//�Ա� �� �ܾ� set
	void SetWithdrawbalance(int money);			//��� �� �ܾ� set
	int GetaccID(void) const;					//���¹�ȣ ��ȯ
	int Getbalance(void) const;					//�ܾ� ��ȯ
	char Getlevel(void) const;					//�ſ��� ��ȯ
	~HighCreditAccount(void);					//�Ҹ���
};

#endif // !_NORMALACCOUNT_H_