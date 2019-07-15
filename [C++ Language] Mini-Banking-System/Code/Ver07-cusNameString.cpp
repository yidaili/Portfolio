#include "Ver07-cusNameString.h"

String::String() :strLen(0)
{
	str = new char;
}

String::String(const char * str)
{
	strLen = strlen(str);
	this->str = new char[strLen + 1];
	strcpy(this->str, str);
}

String::String(const String & copy) :strLen(copy.strLen)
{
	str = new char[copy.strLen + 1];
	strcpy(str, copy.str);
}

void String::operator=(const String & ref)
{
	strLen = ref.strLen;
	this->str = new char[strLen + 1];
	strcpy(this->str, ref.str);
}

void String::operator+=(const String & ref)
{
	delete[]str;
	strLen += ref.strLen;
	str = new char[strLen + 1];
	strcpy(str, ref.str);
}

bool String::operator==(String & ref)
{
	if (!strcmp(str, ref.str))
		return true;
	return false;
}

String String::operator+(const String & ref) const
{
	char * temp = new char[strLen + ref.strLen + 1];
	strcpy(temp, str);
	strcat(temp, ref.str);
	String tempStr(temp);
	delete temp;
	return tempStr;
}

String::~String()
{
	delete[]str;
}

ostream & operator<<(ostream & ostm, const String & str)
{
	ostm << str.str;
	return ostm;
}

istream & operator>>(istream & istm, String & str)
{
	char str_tmp[NAME_LEN];

	istm >> str_tmp;
	str = String(str_tmp);
	return istm;
}