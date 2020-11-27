#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "Sys.h"
#include "cover.h"

/*ע��*/
void Register()
{
	PaWd user;
	PaWd head;
	PaWd*Head=NULL,*p=NULL,*p1=NULL;
	char temp_pass[Acc];
	
	Head=Read_pass();//�����û���Ϣ 
	p1=p=Head->Next; 
	
	do
	{
		system("cls");
		cover_register(); 
		
		printf("\t\t\t�������µ��û���:");
	
		fflush(stdin);
		gets(head.Account);//�����û��� 
		p=p1;//�ص�ͷ�ڵ� 
		while(p)
		{
			if(!strcmp(p->Account,head.Account)) 
			{
				printf("\n\t\t\t���û���������ע�ᣡ�˳���Esc\n");
				
				if(getch()==27)
					return;
				break;
			}
		
			p=p->Next;
		}
	}while(p);
	
	release_PaWd(Head);
	
	printf("\t\t\t����������:");
	scan_pass(head.cipher);
	strcpy(temp_pass,head.cipher);
	
	printf("\n\t\t\t��ȷ������:");
	scan_pass(head.cipher);
	
	if(!strcmp(head.cipher,temp_pass))//�ж�����������Ƿ���ͬ 
		Write_pass(head);
	else
	{ 
		printf("\n\t\t\t��������벻һ�£�");
		getch(); 
		return;
 	}
	  
 	printf("\n\t\t\tע��ɹ���\n\n\t\t\t�����������");
 	
 	getch();
}

/*��¼*/
int login(PaWd*p) 
{
	int count=0;
	int juge=2;
	
 	printf("\t\t\t����������:");
 	
 	while(1)
 	{
 		juge=scan_pawd(p->cipher);
 	 
 		if(juge==1)//�ж������Ƿ���ȷ 
 			return 1;	
 			
		else if(juge==0&&count<2)
		{
			printf("\n\t\t\t�������������������������:");
			count++;
		}
		else
			break;
 	}
 	
 	printf("\n\t\t\t���Ѿ�������3�Σ���������������ϸ˼�������ԣ�");
 	getch(); 
 	return 0;
}

/*�޸�����*/
void Change_password()
{
	PaWd*head=NULL,*p1=NULL,*p2=NULL;
	PaWd Head;
	FILE*pf=NULL;
	
	head=Read_pass();//��ȡ�û���Ϣ 
	p2=p1=head->Next;
	
	system("cls");
	
	printf("\t\t\t�������û�����");
 	fflush(stdin);
 	gets(Head.Account);
 	
 	while(p1)//�ж��û��Ƿ���� 
 	{
	 	if(!strcmp(p1->Account,Head.Account))
	 		break;
	 		
 		p1=p1->Next;
 	}
 	
 	if(!p1)
	{
		printf("\n\t\t\t���û�û��ע�ᣡ");
		getch();
		release_PaWd(head); 
		return;
	}
	
 	printf("\t\t\t����������:");
 		
	if(!scan_pawd(p1->cipher))//�ж������Ƿ���ȷ 
	{
		printf("\n\t\t\t����������벻��ȷ��");
		getch(); 
		return;
	}
	
	printf("\n\t\t\t�����������룺");
	fflush(stdin);
	gets(p1->cipher); 
	
	if(!(pf=fopen("account.txt","w")))//�ж��ļ��Ƿ�ɹ��� 
	{
		printf("�������");
		return;
	}
	
	while(p2)//д���ļ� 
	{
		fwrite(p2,sizeof(PaWd),1,pf);
		p2=p2->Next;
	}
	
	fclose(pf);//�ر��ļ� 
} 
