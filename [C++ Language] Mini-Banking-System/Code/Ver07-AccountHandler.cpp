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
		cout << "올바른 인덱스 값을 넣어주세요" << endl;
	}
	return *accList[idx];
}

template <typename T>
T AccountHandler<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= accNum)
	{
		cout << "올바른 인덱스 값을 넣어주세요" << endl;
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
		while (!fin.eof())//eof() -> 파일의 끝이면 true
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
		cout << "파일이 열리지 않았습니다." << endl;
		exit(1);
	}
	fin.close();	
}

template <typename T>
void AccountHandler<T>::MakeAccount(void)	//계좌 개설
{
	//ReadFile();

	system("cls");

	cout << "개설할 고객의 이름을 입력하면 계좌가 개설됩니다." << endl;
	cout << "(계속하려면 1, 메뉴로 돌아가려면 2 입력)";

	int back;
	cin >> back;
	if (back != 2)
	{
		int choice;

		while (1)
		{
			cout << endl << "<< 개설할 계좌 종류를 선택하세요. >>" << endl << endl;
			cout << "1. 보통계좌   2. 신용등급계좌" << endl;
			cout << "선택 : ";
			cin >> choice;

			int makeAccMoney;
			char name[NAME_LEN];
			switch (choice)
			{
			default:
				cout << "잘못된 선택입니다. 다시 선택하세요." << endl;
			case NORMAL:
				cout << endl << "고객 이름 입력 : ";
				cin >> name;
				cout << endl << "계좌 개설시 입금 금액 : ";
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
				cout << endl << "고객 이름 입력 : ";
				cin >> name;
				
				while (1)
				{
					cout << endl << "고객 신용 등급(A, B, C 중 입력) : ";
					cin >> level;

					if (level == 'A')
					{
						cout << endl << "계좌 개설시 입금 금액 : ";
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
						cout << endl << "계좌 개설시 입금 금액 : ";
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
						cout << endl << "계좌 개설시 입금 금액 : ";
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
					cout << "A, B, C 중 다시 입력 하세요." << endl;
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
	cout << "<< 계좌 개설 완료!! >>" << endl;
	cout << "계좌 명의자 : " << accList[accNum]->GetcusName() << endl;
	cout << "계좌 번호 : " << accList[accNum]->GetaccID() << endl;
	cout << "현재 잔액 : " << accList[accNum]->Getbalance() << "원" << endl;
	accNum++;
}

template <typename T>
void AccountHandler<T>::MakeHighCreditAccount(const String name, int AccNum, const char level, int initMoney)
{
	accList[accNum] = new HighCreditAccount(name, AccNum, level, initMoney);

	system("cls");
	cout << "<< 계좌 개설 완료!! >>" << endl;
	cout << "계좌 명의자 : " << accList[accNum]->GetcusName() << endl;
	cout << "신용 등급 : " << accList[accNum]->Getlevel() << endl;
	cout << "계좌 번호 : " << accList[accNum]->GetaccID() << endl;
	cout << "현재 잔액 : " << accList[accNum]->Getbalance() << "원" << endl;
	accNum++;
}

//입금
template <typename T>
void AccountHandler<T>::DepositMoney(void)
{
	system("cls");

	cout << "입금을 시작합니다." << endl;
	
	int tmpAcc;
	int DepMoney;

	while (1)
	{
		cout << "입금할 계좌 번호 입력(메뉴로 돌아가려면 -1 입력) : ";
		cin >> tmpAcc;

		if (tmpAcc != -1)
		{
			for (int i = 0; i < accNum; i++)
			{
				if (tmpAcc == accList[i]->GetaccID())
				{
					cout << endl << "입금할 금액 : ";
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

						cout << endl << "입금 후 잔액 : " << accList[i]->Getbalance() << "원" << endl;
						getchar();
						getchar();
						return;
					}
				}
			}
			cout << endl << "일치하는 계좌번호가 없습니다." << endl << endl;
		}
		else return;
	}
}

//출금
template <typename T>
void AccountHandler<T>::WithdrawMoney(void)
{
	system("cls");

	cout << "출금을 시작합니다." << endl;

	int tmpAcc;
	int Money;

	while (1)
	{
		cout << "출금할 계좌 번호(메뉴로 돌아가려면 -1 입력) : ";
		cin >> tmpAcc;

		if (tmpAcc != -1)
		{
			for (int i = 0; i < accNum; i++)
			{
				if (tmpAcc == accList[i]->GetaccID())
				{
					cout << endl << "출금할 금액 : ";
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

						cout << endl << "출금 후 잔액 : " << accList[i]->Getbalance() << "원" << endl;
						getchar();
						getchar();
						return;
					}
				}
			}
			cout << endl << "일치하는 계좌번호가 없습니다." << endl;
			return;
		}
		else return;
	}
}

//잔액조회
template <typename T>
void AccountHandler<T>::ShowAllAccInfo(void)
{
	system("cls");

	for (int i = 0; i < accNum; i++)
	{
		if (accList[i]->Getlevel() == 'N')
		{
			cout << endl << "---------------------------------" << endl;
			cout << "계좌 번호 : " << accList[i]->GetaccID() << endl;
			cout << "고객 이름 : " << accList[i]->GetcusName()<< endl;
			cout << "계좌 잔액 : " << accList[i]->Getbalance() << "원" << endl;
			cout << "---------------------------------" << endl;
		}
		else
		{
			cout << endl << "---------------------------------" << endl;
			cout << "계좌 번호 : " << accList[i]->GetaccID() << endl;
			cout << "고객 이름 : " << accList[i]->GetcusName() << endl;
			cout << "신용 등급 : " << accList[i]->Getlevel() << endl;
			cout << "계좌 잔액 : " << accList[i]->Getbalance() << "원" << endl;
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
		cout << "파일이 열리지 않았습니다." << endl;
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
		cout << accList[i]->GetcusName() << "소멸" << endl;
		delete accList[i];
	}
}