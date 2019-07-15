/*
	기능	: 고객 정보 저장 및 참조 함수들의 선언.
	작성자	: LTH
	작성일	:2019-03-11
	Ver		: 1.0
*/


#ifndef __CUSINFOACCESS_H__
#define __CUSINFOACCESS_H__

#include "cusInfo.h"

/*
	기능 : cusInfo 할당 및 저장
	반환 : 성공시 등록된 정보의 개수,
		   실패시 0을 반환.
*/
int AddCusInfo(char * ID, char * name, char * num);

/*
	기능 : 해당 고객 ID의 정보를 가지고 있는 포인터를 반환
	반환 : 등록 안된 ID의 경우 NULL 포인터 반환.
*/
cusInfo * GetCusPtrByID(char * ID);

/*
	기능 : 가입된 ID인지 체크
	반환 : 가입되었으면 1, 아니면 0을 반환.
*/
int IsregistID(char * ID);

#endif // !__CUSINFOACCESS_H__