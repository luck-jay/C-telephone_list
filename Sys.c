#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include "Sys.h"
#include "Adbdy.h" 

/*Enter an integer*/
void scan_number(char num[])
{
	int count=0;//Number of records

	while(1)
	{
		num[count]=getch();

		if(num[count]>='0'&&num[count]<='9'&&count<11)//Determine if the input is a number
			printf("%c",num[count++]);
		else if(num[count]=='\b'&&count!=0)//Determine if the input is Backspace
		{
			printf("\b \b");
			num[count--]='\0';
		}	
		else if(num[count]=='\r')//Determine if the input is Enter
			break;
	}
	
	num[count]='\0'; 
}

/*�û�������Ϣ��ȡ*/ 
PaWd*Read_pass()
{
	FILE*pf=NULL;
	PaWd*head=NULL;//ͷָ�� 
	PaWd*p1=NULL,*p2=NULL;	
	
	head=p1=(PaWd*)malloc(sizeof(PaWd));//��������ͷ 
 	head->Next=NULL;
 	
 	if(!(pf=fopen("account.txt","r")))//�ж��ļ��Ƿ�� 
 	{
	 	printf("�ļ���ʧ�ܣ�");
	 	return head;
	}
	
	while(1)
	{
		if(feof(pf))
			break;
			
		p2=(PaWd*)malloc(sizeof(PaWd));
		p2->Next=NULL;
		
		fread(p2,sizeof(PaWd),1,pf);//����
		
		p1->Next=p2;
		p1=p2;	
	}
	
	fclose(pf);//�ر��ļ� 
	return head; 
}

/*�û���Ϣд��*/ 
void Write_pass(PaWd head)
{
	FILE*fp=NULL;
	PaWd*Head=&head; 
	
	if(!(fp=fopen("account.txt","at")))//�ж��ļ��Ƿ�ɹ��� 
	{
		printf("\t\t\tע��ʧ�ܣ�");
		return; 
	}
	
	fwrite(Head,sizeof(PaWd),1,fp);//������д���ļ� 
	
	fclose(fp);//�ر��ļ� 
} 

/*��ϵ�˶�ȡ*/
Cont*Read_account(char name_file[])
{
	FILE*pf=NULL;
	Cont*head=NULL,*p1=NULL,*p2=NULL;
	
	if(!(pf=fopen(name_file,"r")))//�ж��ļ��Ƿ�ɹ��� 
	{
		printf("\t\t\t�������");
		exit(0); 
	}
	
	head=p1=(Cont*)malloc(sizeof(Cont));//����ͷ�ڵ� 
	p1->next=NULL;
	
	while(1)
	{
		p2=(Cont*)malloc(sizeof(Cont));
		p2->next=NULL;
		
		fread(p2,sizeof(Cont),1,pf);//����һ������
		
		if(feof(pf))
		{
			free(p2);
			break;
		}
		
		p1->next=p2;
		p1=p2; 
	}
	
	fclose(pf);//�ر��ļ� 
	
	return head;
}

/*��������*/
void scan_pass(char pass[])
{
	int count=0;
	
	while(1)//�ַ����� 
	{
		pass[count]=getch();
		
		if(pass[count]>0&&pass[count]!='\b'&&pass[count]!='\r')	
		{	
			printf("%c",pass[count++]);
			
			Sleep(200);//�ȴ�200���� 
			
			printf("\b*");	
		}
		
		else if(pass[count]=='\b'&&count>0)
		{
			printf("\b \b");
			pass[count--]='\0';
		}
		
		else if(pass[count]=='\r')
			break;
	}
	
	pass[count]='\0';
} 

/*�ж������Ƿ���ȷ*/
int scan_pawd(char pawd[])
{
	char pass[Cip];
	
	scan_pass(pass);
	
	if(strcmp(pass,pawd))//�ж������Ƿ���ȷ 
		return 0;
	else
		return 1;
} 

