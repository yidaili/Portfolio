#ifndef _ACCOUNTHANDLER_H_
#define _ACCOUNTHANDLER_H_

#include "Ver07-NormalAccount.h"
#include "Ver07-HighCreditAccount.h"

typedef Account * accPtr;

template <typename T>
class AccountHandler	//Controll Class
{
private:
	T * accList;			//계좌를 관리할 배열
	int accNum;					//개설된 계좌 수
public:
	AccountHandler();					//생성자
	T & operator[](int idx);			//배열 인덱스 오버로딩-수정용
	T operator[](int idx) const;//배열 인덱스 오버로딩-출력용
	void ReadFile(void);				//파일 읽기
	void MakeAccount(void);				//계좌 개설
	void MakeNormalAccount(const String name, int AccNum, int initMoney);		//보통예금계좌 개설
	void MakeHighCreditAccount(const String name, int AccNum, const char level, int initMoney);	//신용신뢰계좌 개설
	void DepositMoney(void);			//입금
	void WithdrawMoney(void);			//출금
	void ShowAllAccInfo(void);			//잔액조회
	String GetCusName(void);			//고객이름 반환
	void AccInfoWrite(void);			//파일 쓰기
	~AccountHandler(void);				//소멸자
};

#endif // !_ACCOUNTHANDLER_H_

