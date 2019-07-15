#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"

void RegistDVD(void)
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	printf("ISBN 입력 : ");
	gets(ISBN);

	if (IsRegistISBN(ISBN))
	{
		puts("이미 등록되어 있는 ISBN 입니다.");
		printf("\n계속 진행하시려면 Enter(엔터)를 누르세요.");
		getchar();
		return;
	}

	printf("제목 입력 : ");
	gets(title);
	
	printf("\n----- 장 르 -----\n");
	printf("1. 액션 \n");
	printf("2. 코믹 \n");
	printf("3. SF \n");
	printf("4. 로맨틱 \n");
	printf("-----------------\n");
	printf("장르 번호 입력 후 Enter(엔터)를 누르세요. >> ");
	scanf("%d", &genre);
	getchar();
	
	if (genre > 0 && genre < 5)
	{
		if (!AddDVDInfo(ISBN, title, genre))
		{
			puts("데이터 저장에 실패했습니다.");
			printf("\n계속 진행하시려면 Enter(엔터)를 누르세요.");
			getchar();
			return;
		}

		puts("DVD 등록이 완료 되었습니다.");
		printf("\n계속 진행하시려면 Enter(엔터)를 누르세요.");
		getchar();
	}
	else
	{
		printf("잘못된 선택입니다. 다시 입력하세요.");
		printf("\n계속 진행하시려면 Enter(엔터)를 누르세요.");
		getchar();
		return;
	}

}

void SearchDVDInfo(void)
{
	char ISBN[ISBN_LEN];

	dvdInfo * dvdPtr;

	printf("찾을 DVD ISBN 입력 : ");
	gets(ISBN);
	
	dvdPtr = GetDVDPtrByISBN(ISBN);

	if (dvdPtr == 0)
	{
		printf("찾을수 없는 ISBN 입니다.\n");
		printf("\n계속 진행하시려면 Enter(엔터)를 누르세요.");
		getchar();
	}

	else
		ShowDVDInfo(dvdPtr);
}