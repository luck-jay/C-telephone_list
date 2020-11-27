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

/*用户密码信息读取*/ 
PaWd*Read_pass()
{
	FILE*pf=NULL;
	PaWd*head=NULL;//头指针 
	PaWd*p1=NULL,*p2=NULL;	
	
	head=p1=(PaWd*)malloc(sizeof(PaWd));//建立链表头 
 	head->Next=NULL;
 	
 	if(!(pf=fopen("account.txt","r")))//判断文件是否打开 
 	{
	 	printf("文件打开失败！");
	 	return head;
	}
	
	while(1)
	{
		if(feof(pf))
			break;
			
		p2=(PaWd*)malloc(sizeof(PaWd));
		p2->Next=NULL;
		
		fread(p2,sizeof(PaWd),1,pf);//读入
		
		p1->Next=p2;
		p1=p2;	
	}
	
	fclose(pf);//关闭文件 
	return head; 
}

/*用户信息写入*/ 
void Write_pass(PaWd head)
{
	FILE*fp=NULL;
	PaWd*Head=&head; 
	
	if(!(fp=fopen("account.txt","at")))//判断文件是否成功打开 
	{
		printf("\t\t\t注册失败！");
		return; 
	}
	
	fwrite(Head,sizeof(PaWd),1,fp);//把数据写入文件 
	
	fclose(fp);//关闭文件 
} 

/*联系人读取*/
Cont*Read_account(char name_file[])
{
	FILE*pf=NULL;
	Cont*head=NULL,*p1=NULL,*p2=NULL;
	
	if(!(pf=fopen(name_file,"r")))//判断文件是否成功打开 
	{
		printf("\t\t\t程序出错！");
		exit(0); 
	}
	
	head=p1=(Cont*)malloc(sizeof(Cont));//建立头节点 
	p1->next=NULL;
	
	while(1)
	{
		p2=(Cont*)malloc(sizeof(Cont));
		p2->next=NULL;
		
		fread(p2,sizeof(Cont),1,pf);//读出一个数据
		
		if(feof(pf))
		{
			free(p2);
			break;
		}
		
		p1->next=p2;
		p1=p2; 
	}
	
	fclose(pf);//关闭文件 
	
	return head;
}

/*密码输入*/
void scan_pass(char pass[])
{
	int count=0;
	
	while(1)//字符输入 
	{
		pass[count]=getch();
		
		if(pass[count]>0&&pass[count]!='\b'&&pass[count]!='\r')	
		{	
			printf("%c",pass[count++]);
			
			Sleep(200);//等待200毫秒 
			
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

/*判断密码是否正确*/
int scan_pawd(char pawd[])
{
	char pass[Cip];
	
	scan_pass(pass);
	
	if(strcmp(pass,pawd))//判断密码是否正确 
		return 0;
	else
		return 1;
} 

/*删除一个联系人*/
Cont*Del(Cont*p,char cont_name[])
{
	Cont*temp=NULL,*head=p;

	if(!strcmp(p->next->name,cont_name))//若是第一个节点 
	{
		temp=p->next->next;
		free(p->next);
		p->next=temp;
	}
	else
	{
		for(;strcmp(p->next->name,cont_name);p=p->next); //找到前驱节点 
				
		if(p->next)
		{
			temp=p->next->next;
			free(p->next);
			p->next=temp;
		}
	}
	
	return head;
 } 
 
/*导出到表格*/
void Derived(Cont*head,char name_file[])
{
	Cont*p=head->next;
	FILE*pf=NULL;
	int count=1;
	
	strcat(name_file,".csv");
	
	if(!(pf=fopen(name_file,"w+")))//打开一个表格文件 
	{
		printf("\t\t\t程序异常!");
		return;
	}
	
	fprintf(pf,"%s,%s,%s,%s,%s,%s\n","编号","姓名","性别","电话号码","地址","备注");
	
	while(p)
	{
		fprintf(pf,"%d,%s,%s,%s,%s,%s\n",count++,p->name,p->sexuality,p->number,p->address,p->remarks);
		
		p=p->next;
	 } 
	
	fclose(pf);
 } 

/*删除编号输入*/
void scan_temp_num(char temp[])
{
	int err=1,count=0;//err判断是否输入空格 
	
	while(1)
	{
		temp[count]=getch();//得到键盘输入 
		
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
			
			if(temp[count]==' ')//判断是否删除空格 
				err=1;
			else 
				err=0;
		}	
	}
	
	temp[count]='\0';//设置字符串结尾 
 } 
 
/*删除编号获得*/
void scan_num(int num[],int err) 
{
	char temp[NT*2];
	int i,count=0;
	
	scan_temp_num(temp);//输入编号 
	
	for(i=0;temp[i]!='\0';i++)//得到编号 
	{
		if(temp[i]>='0'&&temp[i]<='9')
			num[count]=num[count]*10+((int)temp[i]-48); 	
		
		if(temp[i+1]==' ')
			count++;
	}
}

/*释放链表(账号密码）*/
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
 
/*释放链表(通讯录）*/
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
 
 /*得到光标位置*/
COORD _where_()
{
	COORD cursor;//用于储存坐标信息 
	CONSOLE_SCREEN_BUFFER_INFO csbi; //控制台屏幕缓冲区信息
	
  	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);//得到光标位置
	   
  	cursor.X=csbi.dwCursorPosition.X;
  	cursor.Y=csbi.dwCursorPosition.Y;
    
    return cursor;
 } 
 
/*移动光标*/ 
void Gotoxy(int x,int y)
{
    HANDLE handle; //定义句柄变量handle
    COORD coord; //定义结构体coord (坐标系coord)
    
    coord.X = x; //横坐标x
    coord.Y = y; //纵坐标y
    
    handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台输出句柄(值为-11)
    SetConsoleCursorPosition(handle, coord); //移动光标
}
