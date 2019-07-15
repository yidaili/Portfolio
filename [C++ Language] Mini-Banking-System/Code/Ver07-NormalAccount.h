#ifndef _NORMALACCOUNT_H_
#define _NORMALACCOUNT_H_

#include "Ver07-Account.h"

class NormalAccount :public Account
{
private:
	int accID;				//���¹�ȣ
	int balance;			//�ܾ�
	double interestRatio;	//����
public:
	NormalAccount(const String name, int num, int initMoney);			 //������
	NormalAccount(const NormalAccount & copy);							 //default ���� ������
	void SetDepositbalance(int money, const char level);			//�Ա� �� �ܾ� set
	void SetWithdrawbalance(int money);			//��� �� �ܾ� set
	int GetaccID(void) const;					//���¹�ȣ ��ȯ
	int Getbalance(void) const;					//�ܾ� ��ȯ
	virtual char Getlevel(void) const;			//�ſ��� ��ȯ
	~NormalAccount(void);						//�Ҹ���
};

#endif // !_NORMALACCOUNT_H_