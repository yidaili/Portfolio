#include "Ver07-Account.h"

Account::Account(const String name = "ȫ�浿")	//������
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