#ifndef _ACCOUNTHANDLER_H_
#define _ACCOUNTHANDLER_H_

#include "Ver07-NormalAccount.h"
#include "Ver07-HighCreditAccount.h"

typedef Account * accPtr;

template <typename T>
class AccountHandler	//Controll Class
{
private:
	T * accList;			//���¸� ������ �迭
	int accNum;					//������ ���� ��
public:
	AccountHandler();					//������
	T & operator[](int idx);			//�迭 �ε��� �����ε�-������
	T operator[](int idx) const;//�迭 �ε��� �����ε�-��¿�
	void ReadFile(void);				//���� �б�
	void MakeAccount(void);				//���� ����
	void MakeNormalAccount(const String name, int AccNum, int initMoney);		//���뿹�ݰ��� ����
	void MakeHighCreditAccount(const String name, int AccNum, const char level, int initMoney);	//�ſ�ŷڰ��� ����
	void DepositMoney(void);			//�Ա�
	void WithdrawMoney(void);			//���
	void ShowAllAccInfo(void);			//�ܾ���ȸ
	String GetCusName(void);			//���̸� ��ȯ
	void AccInfoWrite(void);			//���� ����
	~AccountHandler(void);				//�Ҹ���
};

#endif // !_ACCOUNTHANDLER_H_

