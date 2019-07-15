#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"

void RegistDVD(void)
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	printf("ISBN �Է� : ");
	gets(ISBN);

	if (IsRegistISBN(ISBN))
	{
		puts("�̹� ��ϵǾ� �ִ� ISBN �Դϴ�.");
		printf("\n��� �����Ͻ÷��� Enter(����)�� ��������.");
		getchar();
		return;
	}

	printf("���� �Է� : ");
	gets(title);
	
	printf("\n----- �� �� -----\n");
	printf("1. �׼� \n");
	printf("2. �ڹ� \n");
	printf("3. SF \n");
	printf("4. �θ�ƽ \n");
	printf("-----------------\n");
	printf("�帣 ��ȣ �Է� �� Enter(����)�� ��������. >> ");
	scanf("%d", &genre);
	getchar();
	
	if (genre > 0 && genre < 5)
	{
		if (!AddDVDInfo(ISBN, title, genre))
		{
			puts("������ ���忡 �����߽��ϴ�.");
			printf("\n��� �����Ͻ÷��� Enter(����)�� ��������.");
			getchar();
			return;
		}

		puts("DVD ����� �Ϸ� �Ǿ����ϴ�.");
		printf("\n��� �����Ͻ÷��� Enter(����)�� ��������.");
		getchar();
	}
	else
	{
		printf("�߸��� �����Դϴ�. �ٽ� �Է��ϼ���.");
		printf("\n��� �����Ͻ÷��� Enter(����)�� ��������.");
		getchar();
		return;
	}

}

void SearchDVDInfo(void)
{
	char ISBN[ISBN_LEN];

	dvdInfo * dvdPtr;

	printf("ã�� DVD ISBN �Է� : ");
	gets(ISBN);
	
	dvdPtr = GetDVDPtrByISBN(ISBN);

	if (dvdPtr == 0)
	{
		printf("ã���� ���� ISBN �Դϴ�.\n");
		printf("\n��� �����Ͻ÷��� Enter(����)�� ��������.");
		getchar();
	}

	else
		ShowDVDInfo(dvdPtr);
}