/*ɾ��һ����ϵ��*/
Cont*Del(Cont*p,char cont_name[])
{
	Cont*temp=NULL,*head=p;

	if(!strcmp(p->next->name,cont_name))//���ǵ�һ���ڵ� 
	{
		temp=p->next->next;
		free(p->next);
		p->next=temp;
	}
	else
	{
		for(;strcmp(p->next->name,cont_name);p=p->next); //�ҵ�ǰ���ڵ� 
				
		if(p->next)
		{
			temp=p->next->next;
			free(p->next);
			p->next=temp;
		}
	}
	
	return head;
 } 
 
/*���������*/
void Derived(Cont*head,char name_file[])
{
	Cont*p=head->next;
	FILE*pf=NULL;
	int count=1;
	
	strcat(name_file,".csv");
	
	if(!(pf=fopen(name_file,"w+")))//��һ������ļ� 
	{
		printf("\t\t\t�����쳣!");
		return;
	}
	
	fprintf(pf,"%s,%s,%s,%s,%s,%s\n","���","����","�Ա�","�绰����","��ַ","��ע");
	
	while(p)
	{
		fprintf(pf,"%d,%s,%s,%s,%s,%s\n",count++,p->name,p->sexuality,p->number,p->address,p->remarks);
		
		p=p->next;
	 } 
	
	fclose(pf);
 } 

/*ɾ���������*/
void scan_temp_num(char temp[])
{
	int err=1,count=0;//err�ж��Ƿ�����ո� 
	
	while(1)
	{
		temp[count]=getch();//�õ��������� 
		
		if(temp[count]>='0'&&temp[count]<='9')
		{
			printf("%c",temp[count]);
			count++;
			err=1;
		}
		
		else if(temp[count]==' '&&err&&count>0)
		{
			printf(" ");
			err=0;
			count++;
		 }
		
		else if(temp[count]=='\r')
			break;
		
		else if(temp[count]=='\b'&&count>0)
		{
			count--;
			printf("\b \b");
			
			if(temp[count]==' ')//�ж��Ƿ�ɾ���ո� 
				err=1;
			else 
				err=0;
		}	
	}
	
	temp[count]='\0';//�����ַ�����β 
 } 
 
/*ɾ����Ż��*/
void scan_num(int num[],int err) 
{
	char temp[NT*2];
	int i,count=0;
	
	scan_temp_num(temp);//������ 
	
	for(i=0;temp[i]!='\0';i++)//�õ���� 
	{
		if(temp[i]>='0'&&temp[i]<='9')
			num[count]=num[count]*10+((int)temp[i]-48); 	
		
		if(temp[i+1]==' ')
			count++;
	}
}

/*�ͷ�����(�˺����룩*/
void release_PaWd(PaWd*p)
{
	PaWd*p1=p;
	
	while(p1)
	{
		p1=p->Next;
		free(p);
		p=p1;
	 }
 } 
 
/*�ͷ�����(ͨѶ¼��*/
void release_Cont(Cont*p)
{
	Cont*p1=p;
	
	while(p1)
	{
		p1=p->next;
		free(p);
		p=p1;
	 } 
 } 
 
 /*�õ����λ��*/
COORD _where_()
{
	COORD cursor;//���ڴ���������Ϣ 
	CONSOLE_SCREEN_BUFFER_INFO csbi; //����̨��Ļ��������Ϣ
	
  	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);//�õ����λ��
	   
  	cursor.X=csbi.dwCursorPosition.X;
  	cursor.Y=csbi.dwCursorPosition.Y;
    
    return cursor;
 } 
 
/*�ƶ����*/ 
void Gotoxy(int x,int y)
{
    HANDLE handle; //����������handle
    COORD coord; //����ṹ��coord (����ϵcoord)
    
    coord.X = x; //������x
    coord.Y = y; //������y
    
    handle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ����̨������(ֵΪ-11)
    SetConsoleCursorPosition(handle, coord); //�ƶ����
}
