#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#define ISBN_LEN 30
#define TITLE_LEN 30
#define RENT_LEN 100
//DVD �帣 ����
enum { ACTION = 1, COMIC, SF, ROMANTIC };

//�뿩 ���� ����
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
	int genre; //DVD �帣 ��� ����
	
	//�뿩���ɿ���(�뿩, �ݳ�)
	int rentState;
	
	//rentList�� ���� ��ġ����
	int numOfRentCus;
	
	//�뿩�̷�
	dvdrent rentList[RENT_LEN];
}dvdInfo;

#endif // !__DVDINFO_H__