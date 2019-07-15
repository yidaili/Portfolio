#include "common.h"
#include "dvdInfo.h"

#define MAX_DVDNUM 100

dvdInfo * dvdList[MAX_DVDNUM];
int numOfdvd = 0;

int AddDVDInfo(char * ISBN, char * title, int genre)
{
	dvdInfo * pDVD;

	pDVD = (dvdInfo *)malloc(sizeof(dvdInfo));

	if (numOfdvd >= MAX_DVDNUM)
		return 0;

	strcpy(pDVD->ISBN, ISBN);
	strcpy(pDVD->title, title);
	pDVD->genre = genre;
	pDVD->rentState = RETURNED;
	pDVD->numOfRentCus = 0;

	dvdList[numOfdvd++] = pDVD;

	return numOfdvd;
}

dvdInfo * GetDVDPtrByISBN(char * ISBN)
{
	for (int i = 0; i < numOfdvd; i++)
	{
		if (!strcmp(dvdList[i]->ISBN, ISBN))
			return dvdList[i];
	}

	return (dvdInfo *)0;
}
/*
	��� : �� ��ϵ� ISBN���� üũ.
	��ȯ : ��ϵǾ�����1, �ƴϸ� 0�� ��ȯ.
*/
void IsRegistISBN(char * ISBN)
{
	for (int i = 0; i < numOfdvd; i++)
	{
		if (!strcmp(dvdList[i]->ISBN, ISBN))
			return 1;
	}
	return 0;
}