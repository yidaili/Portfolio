/*
	���	: �� ���� ���� �� ���� �Լ����� ����.
	�ۼ���	: LTH
	�ۼ���	:2019-03-11
	Ver		: 1.0
*/


#ifndef __CUSINFOACCESS_H__
#define __CUSINFOACCESS_H__

#include "cusInfo.h"

/*
	��� : cusInfo �Ҵ� �� ����
	��ȯ : ������ ��ϵ� ������ ����,
		   ���н� 0�� ��ȯ.
*/
int AddCusInfo(char * ID, char * name, char * num);

/*
	��� : �ش� �� ID�� ������ ������ �ִ� �����͸� ��ȯ
	��ȯ : ��� �ȵ� ID�� ��� NULL ������ ��ȯ.
*/
cusInfo * GetCusPtrByID(char * ID);

/*
	��� : ���Ե� ID���� üũ
	��ȯ : ���ԵǾ����� 1, �ƴϸ� 0�� ��ȯ.
*/
int IsregistID(char * ID);

#endif // !__CUSINFOACCESS_H__