#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#define ISBN_LEN 30
#define TITLE_LEN 30
#define RENT_LEN 100
//DVD 장르 정보
enum { ACTION = 1, COMIC, SF, ROMANTIC };

//대여 상태 정보
enum {RENTED, RETURNED};

#define CUSID_LEN 10

typedef struct __dvdrent
{
	char cusID[CUSID_LEN];
	int Date;
	char ISBN[ISBN_LEN];
}dvdrent;

typedef struct __dvdInfo
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre; //DVD 장르 멤버 변수
	
	//대여가능여부(대여, 반납)
	int rentState;
	
	//rentList의 저장 위치정보
	int numOfRentCus;
	
	//대여이력
	dvdrent rentList[RENT_LEN];
}dvdInfo;

#endif // !__DVDINFO_H__