#include "common.h"
#include "cusManager.h"
#include "dvdManager.h"
#include "screenOut.h"
#include "rentManager.h"
#include "cusInfoAccess.h"
#include "dvdInfoAccess.h"
#include "rent_return.h"

enum{CUS_REGIST=1, CUS_SEARCH, DVD_REGIST, DVD_SEARCH, RENT, RETURN, DVD_RENTINFO, ID_RENT_INFO, QUIT};

int main(void)
{
	int intputMenu = 0;

	while (1)
	{
		ShowMenu();
		scanf("%d", &intputMenu);
		getchar();

		switch (intputMenu)
		{
		case CUS_REGIST:
			RegisterCustomer();
			break;

		case CUS_SEARCH:
			SearchCusInfo();
			break;

		case DVD_REGIST:
			RegistDVD();
			break;

		case DVD_SEARCH:
			SearchDVDInfo();
			break;

		case RENT:
			RegistDVDrentInfo();
			break;

		case RETURN:
			ReturnInfo();
			break;

		case DVD_RENTINFO:
			ShowDVDrentInfo();
			break;

		case ID_RENT_INFO:
			ShowIDrentInfo();
			break;
		}

		if (intputMenu == QUIT)
		{
			puts("이용해주셔서 감사합니다.");
			break;
		}
	}
	return 0;
}