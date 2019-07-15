#include "common.h"
#include "cusInfoAccess.h"
#include "dvdInfoAccess.h"

extern dvdInfo * dvdList;
extern int numOfdvd;

//�뿩���� ����
void RegistDVDrentInfo(void)
{
	char rentID[CUSID_LEN];
	int rentDate;
	char rentISBN[ISBN_LEN];

	printf("�뿩 �� ID �Է� : ");
	gets(rentID);

	if (!IsregistID(rentID))
	{
		printf("�Էµ� ID�� ���Ե� ���� �����ϴ�.\n");
		printf("\n��� �����Ͻ÷��� Enter(����)�� ��������.");
		getchar();
		return;
	}

	printf("�뿩�� DVD�� ISBN �Է� : ");
	gets(rentISBN);

	if (!IsRegistISBN(rentISBN))
	{
		printf("��ϵ��� ���� DVD ISBN �Դϴ�.");
		getchar();
		return;
	}

	printf("�뿩 ��¥ �Է�(ex. 20190101) : ");
	scanf("%d",&rentDate);
	getchar();

	if (!AddRentInfo(rentID, &rentDate, rentISBN))
	{
		puts("������ ���忡 �����߽��ϴ�.");
		printf("\n��� �����Ͻ÷��� Enter(����)�� ��������.");
		getchar();
		return;
	}
}


//�ݳ�, �뿩������ ���ؼ� �޽���
void ReturnInfo(void)
{
	char ISBN[ISBN_LEN];
	dvdInfo * pReturn;

	printf("�ݳ��� DVD ISBN �Է� : ");
	gets(ISBN);

	pReturn = GetDVDPtrByISBN(ISBN);

	if (!IsRegistISBN(ISBN))
	{
		printf("��ϵ��� ���� DVD ISBN �Դϴ�.");
		printf("\n��� �����Ͻ÷��� Enter(����)�� ��������.");
		getchar();
		return;
	}
	
	if (pReturn->rentState == RENTED)
	{
		pReturn->rentState = RETURNED;
		printf("�ݳ��� �Ϸ�Ǿ����ϴ�.");
		printf("\n��� �����Ͻ÷��� Enter(����)�� ��������.");

		getchar();
		return;
	}
	else
	{
		printf("�뿩���� ���� DVD �Դϴ�.");
		printf("\n��� �����Ͻ÷��� Enter(����)�� ��������.");
		getchar();
		return;
	}
}

void SearchDVDrentInfo(void)
{
	cusInfo *rentCusptr;
	char ISBN[ISBN_LEN];

	printf("�뿩 ������ ã�� DVD ISBN �Է� : ");
	gets(ISBN);
	
	if (dvdList->numOfRentCus)
	{
		printf("\nDVD ISBN %s�� �뿩 ����\n", ISBN);
		printf("===============================================================\n");
		printf("ID           �̸�             ��ȭ��ȣ            �뿩��¥\n");

		for (int i = 0; i < numOfdvd; i++)
		{
			for (int j = 0; j < dvdList[i].numOfRentCus; j++) {

				rentCusptr = GetCusPtrByID(dvdList[i].rentList[j].cusID);

				printf("%s         %s          %s         %d\n",
					dvdList[i].rentList[j].cusID, rentCusptr->name, rentCusptr->phoneNum, dvdList[i].rentList[j].Date);
			}
		}
		printf("\n��� �����Ͻ÷��� Enter(����)�� ��������.");
		getchar();

	}
	else
	{
		printf("\n�뿩 �̷��� �����ϴ�.");
		printf("\n��� �����Ͻ÷��� Enter(����)�� ��������.");
		getchar();
		return;
	}
}

void SearchIDrentInfo(char *ID)
{
	int StartRentDate, EndRentDate;

	printf("�뿩 ���� �˻� �Ⱓ �Է�\n");
	printf("�˻� ���� ��¥(ex 20180101) -> ");
	scanf("%d", &StartRentDate);
	getchar();
	printf("�˻� ���� ��¥(ex 20190301) -> ");
	scanf("%d", &EndRentDate);
	getchar();

	printf("\n==========================================================\n");
	printf("ID %s ���� %d ���� %d ���� �뿩 ����\n", ID, StartRentDate, EndRentDate);
	printf("============================================================\n");
	printf("�뿩 ��¥         DVD ����         DVD ISBN          �帣\n");

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
						printf("�׼�\n");
						break;
					case COMIC:
						printf("�ڹ�\n");
						break;
					case SF:
						printf("SF\n");
						break;
					case ROMANTIC:
						printf("�θ�ƽ\n");
						break;
					}
					printf("\n��� �����Ͻ÷��� Enter(����)�� ��������.");
					getchar();
					getchar();
					return;
				}
				else
				{
					printf("�ش� �Ⱓ���� �뿩 �̷��� �����ϴ�.");
					printf("\n��� �����Ͻ÷��� Enter(����)�� ��������.");
					getchar();
					return;
				}
			}
		}
	}
	
}