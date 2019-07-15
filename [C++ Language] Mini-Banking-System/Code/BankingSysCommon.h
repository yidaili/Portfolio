#ifndef _BANKINGSYSCOMMON_H_
#define _BANKINGSYSCOMMON_H_

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;


//메뉴용 열거자
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

//계좌 개설 열거자
enum { NORMAL = 1, CREDIT = 2 };

//신용등급 열거자
enum { A = 7, B = 4, C = 2 };

const int ACC_MAX_LEN = 100;
const int NAME_LEN = 20;

#endif // !_BANKINGSYSCOMMON_H_
