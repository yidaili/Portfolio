#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

void RegisterCustomer(void)
{
	char ID[ID_LEN];
	char Name[NAME_LEN];
	char PhoneNum[PHONE_LEN];

	printf("ID 입력 : ");
	gets(ID);
	
	if (IsregistID(ID))  //배열이기 때문에 '&' 사용하지 않는다
	{
		puts("해당 ID는 사용중입니다.");
		printf("\n계속 진행하시려면 Enter(엔터)를 누르세요.");
		getchar();
		return;		//함수를 빠져나감
	}

	printf("이름 입력 : ");
	gets(Name);

	printf("전화번호 입력 : ");
	gets(PhoneNum);

	if (!AddCusInfo(ID, Name, PhoneNum))
	{
		puts("데이터 저장에 실패했습니다.");
		printf("\n계속 진행하시려면 Enter(엔터)를 누르세요.");
		getchar();
		return;
	}

	puts("회원 가입이 완료 되었습니다.");
	printf("\n계속 진행하시려면 Enter(엔터)를 누르세요.");
	getchar();
}

void SearchCusInfo(void)
{
	char ID[ID_LEN];
	cusInfo *cusPtr;

	printf("찾을 ID 입력 : ");
	gets(ID);

	cusPtr = GetCusPtrByID(ID);
	if (cusPtr == 0)
	{
		puts("존재하지 않는 ID입니다.");
		printf("\n계속 진행하시려면 Enter(엔터)를 누르세요.");
		getchar();
		return;
	}

	ShowCustomerInfo(cusPtr);
}