#ifndef _ACCOUNTEXCEPTION_H
#define _ACCOUNTEXCEPTION_H

#include "BankingSysCommon.h"

class AccountException
{
public:
	virtual void ShowExceptionReason() = 0;
};

//�Աݿ��� class
class DepositException :public AccountException
{
private:
	int depositMoney;
public:
	DepositException(int money);	//������
	void ShowExceptionReason();		//���� �޽��� ���
};

//0���� ���� ��ݿ��� class
class MinusWithdrawException :public AccountException
{
private:
	int balance;
public:
	MinusWithdrawException(int money);	//������
	void ShowExceptionReason();		//���� �޽��� ���
};

//�ܾ׺��� ���� ��ݿ��� class
class balanceWithdrawException :public AccountException
{
private:
	int balance;
public:
	balanceWithdrawException(int money);	//������
	void ShowExceptionReason();		//���� �޽��� ���
};

//���� ������� ���� class
class accNumException :public AccountException
{
public:
	accNumException();	//������
	void ShowExceptionReason();		//���� �޽��� ���
};
#endif // !_ACCOUNTEXCEPTION_H
