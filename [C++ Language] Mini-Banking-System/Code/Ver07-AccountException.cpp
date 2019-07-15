#include "Ver07-AccountException.h"

//예금 예외
DepositException::DepositException(int money) :depositMoney(money)
{}

void DepositException::ShowExceptionReason()
{
	cout << "알림 : " << depositMoney << "원은 입금불가!!" << endl;
}

//0보다 작은 출금 예외
MinusWithdrawException::MinusWithdrawException(int money) :balance(money)
{}

void MinusWithdrawException::ShowExceptionReason()
{
	cout << "알림 : " << balance << "원은 출금불가!!" << endl;
}

//잔액보다 작은 출금 예외
balanceWithdrawException::balanceWithdrawException(int money) :balance(money)
{}

void balanceWithdrawException::ShowExceptionReason()
{
	cout << "알림 : 잔액부족!!" << balance << "원은 출금불가!!" << endl;
}

//계좌 저장공간 예외
accNumException::accNumException() {}

void accNumException::ShowExceptionReason()
{
	cout << "알림 : 더 이상 계좌를 개설할 수 없습니다." << endl;
}