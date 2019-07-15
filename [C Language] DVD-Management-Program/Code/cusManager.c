#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

void RegisterCustomer(void)
{
	char ID[ID_LEN];
	char Name[NAME_LEN];
	char PhoneNum[PHONE_LEN];

	printf("ID �Է� : ");
	gets(ID);
	
	if (IsregistID(ID))  //�迭�̱� ������ '&' ������� �ʴ´�
	{
		puts("�ش� ID�� ������Դϴ�.");
		printf("\n��� �����Ͻ÷��� Enter(����)�� ��������.");
		getchar();
		return;		//�Լ��� ��������
	}

	printf("�̸� �Է� : ");
	gets(Name);

	printf("��ȭ��ȣ �Է� : ");
	gets(PhoneNum);

	if (!AddCusInfo(ID, Name, PhoneNum))
	{
		puts("������ ���忡 �����߽��ϴ�.");
		printf("\n��� �����Ͻ÷��� Enter(����)�� ��������.");
		getchar();
		return;
	}

	puts("ȸ�� ������ �Ϸ� �Ǿ����ϴ�.");
	printf("\n��� �����Ͻ÷��� Enter(����)�� ��������.");
	getchar();
}

void SearchCusInfo(void)
{
	char ID[ID_LEN];
	cusInfo *cusPtr;

	printf("ã�� ID �Է� : ");
	gets(ID);

	cusPtr = GetCusPtrByID(ID);
	if (cusPtr == 0)
	{
		puts("�������� �ʴ� ID�Դϴ�.");
		printf("\n��� �����Ͻ÷��� Enter(����)�� ��������.");
		getchar();
		return;
	}

	ShowCustomerInfo(cusPtr);
}