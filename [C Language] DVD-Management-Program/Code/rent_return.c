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
		printf("대여가 완료되었습니다.");
		getchar();

	}
	else
	{
		printf("대여 중인 DVD이므로, 대여가 불가능합니다.\n");
		getchar();
	
	}

	return pDVDrent->numOfRentCus;
}

