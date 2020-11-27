#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "Sys.h"
#include "cover.h"

/*注册*/
void Register()
{
	PaWd user;
	PaWd head;
	PaWd*Head=NULL,*p=NULL,*p1=NULL;
	char temp_pass[Acc];
	
	Head=Read_pass();//读出用户信息 
	p1=p=Head->Next; 
	
	do
	{
		system("cls");
		cover_register(); 
		
		printf("\t\t\t请输入新的用户名:");
	
		fflush(stdin);
		gets(head.Account);//输入用户名 
		p=p1;//回到头节点 
		while(p)
		{
			if(!strcmp(p->Account,head.Account)) 
			{
				printf("\n\t\t\t该用户名已有人注册！退出按Esc\n");
				
				if(getch()==27)
					return;
				break;
			}
		
			p=p->Next;
		}
	}while(p);
	
	release_PaWd(Head);
	
	printf("\t\t\t请输入密码:");
	scan_pass(head.cipher);
	strcpy(temp_pass,head.cipher);
	
	printf("\n\t\t\t请确认密码:");
	scan_pass(head.cipher);
	
	if(!strcmp(head.cipher,temp_pass))//判断输入的密码是否相同 
		Write_pass(head);
	else
	{ 
		printf("\n\t\t\t输入的密码不一致！");
		getch(); 
		return;
 	}
	  
 	printf("\n\t\t\t注册成功！\n\n\t\t\t按任意键继续");
 	
 	getch();
}

/*登录*/
int login(PaWd*p) 
{
	int count=0;
	int juge=2;
	
 	printf("\t\t\t请输入密码:");
 	
 	while(1)
 	{
 		juge=scan_pawd(p->cipher);
 	 
 		if(juge==1)//判断密码是否正确 
 			return 1;	
 			
		else if(juge==0&&count<2)
		{
			printf("\n\t\t\t你输入的密码有误！请重新输入:");
			count++;
		}
		else
			break;
 	}
 	
 	printf("\n\t\t\t你已经尝试了3次，如忘记密码请仔细思考后再试！");
 	getch(); 
 	return 0;
}

/*修改密码*/
void Change_password()
{
	PaWd*head=NULL,*p1=NULL,*p2=NULL;
	PaWd Head;
	FILE*pf=NULL;
	
	head=Read_pass();//读取用户信息 
	p2=p1=head->Next;
	
	system("cls");
	
	printf("\t\t\t请输入用户名：");
 	fflush(stdin);
 	gets(Head.Account);
 	
 	while(p1)//判断用户是否存在 
 	{
	 	if(!strcmp(p1->Account,Head.Account))
	 		break;
	 		
 		p1=p1->Next;
 	}
 	
 	if(!p1)
	{
		printf("\n\t\t\t该用户没有注册！");
		getch();
		release_PaWd(head); 
		return;
	}
	
 	printf("\t\t\t请输入密码:");
 		
	if(!scan_pawd(p1->cipher))//判断密码是否正确 
	{
		printf("\n\t\t\t你输入的密码不正确！");
		getch(); 
		return;
	}
	
	printf("\n\t\t\t请输入新密码：");
	fflush(stdin);
	gets(p1->cipher); 
	
	if(!(pf=fopen("account.txt","w")))//判断文件是否成功打开 
	{
		printf("程序出错！");
		return;
	}
	
	while(p2)//写入文件 
	{
		fwrite(p2,sizeof(PaWd),1,pf);
		p2=p2->Next;
	}
	
	fclose(pf);//关闭文件 
} 
