/*
	���   : �ܼ������ ���� �Լ����� ����.
	�ۼ��� : LTH
	�ۼ��� : 2019-03-11
	Ver	   : 1.0
*/
#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"

/*
	��� : ���α׷��� ����ϱ� ���� �޴� ���
	��ȯ : void
*/
void ShowMenu(void);

/*
	��� : �� ������ ���
	��ȯ : void
*/
void ShowCustomerInfo(cusInfo * pCus);

void ShowDVDInfo(dvdInfo * pDVD);

void ShowGenre(int gen);

void ShowDVDrentInfo(void);

void ShowIDrentInfo(void);
#endif // !__SCREENOUT_H__