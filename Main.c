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
 
	if(!(fp=fopen("account.txt","at")))//�ж��ļ��Ƿ�ɹ��� 
	{
		printf("�����쳣��");
		exit(0); 
	}
	
	while(1)
	{	
		system("cls"); 
		cover_pass();//�����ҳ
		
		switch(getch())
		{
			case '1':{
				PaWd*head=NULL,*p=NULL;
				PaWd Head;
				
				head=Read_pass();//��ȡ�û���Ϣ 
				p=head->Next;
	
				system("cls");
				cover_password();
	
				printf("\t\t\t�������û�����");
 				fflush(stdin);
 				gets(Head.Account);
 	
 				while(p)//�ж��û��Ƿ���� 
 				{
				 	if(!strcmp(p->Account,Head.Account))
	 					break;
			
 					p=p->Next;
				}
 			
 				if(!p)
				{
					printf("\n\t\t\t���û�û��ע�ᣡ");
					getch();
					release_PaWd(head);
					break;
				}
				
				strcpy(name,Head.Account);
				
				if(login(p))//��¼
				{
					release_PaWd(head);//�ͷſռ� 
					system("color e3");
					_main_(name);
				}
				 
				}break;
				
			case '2':
				system("cls");
				Register();//ע��
				break;
				
			case '3':Change_password();//�޸����� 
				break;
			
			case '0':
				exit(0);//�˳� 
				break;
		}
		Sleep(20);
	} 
	
	return 0;
}

/*------------------------------------------------------------------------------
ʱ�䣺2019��3��1��
���ߣ����˽�
*/
