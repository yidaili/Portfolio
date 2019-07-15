#include "BankingSysCommon.h"
#include "Ver07-AccountHandler.h"
#include "Ver07-Account.h"
#include "Ver07-HighCreditAccount.h"
#include "Ver07-AccountException.h"

//AccountHandler Class
template <typename T>
AccountHandler<T>::AccountHandler()
{
	accList = new Account *[ACC_MAX_LEN];
	accNum = 0;
}

template <typename T>
T& AccountHandler<T>::operator[](int idx)
{
	if (idx < 0 || idx >= accNum)
	{
		cout << "�ùٸ� �ε��� ���� �־��ּ���" << endl;
	}
	return *accList[idx];
}

template <typename T>
T AccountHandler<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= accNum)
	{
		cout << "�ùٸ� �ε��� ���� �־��ּ���" << endl;
	}
	return *accList[idx];
}

template <typename T>
void AccountHandler<T>::ReadFile()
{
	ifstream fin("MiniBankingCusInfo.txt");

	char* name = new char[NAME_LEN];
	int accID;
	int balance;
	char level;

	if (fin.is_open())
	{
		while (!fin.eof())//eof() -> ������ ���̸� true
		{
			fin >> level >> name >> accID >> balance;
			
			if (level == 'N')
			{
				accList[accNum] = new NormalAccount(name, accNum, balance);
				accNum++;
			}
			else if (level == 'A' || level == 'B' || level == 'C')
			{
				accList[accNum] = new HighCreditAccount(name, accNum, level, balance);
				accNum++;
			}
		}
	}
	else
	{
		cout << "������ ������ �ʾҽ��ϴ�." << endl;
		exit(1);
	}
	fin.close();	
}

template <typename T>
void AccountHandler<T>::MakeAccount(void)	//���� ����
{
	//ReadFile();

	system("cls");

	cout << "������ ���� �̸��� �Է��ϸ� ���°� �����˴ϴ�." << endl;
	cout << "(����Ϸ��� 1, �޴��� ���ư����� 2 �Է�)";

	int back;
	cin >> back;
	if (back != 2)
	{
		int choice;

		while (1)
		{
			cout << endl << "<< ������ ���� ������ �����ϼ���. >>" << endl << endl;
			cout << "1. �������   2. �ſ��ް���" << endl;
			cout << "���� : ";
			cin >> choice;

			int makeAccMoney;
			char name[NAME_LEN];
			switch (choice)
			{
			default:
				cout << "�߸��� �����Դϴ�. �ٽ� �����ϼ���." << endl;
			case NORMAL:
				cout << endl << "�� �̸� �Է� : ";
				cin >> name;
				cout << endl << "���� ������ �Ա� �ݾ� : ";
				cin >> makeAccMoney;

				if (makeAccMoney < 0)
				{
					try
					{
						DepositException expn(makeAccMoney);
						throw expn;
					}
					catch (AccountException & expn)
					{
						expn.ShowExceptionReason();
						getchar();
						getchar();
						break;
					}
				}
				if (accNum > ACC_MAX_LEN)
				{
					try
					{
						accNumException expn;
						throw expn;
					}
					catch (AccountException & expn)
					{
						expn.ShowExceptionReason();
						getchar();
						getchar();
						return;
					}
				}
				MakeNormalAccount(name, accNum, makeAccMoney);
				getchar();
				getchar();
				return;

			case CREDIT:
				char level;
				cout << endl << "�� �̸� �Է� : ";
				cin >> name;
				
				while (1)
				{
					cout << endl << "�� �ſ� ���(A, B, C �� �Է�) : ";
					cin >> level;

					if (level == 'A')
					{
						cout << endl << "���� ������ �Ա� �ݾ� : ";
						cin >> makeAccMoney;
						
						if (makeAccMoney < 0)
						{
							try
							{
								DepositException expn(makeAccMoney);
								throw expn;
							}
							catch (AccountException & expn)
							{
								expn.ShowExceptionReason();
								getchar();
								getchar();
								return;
							}
						}
						else break;
					}
					else if (level == 'B')
					{
						cout << endl << "���� ������ �Ա� �ݾ� : ";
						cin >> makeAccMoney;

						if (makeAccMoney < 0)
						{
							try
							{
								DepositException expn(makeAccMoney);
								throw expn;
							}
							catch (AccountException & expn)
							{
								expn.ShowExceptionReason();
								getchar();
								getchar();
								return;
							}
						}
						else break;
					}
					else if(level == 'C')
					{
						cout << endl << "���� ������ �Ա� �ݾ� : ";
						cin >> makeAccMoney;

						if (makeAccMoney < 0)
						{
							try
							{
								DepositException expn(makeAccMoney);
								throw expn;
							}
							catch (AccountException & expn)
							{
								expn.ShowExceptionReason();
								getchar();
								getchar();
								return;
							}
						}
						else break;
					}
					cout << "A, B, C �� �ٽ� �Է� �ϼ���." << endl;
				}

				if (accNum > ACC_MAX_LEN)
				{
					try
					{
						accNumException expn;
						throw expn;
					}
					catch (AccountException & expn)
					{
						expn.ShowExceptionReason();
						getchar();
						getchar();
						return;
					}
				}
				MakeHighCreditAccount(name, accNum, level, makeAccMoney);
				getchar();
				getchar();
				return;
			}
		}
		getchar();
		getchar();
		return;
	}
	else return;
}

