#ifndef SYS_H
#include <Windows.h>
#define Cip 16
#define Acc 10
typedef int COUNT;

/*账户*/ 
typedef struct PassWord{
	char Account[Acc];
	char cipher[Cip];
	struct PassWord*Next;
}PaWd;

extern void scan_number(char num[]);//Enter Number 

extern PaWd*Read_pass();//登录界面读取文件

extern void Write_pass(PaWd head);//登录界面保存文件 

extern void _main_(char name[]);//主体函数

extern int scan_pawd(char pawd[]);//判断密码是否正确 

extern void scan_pass(char pass[]);//输入密码 

extern void release_PaWd(PaWd*p);//释放用户密码链表 

extern COORD _where_();//得到光标当前坐标

extern void Gotoxy(int x,int y);//移动光标位置

extern void scan_num(int num[],int err);//输入编号 

extern void enter();//按下enetr 

#define SYS_H
#endif


