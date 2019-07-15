#include "common.h"
#include "rent_return.h"
#include "dvdInfo.h"



int AddRentInfo(char * ID, int * Date, char *ISBN)
{
	dvdrent * pRent;
	dvdInfo * pDVDrent;

	pRent = (dvdrent *)malloc(sizeof(dvdrent));
	pDVDrent = GetDVDPtrByISBN(ISBN);

	if (pDVDrent->numOfRentCus >= RENT_LEN)
		return 0;

	strcpy(pRent->cusID, ID);
	pRent->Date = * Date;
	strcpy(pRent->ISBN, ISBN);
	
	
	pDVDrent->rentList[(pDVDrent->numOfRentCus)++] = *pRent;
	
	if (pDVDrent->rentState == RETURNED)
	{
		pDVDrent->rentState = RENTED;
		printf("�뿩�� �Ϸ�Ǿ����ϴ�.");
		getchar();

	}
	else
	{
		printf("�뿩 ���� DVD�̹Ƿ�, �뿩�� �Ұ����մϴ�.\n");
		getchar();
	
	}

	return pDVDrent->numOfRentCus;
}