template <typename T>
void AccountHandler<T>::MakeNormalAccount(const String name, int AccNum, int initMoney)
{
	accList[accNum] = new NormalAccount(name, AccNum, initMoney);

	system("cls");
	cout << "<< ���� ���� �Ϸ�!! >>" << endl;
	cout << "���� ������ : " << accList[accNum]->GetcusName() << endl;
	cout << "���� ��ȣ : " << accList[accNum]->GetaccID() << endl;
	cout << "���� �ܾ� : " << accList[accNum]->Getbalance() << "��" << endl;
	accNum++;
}

template <typename T>
void AccountHandler<T>::MakeHighCreditAccount(const String name, int AccNum, const char level, int initMoney)
{
	accList[accNum] = new HighCreditAccount(name, AccNum, level, initMoney);

	system("cls");
	cout << "<< ���� ���� �Ϸ�!! >>" << endl;
	cout << "���� ������ : " << accList[accNum]->GetcusName() << endl;
	cout << "�ſ� ��� : " << accList[accNum]->Getlevel() << endl;
	cout << "���� ��ȣ : " << accList[accNum]->GetaccID() << endl;
	cout << "���� �ܾ� : " << accList[accNum]->Getbalance() << "��" << endl;
	accNum++;
}

//�Ա�
template <typename T>
void AccountHandler<T>::DepositMoney(void)
{
	system("cls");

	cout << "�Ա��� �����մϴ�." << endl;
	
	int tmpAcc;
	int DepMoney;

	while (1)
	{
		cout << "�Ա��� ���� ��ȣ �Է�(�޴��� ���ư����� -1 �Է�) : ";
		cin >> tmpAcc;

		if (tmpAcc != -1)
		{
			for (int i = 0; i < accNum; i++)
			{
				if (tmpAcc == accList[i]->GetaccID())
				{
					cout << endl << "�Ա��� �ݾ� : ";
					cin >> DepMoney;
					
					if (DepMoney < 0)
					{
						try
						{
							DepositException expn(DepMoney);
							throw expn;
						}
						catch (AccountException & expn)
						{
							expn.ShowExceptionReason();
							getchar();
							getchar();
							return;
						}
					}
					else
					{
						accList[i]->SetDepositbalance(DepMoney, accList[i]->Getlevel());

						cout << endl << "�Ա� �� �ܾ� : " << accList[i]->Getbalance() << "��" << endl;
						getchar();
						getchar();
						return;
					}
				}
			}
			cout << endl << "��ġ�ϴ� ���¹�ȣ�� �����ϴ�." << endl << endl;
		}
		else return;
	}
}

