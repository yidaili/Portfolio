#ifndef _CUSNAMESTRING_H
#define _CUSNAMESTRING_H
#include "BankingSysCommon.h"

class String
{
private:
	int strLen;	//���ڿ� ���� ��� ����
	char * str;	//���ڿ� �迭 �ּ�
public:
	String();	//�⺻ ������
	String(const char * str);					//�Ű������� �ִ� ������
	String(const String & copy);				//���� ������
	void operator=(const String & ref);			//���Կ�����
	void operator+=(const String & ref);		//"+="������ �����ε�
	bool operator==(String & ref);				//"=="������ �����ε�
	String operator+(const String & ref) const;	//"+"������ �����ε�
	~String();	//�Ҹ���
	//"<<"������ �����ε�
	friend ostream & operator<<(ostream & ostm, const String & str);
	//">>"������ �����ε�
	friend istream & operator>>(istream & istm, String & str);
};

ostream & operator<<(ostream & ostm, const String & str);

istream & operator>>(istream & istm, String & str);

#endif // !_CUSNAMESTRING_H
