#include "common.h"
#include "cusInfoAccess.h"
#include "dvdInfoAccess.h"

extern dvdInfo * dvdList;
extern int numOfdvd;

//대여정보 저장
void RegistDVDrentInfo(void)
{
	char rentID[CUSID_LEN];
	int rentDate;
	char rentISBN[ISBN_LEN];

	printf("대여 고객 ID 입력 : ");
	gets(rentID);

	if (!IsregistID(rentID))
	{
		printf("입력된 ID로 가입된 고객이 없습니다.\n");
		printf("\n계속 진행하시려면 Enter(엔터)를 누르세요.");
		getchar();
		return;
	}

	printf("대여할 DVD의 ISBN 입력 : ");
	gets(rentISBN);

	if (!IsRegistISBN(rentISBN))
	{
		printf("등록되지 않은 DVD ISBN 입니다.");
		getchar();
		return;
	}

	printf("대여 날짜 입력(ex. 20190101) : ");
	scanf("%d",&rentDate);
	getchar();

	if (!AddRentInfo(rentID, &rentDate, rentISBN))
	{
		puts("데이터 저장에 실패했습니다.");
		printf("\n계속 진행하시려면 Enter(엔터)를 누르세요.");
		getchar();
		return;
	}
}


//반납, 대여정보와 비교해서 메시지
void ReturnInfo(void)
{
	char ISBN[ISBN_LEN];
	dvdInfo * pReturn;

	printf("반납할 DVD ISBN 입력 : ");
	gets(ISBN);

	pReturn = GetDVDPtrByISBN(ISBN);

	if (!IsRegistISBN(ISBN))
	{
		printf("등록되지 않은 DVD ISBN 입니다.");
		printf("\n계속 진행하시려면 Enter(엔터)를 누르세요.");
		getchar();
		return;
	}
	
	if (pReturn->rentState == RENTED)
	{
		pReturn->rentState = RETURNED;
		printf("반납이 완료되었습니다.");
		printf("\n계속 진행하시려면 Enter(엔터)를 누르세요.");

		getchar();
		return;
	}
	else
	{
		printf("대여되지 않은 DVD 입니다.");
		printf("\n계속 진행하시려면 Enter(엔터)를 누르세요.");
		getchar();
		return;
	}
}

void SearchDVDrentInfo(void)
{
	cusInfo *rentCusptr;
	char ISBN[ISBN_LEN];

	printf("대여 정보를 찾을 DVD ISBN 입력 : ");
	gets(ISBN);
	
	if (dvdList->numOfRentCus)
	{
		printf("\nDVD ISBN %s의 대여 정보\n", ISBN);
		printf("===============================================================\n");
		printf("ID           이름             전화번호            대여날짜\n");

		for (int i = 0; i < numOfdvd; i++)
		{
			for (int j = 0; j < dvdList[i].numOfRentCus; j++) {

				rentCusptr = GetCusPtrByID(dvdList[i].rentList[j].cusID);

				printf("%s         %s          %s         %d\n",
					dvdList[i].rentList[j].cusID, rentCusptr->name, rentCusptr->phoneNum, dvdList[i].rentList[j].Date);
			}
		}
		printf("\n계속 진행하시려면 Enter(엔터)를 누르세요.");
		getchar();

	}
	else
	{
		printf("\n대여 이력이 없습니다.");
		printf("\n계속 진행하시려면 Enter(엔터)를 누르세요.");
		getchar();
		return;
	}
}

void SearchIDrentInfo(char *ID)
{
	int StartRentDate, EndRentDate;

	printf("대여 정보 검색 기간 입력\n");
	printf("검색 시작 날짜(ex 20180101) -> ");
	scanf("%d", &StartRentDate);
	getchar();
	printf("검색 종료 날짜(ex 20190301) -> ");
	scanf("%d", &EndRentDate);
	getchar();

	printf("\n==========================================================\n");
	printf("ID %s 님의 %d 부터 %d 까지 대여 정보\n", ID, StartRentDate, EndRentDate);
	printf("============================================================\n");
	printf("대여 날짜         DVD 제목         DVD ISBN          장르\n");

	for (int i = 0; i < numOfdvd; i++)
	{
		for (int j = 0; j < dvdList[i].numOfRentCus; j++) {
			if (!strcmp(dvdList[i].rentList[j].cusID, ID))
			{
				if (dvdList[i].rentList[j].Date >= StartRentDate && dvdList[i].rentList[j].Date <= EndRentDate)
				{
					printf("%d          %s          %s          ", 
						dvdList[i].rentList[j].Date, dvdList[i].title, dvdList[i].ISBN);

					switch (dvdList[i].genre)
					{
					case ACTION:
						printf("액션\n");
						break;
					case COMIC:
						printf("코믹\n");
						break;
					case SF:
						printf("SF\n");
						break;
					case ROMANTIC:
						printf("로맨틱\n");
						break;
					}
					printf("\n계속 진행하시려면 Enter(엔터)를 누르세요.");
					getchar();
					getchar();
					return;
				}
				else
				{
					printf("해당 기간동안 대여 이력이 없습니다.");
					printf("\n계속 진행하시려면 Enter(엔터)를 누르세요.");
					getchar();
					return;
				}
			}
		}
	}
	
}