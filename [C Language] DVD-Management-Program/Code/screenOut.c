#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "screenOut.h"

void ShowMenu(void)
{
	system("cls"); //stdlib.h�� ��ġ. window �ü������ ����ϴ� Ű����. �ü�� ���� �ٸ�

	printf("----- �� �� -----\n");
	printf("1. �ű԰��� \n");
	printf("2. ȸ����ȸ \n");
	printf("3. DVD ��� \n");
	printf("4. DVD ��ȸ \n");
	printf("5. DVD �뿩 \n");
	printf("6. DVD �ݳ� \n");
	printf("7. DVD �뿩 �̷� ��ȸ \n");
	printf("8. �� �뿩 �̷� ��ȸ \n");
	printf("9. ���� \n");
	printf("-----------------\n");
	printf("�޴� ��ȣ �Է� �� Enter(����)�� �������� >> ");
}

void ShowCustomerInfo(cusInfo * pCus)
{
	printf("------------------------\n");
	printf(" ID : %s \n", pCus->ID);
	printf(" Name : %s \n", pCus->name);
	printf(" Phone : %s \n", pCus->phoneNum);
	printf("------------------------\n");
	printf("\n��� �����Ͻ÷��� Enter(����)�� ��������.");
	getchar();
}

void ShowDVDInfo(dvdInfo * pDVD)
{
	printf("------------------------\n");
	printf(" ISBN : %s \n", pDVD->ISBN);
	printf(" ���� : %s \n", pDVD->title);
	ShowGenre((*pDVD).genre);
	printf("------------------------\n");
	printf("\n��� �����Ͻ÷��� Enter(����)�� ��������.");
	getchar();
}

void ShowGenre(int gen)
{
	switch (gen)
	{
	case ACTION:
		printf(" �帣 : �׼�\n");
		break;
	case COMIC:
		printf(" �帣 : �ڹ�\n");
		break;
	case SF:
		printf(" �帣 : SF\n");
		break;
	case ROMANTIC:
		printf(" �帣 : �θ�ƽ\n");
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

	printf("�뿩 ������ ã�� ID �Է� : ");
	gets(ID);

	SearchIDrentInfo(ID);
}