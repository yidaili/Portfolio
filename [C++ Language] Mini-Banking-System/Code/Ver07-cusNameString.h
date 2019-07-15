#ifndef _CUSNAMESTRING_H
#define _CUSNAMESTRING_H
#include "BankingSysCommon.h"

class String
{
private:
	int strLen;	//문자열 길이 멤버 변수
	char * str;	//문자열 배열 주소
public:
	String();	//기본 생성자
	String(const char * str);					//매개변수가 있는 생성자
	String(const String & copy);				//복사 생성자
	void operator=(const String & ref);			//대입연산자
	void operator+=(const String & ref);		//"+="연산자 오버로딩
	bool operator==(String & ref);				//"=="연산자 오버로딩
	String operator+(const String & ref) const;	//"+"연산자 오버로딩
	~String();	//소멸자
	//"<<"연산자 오버로딩
	friend ostream & operator<<(ostream & ostm, const String & str);
	//">>"연산자 오버로딩
	friend istream & operator>>(istream & istm, String & str);
};

ostream & operator<<(ostream & ostm, const String & str);

istream & operator>>(istream & istm, String & str);

#endif // !_CUSNAMESTRING_H
