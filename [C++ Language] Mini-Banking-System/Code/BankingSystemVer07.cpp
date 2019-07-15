/*
1. �ý��۸� : BankingSystem
2. ����     : 7.0
3. �����   : ������
4. ����
	4.1 OOP(��ü����) �ܰ躰 ������Ʈ�� �⺻Ʋ ����
	4.2 Ŭ���� ����(������, �Ҹ���, ��������� ����)
	4.3 ��Ʈ��, ����Ƽ Ŭ����
	4.4 ���� ����
	4.5 �迭Ŭ����, String Ŭ���� ����
	4.6 ����ó��, ��������� ����
	4.7 ���ø� ����
*/

#include "Ver07-AccountHandler.cpp"

void ShowMenu(void);

int main(void)
{
	AccountHandler<accPtr> * accHandler = new AccountHandler<accPtr>;

	accHandler->ReadFile();

	int choice;		//�޴� ����

	while (1)
	{
		

		ShowMenu();

		cout << "���� : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			accHandler->MakeAccount();
			break;
		case DEPOSIT:
			accHandler->DepositMoney();
			break;
		case WITHDRAW:
			accHandler->WithdrawMoney();
			break;
		case INQUIRE:
			accHandler->ShowAllAccInfo();
			break;
		case EXIT:
			accHandler->~AccountHandler();
			return 0;
		default:
			cout << "���� �޴��Դϴ�. �ٽ� �������ּ���." << endl;
		}
	}

	return 0;
}

//�޴����
void ShowMenu(void)
{
	system("cls");

	cout << "====== Menu ======" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. ��    ��" << endl;
	cout << "3. ��    ��" << endl;
	cout << "4. ������ȸ" << endl;
	cout << "5. ��    ��" << endl;
	cout << "==================" << endl;
}