//���
template <typename T>
void AccountHandler<T>::WithdrawMoney(void)
{
	system("cls");

	cout << "����� �����մϴ�." << endl;

	int tmpAcc;
	int Money;

	while (1)
	{
		cout << "����� ���� ��ȣ(�޴��� ���ư����� -1 �Է�) : ";
		cin >> tmpAcc;

		if (tmpAcc != -1)
		{
			for (int i = 0; i < accNum; i++)
			{
				if (tmpAcc == accList[i]->GetaccID())
				{
					cout << endl << "����� �ݾ� : ";
					cin >> Money;

					if (Money < 0)
					{
						try
						{
							MinusWithdrawException expn(Money);
							throw expn;
						}
						catch (AccountException & expn)
						{
							expn.ShowExceptionReason();
							getchar();
							getchar();
							return;
						}
					}
					else if (Money > accList[i]->Getbalance())
					{
						try
						{
							balanceWithdrawException expn(Money);
							throw expn;
						}
						catch (AccountException & expn)
						{
							expn.ShowExceptionReason();
							getchar();
							getchar();
							return;
						}
					}
					else if (accList[i]->Getbalance() >= Money)
					{
						accList[i]->SetWithdrawbalance(Money);

						cout << endl << "��� �� �ܾ� : " << accList[i]->Getbalance() << "��" << endl;
						getchar();
						getchar();
						return;
					}
				}
			}
			cout << endl << "��ġ�ϴ� ���¹�ȣ�� �����ϴ�." << endl;
			return;
		}
		else return;
	}
}

//�ܾ���ȸ
template <typename T>
void AccountHandler<T>::ShowAllAccInfo(void)
{
	system("cls");

	for (int i = 0; i < accNum; i++)
	{
		if (accList[i]->Getlevel() == 'N')
		{
			cout << endl << "---------------------------------" << endl;
			cout << "���� ��ȣ : " << accList[i]->GetaccID() << endl;
			cout << "�� �̸� : " << accList[i]->GetcusName()<< endl;
			cout << "���� �ܾ� : " << accList[i]->Getbalance() << "��" << endl;
			cout << "---------------------------------" << endl;
		}
		else
		{
			cout << endl << "---------------------------------" << endl;
			cout << "���� ��ȣ : " << accList[i]->GetaccID() << endl;
			cout << "�� �̸� : " << accList[i]->GetcusName() << endl;
			cout << "�ſ� ��� : " << accList[i]->Getlevel() << endl;
			cout << "���� �ܾ� : " << accList[i]->Getbalance() << "��" << endl;
			cout << "---------------------------------" << endl;
		}
	}
	getchar();
	getchar();
}

template <typename T>
String AccountHandler<T>::GetCusName(void)
{
	return accList[accNum]->GetcusName()->GetNameStr();
}

template <typename T>
void AccountHandler<T>::AccInfoWrite(void)
{
	ofstream fout("MiniBankingCusInfo.txt");

	if (fout.is_open())
	{
		for (int i = 0; i < accNum - 1; i++)
		{
			fout << accList[i]->Getlevel() << '\t';
			fout << accList[i]->GetcusName() << '\t';
			fout << accList[i]->GetaccID() << '\t';
			fout << accList[i]->Getbalance() << '\n';
		}
		fout << accList[accNum - 1]->Getlevel() << '\t';
		fout << accList[accNum - 1]->GetcusName() << '\t';
		fout << accList[accNum - 1]->GetaccID() << '\t';
		fout << accList[accNum - 1]->Getbalance();
	}
	else
	{
		cout << "������ ������ �ʾҽ��ϴ�." << endl;
		exit(1);
	}
	fout.close();
}

template <typename T>
AccountHandler<T>::~AccountHandler(void)
{
	AccInfoWrite();

	for (int i = 0; i < accNum; i++)
	{
		cout << accList[i]->GetcusName() << "�Ҹ�" << endl;
		delete accList[i];
	}
}