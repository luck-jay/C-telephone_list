#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>
#include "cover.h"
#include "pass.h"
#include "Sys.h"

int main()
{ 
	FILE*fp=NULL;
	static char name[Acc];
	
	system("color f3");
 
	if(!(fp=fopen("account.txt","at")))//判断文件是否成功打开 
	{
		printf("程序异常！");
		exit(0); 
	}
	
	while(1)
	{	
		system("cls"); 
		cover_pass();//输出首页
		
		switch(getch())
		{
			case '1':{
				PaWd*head=NULL,*p=NULL;
				PaWd Head;
				
				head=Read_pass();//读取用户信息 
				p=head->Next;
	
				system("cls");
				cover_password();
	
				printf("\t\t\t请输入用户名：");
 				fflush(stdin);
 				gets(Head.Account);
 	
 				while(p)//判断用户是否存在 
 				{
				 	if(!strcmp(p->Account,Head.Account))
	 					break;
			
 					p=p->Next;
				}
 			
 				if(!p)
				{
					printf("\n\t\t\t该用户没有注册！");
					getch();
					release_PaWd(head);
					break;
				}
				
				strcpy(name,Head.Account);
				
				if(login(p))//登录
				{
					release_PaWd(head);//释放空间 
					system("color e3");
					_main_(name);
				}
				 
				}break;
				
			case '2':
				system("cls");
				Register();//注册
				break;
				
			case '3':Change_password();//修改密码 
				break;
			
			case '0':
				exit(0);//退出 
				break;
		}
		Sleep(20);
	} 
	
	return 0;
}

/*------------------------------------------------------------------------------
时间：2019年3月1日
作者：彭运杰
*/
