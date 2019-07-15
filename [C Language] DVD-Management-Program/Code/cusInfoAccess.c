#include "common.h"
#include "cusInfo.h"


#define MAX_CUSTOMER 100

//분할컴파일에서 전역변수 선언시
//extern -> 공유, static -> 공유하지 않겠다
// 다른 파일에서의 변수를 참조하려면 extern을 앞에 붙여서 이용한다 
cusInfo * cusList[MAX_CUSTOMER]; //static 키워드를 사용하면 다른 파일에서 사용할 수 없다. 해당 파일에서만 사용가능
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