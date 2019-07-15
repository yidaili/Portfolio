#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "screenOut.h"

void ShowMenu(void)
{
	system("cls"); //stdlib.h에 위치. window 운영체제에서 사용하는 키워드. 운영체제 마다 다름

	printf("----- 메 뉴 -----\n");
	printf("1. 신규가입 \n");
	printf("2. 회원조회 \n");
	printf("3. DVD 등록 \n");
	printf("4. DVD 조회 \n");
	printf("5. DVD 대여 \n");
	printf("6. DVD 반납 \n");
	printf("7. DVD 대여 이력 조회 \n");
	printf("8. 고객 대여 이력 조회 \n");
	printf("9. 종료 \n");
	printf("-----------------\n");
	printf("메뉴 번호 입력 후 Enter(엔터)를 누르세요 >> ");
}

void ShowCustomerInfo(cusInfo * pCus)
{
	printf("------------------------\n");
	printf(" ID : %s \n", pCus->ID);
	printf(" Name : %s \n", pCus->name);
	printf(" Phone : %s \n", pCus->phoneNum);
	printf("------------------------\n");
	printf("\n계속 진행하시려면 Enter(엔터)를 누르세요.");
	getchar();
}

void ShowDVDInfo(dvdInfo * pDVD)
{
	printf("------------------------\n");
	printf(" ISBN : %s \n", pDVD->ISBN);
	printf(" 제목 : %s \n", pDVD->title);
	ShowGenre((*pDVD).genre);
	printf("------------------------\n");
	printf("\n계속 진행하시려면 Enter(엔터)를 누르세요.");
	getchar();
}

void ShowGenre(int gen)
{
	switch (gen)
	{
	case ACTION:
		printf(" 장르 : 액션\n");
		break;
	case COMIC:
		printf(" 장르 : 코믹\n");
		break;
	case SF:
		printf(" 장르 : SF\n");
		break;
	case ROMANTIC:
		printf(" 장르 : 로맨틱\n");
		break;
	}
}

void ShowDVDrentInfo(void)
{

	SearchDVDrentInfo();
}

void ShowIDrentInfo()
{
	char ID[ID_LEN];

	printf("대여 정보를 찾을 ID 입력 : ");
	gets(ID);

	SearchIDrentInfo(ID);
}