/*
1. 시스템명 : BankingSystem
2. 버전     : 7.0
3. 담당자   : 이태희
4. 내용
	4.1 OOP(객체지향) 단계별 프로젝트의 기본틀 구성
	4.2 클래스 적용(생성자, 소멸자, 복사생성자 적용)
	4.3 컨트롤, 엔터티 클래스
	4.4 파일 분할
	4.5 배열클래스, String 클래스 적용
	4.6 예외처리, 파일입출력 적용
	4.7 템플릿 적용
*/

#include "Ver07-AccountHandler.cpp"

void ShowMenu(void);

int main(void)
{
	AccountHandler<accPtr> * accHandler = new AccountHandler<accPtr>;

	accHandler->ReadFile();

	int choice;		//메뉴 선택

	while (1)
	{
		

		ShowMenu();

		cout << "선택 : ";
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
			cout << "없는 메뉴입니다. 다시 선택해주세요." << endl;
		}
	}

	return 0;
}

//메뉴출력
void ShowMenu(void)
{
	system("cls");

	cout << "====== Menu ======" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입    금" << endl;
	cout << "3. 출    금" << endl;
	cout << "4. 계좌조회" << endl;
	cout << "5. 종    료" << endl;
	cout << "==================" << endl;
}