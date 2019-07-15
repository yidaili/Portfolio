#include "common.h"
#include "cusInfo.h"


#define MAX_CUSTOMER 100

//���������Ͽ��� �������� �����
//extern -> ����, static -> �������� �ʰڴ�
// �ٸ� ���Ͽ����� ������ �����Ϸ��� extern�� �տ� �ٿ��� �̿��Ѵ� 
cusInfo * cusList[MAX_CUSTOMER]; //static Ű���带 ����ϸ� �ٸ� ���Ͽ��� ����� �� ����. �ش� ���Ͽ����� ��밡��
int numOfCustomer = 0;

int AddCusInfo(char * ID, char * name, char * num)
{
	cusInfo *pCus;

	if (numOfCustomer >= MAX_CUSTOMER)
		return 0;

	pCus = (cusInfo *)malloc(sizeof(cusInfo));

	strcpy(pCus->ID, ID);
	strcpy(pCus->name, name);
	strcpy(pCus->phoneNum, num);

	cusList[numOfCustomer++] = pCus;
	
	return numOfCustomer;
}

cusInfo * GetCusPtrByID(char * ID)
{
	int i;

	for (i = 0; i < numOfCustomer; i++)
	{
		if (!strcmp(cusList[i]->ID, ID)) return cusList[i];
	}

	return NULL;
}

int IsregistID(char * ID)
{
	cusInfo *pCus = GetCusPtrByID(ID);

	if (pCus == NULL)
		return 0;
	else
		return 1;
}