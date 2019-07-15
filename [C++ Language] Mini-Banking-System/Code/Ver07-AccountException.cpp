#include "Ver07-AccountException.h"

//���� ����
DepositException::DepositException(int money) :depositMoney(money)
{}

void DepositException::ShowExceptionReason()
{
	cout << "�˸� : " << depositMoney << "���� �ԱݺҰ�!!" << endl;
}

//0���� ���� ��� ����
MinusWithdrawException::MinusWithdrawException(int money) :balance(money)
{}

void MinusWithdrawException::ShowExceptionReason()
{
	cout << "�˸� : " << balance << "���� ��ݺҰ�!!" << endl;
}

//�ܾ׺��� ���� ��� ����
balanceWithdrawException::balanceWithdrawException(int money) :balance(money)
{}

void balanceWithdrawException::ShowExceptionReason()
{
	cout << "�˸� : �ܾ׺���!!" << balance << "���� ��ݺҰ�!!" << endl;
}

//���� ������� ����
accNumException::accNumException() {}

void accNumException::ShowExceptionReason()
{
	cout << "�˸� : �� �̻� ���¸� ������ �� �����ϴ�." << endl;
}