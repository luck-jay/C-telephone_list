#ifndef SYS_H
#include <Windows.h>
#define Cip 16
#define Acc 10
typedef int COUNT;

/*�˻�*/ 
typedef struct PassWord{
	char Account[Acc];
	char cipher[Cip];
	struct PassWord*Next;
}PaWd;

extern void scan_number(char num[]);//Enter Number 

extern PaWd*Read_pass();//��¼�����ȡ�ļ�

extern void Write_pass(PaWd head);//��¼���汣���ļ� 

extern void _main_(char name[]);//���庯��

extern int scan_pawd(char pawd[]);//�ж������Ƿ���ȷ 

extern void scan_pass(char pass[]);//�������� 

extern void release_PaWd(PaWd*p);//�ͷ��û��������� 

extern COORD _where_();//�õ���굱ǰ����

extern void Gotoxy(int x,int y);//�ƶ����λ��

extern void scan_num(int num[],int err);//������ 

extern void enter();//����enetr 

#define SYS_H
#endif


