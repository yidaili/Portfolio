#include "Ver07-Account.h"

Account::Account(const String name = "홍길동")	//생성자
{
	cusName = String(name);
}

String Account::GetcusName(void) const
{
	return cusName;
}

Account::~Account(void)
{

}