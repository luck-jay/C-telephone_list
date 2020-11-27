#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "Adbdy.h" 
#include "Sys.h"
#include "cover.h"

/*输出到屏幕*/
int out(Cont*p)
{
	int count=0,temp; 
	
	if(!p)
	{
		printf("\n\t\t\t没有联系人信息！");
		return count;
	}
	
	printf("\n   姓名\t\t\b\b\b性别     电话号码\t\t家庭住址\t\t\t\t备注");
	
	while(p)//输出 
	{		
		Gotoxy(0,_where_().Y+2);
		printf("%d. ",count+1);

		temp=_where_().X;//得到x坐标 

		Gotoxy(temp,_where_().Y);
		printf("%s",p->name);

		Gotoxy(temp+11,_where_().Y);
		printf("%s",p->sexuality);
	
		Gotoxy(temp+19,_where_().Y);
		printf("%s",p->number);
		
		Gotoxy(temp+37,_where_().Y);
		printf("%s",p->address);
		
		Gotoxy(temp+77,_where_().Y);
		printf("%s",p->remarks);

		count++;
		p=p->next;
	} 

	return count; 
} 

/*查找联系人*/
Cont*seek(Cont*p)
{
	int i,j;
	COUNT count=0;//printf("……");while(1);
	char temp[Addre];
	char cont_name[Na],temp_name[Na];
	char temp_number[NL];
	Cont*p1=NULL,*p2=NULL,*head=NULL;
	
	p1=head=(Cont*)malloc(sizeof(Cont));
	head->next=NULL;
	
	printf("\t\t==================================\n");
	printf("\t\t\t1.按姓名查找\n");
	printf("\t\t\t2.按号码查找\n");
	printf("\n\t\t\t退回主页面请按Esc\n"); 
	printf("\t\t==================================\n");
	
	while(1)
	{	
		switch(getch())
		{
			case '1':
				printf("\t\t\t请输入要查找的联系人姓名或关键字：");
				fflush(stdin);
				gets(temp_name);
				
				while(p)//查找联系人 
				{	
					if(strstr(p->name,temp_name))
					{
						p2=(Cont*)malloc(sizeof(Cont));
						p2->next=NULL;
						
						strcpy(p2->name,p->name);
						strcpy(p2->sexuality,p->sexuality);
						strcpy(p2->number,p->number);
						strcpy(p2->address,p->address);
						strcpy(p2->remarks,p->remarks); 
						
						p1->next=p2;
						p1=p2;	
					}
			
					p=p->next;
				}
		
			return head;
			break;
	
			case '2':
				printf("\t\t\t请输入要查找的电话号码：");
				scan_number(temp_number);
			
				while(p)//查找联系人 
				{	
					if(strstr(p->number,temp_number))
					{
						p2=(Cont*)malloc(sizeof(Cont));
						p2->next=NULL;
				
						strcpy(p2->name,p->name);
						strcpy(p2->sexuality,p->sexuality);
						strcpy(p2->number,p->number);
						strcpy(p2->address,p->address);
						strcpy(p2->remarks,p->remarks); 
						
						p1->next=p2;
						p1=p2;
					}
			
					p=p->next;
				}
		
			return head;
				break;
			
			case 27:
				return head;
				break;
		}
	}
}

/*判断首字母函数*/
char head_letter(char lett[])
{
	int temp;
	
	temp=(unsigned char)lett[0]*256+(unsigned char)lett[1];

	if(temp>=45217&&temp<=45252)//判断首字母 
		return 'a';
		
	else if(temp>=45253&&temp<=45760)
		return 'b';
		
	else if(temp>=45761&&temp<=46317)
		return 'c';
		
	else if(temp>=46318&&temp<=46825)
		return 'd';
		
	else if(temp>=46826&&temp<=47009)
		return 'e';
		
	else if(temp>=47010&&temp<=47296)
		return 'f';
		
	else if(temp>=47297&&temp<=47613)
		return 'g';
		
	else if(temp>=47614&&temp<=48118)
		return 'h';
		
	else if(temp>=48119&&temp<=49061)
		return 'j';
		
	else if(temp>=49062&&temp<=49323)
		return 'k';
		
	else if(temp>=49324&&temp<=49895)
		return 'l';
		
	else if(temp>=49896&&temp<=50370)
		return 'm';
		
	else if(temp>=50371&&temp<=50613)
		return 'n';
		
	else if(temp>=50614&&temp<=50621)
		return 'o';
		
	else if(temp>=50622&&temp<=50905)
		return 'p';
		
	else if(temp>=50906&&temp<=51386)
		return 'q';
		
	else if(temp>=51387&&temp<=51445)
		return 'r';
		
	else if(temp>=51446&&temp<=52217)
		return 's';
		
	else if(temp>=52218&&temp<=52697)
		return 't';
		
	else if(temp>=52698&&temp<=52979)
		return 'w';
		
	else if(temp>=52980&&temp<=53640)
		return 'x';
		
	else if(temp>=53689&&temp<=54480)
		return 'y';
		
	else if(temp>=54481&&temp<=55298)
		return 'z';
		
	else
		return ' '; 
 } 

/*判断字母*/
void sort_lett(int temp_num[],char ch)
{
	switch(ch) 
	{
		case 'A': 
		case 'a': temp_num[0]++; break;
		case 'B':
		case 'b': temp_num[1]++; break;
		case 'C':
		case 'c': temp_num[2]++; break;
		case 'D':
		case 'd': temp_num[3]++; break;
		case 'E':
		case 'e': temp_num[4]++; break;
		case 'F':
		case 'f': temp_num[5]++; break;
		case 'G':
		case 'g': temp_num[6]++; break;
		case 'H':
		case 'h': temp_num[7]++; break;
		case 'I':
		case 'i': temp_num[8]++; break;
		case 'J':
		case 'j': temp_num[9]++; break;
		case 'K':
		case 'k': temp_num[10]++; break;
		case 'L':
		case 'l': temp_num[11]++; break;
		case 'M':
		case 'm': temp_num[12]++; break;
		case 'N':
		case 'n': temp_num[13]++; break;
		case 'O':
		case 'o': temp_num[14]++; break;
		case 'P':
		case 'p': temp_num[15]++; break;
		case 'Q':
		case 'q': temp_num[16]++; break;
		case 'R':
		case 'r': temp_num[17]++; break;
		case 'S':
		case 's': temp_num[18]++; break;
		case 'T':
		case 't': temp_num[19]++; break;
		case 'U':
		case 'u': temp_num[20]++; break;
		case 'V':
		case 'v': temp_num[21]++; break;
		case 'W':
		case 'w': temp_num[22]++; break;
		case 'X':
		case 'x': temp_num[23]++; break;
		case 'Y':
		case 'y': temp_num[24]++; break;
		case 'Z':
		case 'z': temp_num[25]++; break;
		default: temp_num[26]++; break;
	}
 } 

Cont*sort_list(Cont*head)
{
	Cont*p1=head->next,*p2=head,*p3=NULL,*temp=NULL,*tep=NULL,*Next;
	
    
	if(!p1||!p1->next)//判断链表是否只有一个元素或者是空链表 
		return head;

    while(p2->next)//冒泡排序 
    {
        for(p3 = head, tep = p3 -> next, Next = tep -> next; Next; p3 = p3 -> next, tep = tep -> next, Next = Next -> next)
        {
            
            if(!strcmp(tep->name,Next->name))//交换节点 
            {
                tep -> next = Next -> next;
                p3 -> next = Next;
                Next -> next =tep;
                temp = Next;
                Next = tep;
                tep = temp;
            }
        }
        
        p2=p2->next; 
    }
	
	return head; 
}

/*排序*/
void sort(Cont*head)
{
	COORD tep;
	Cont*p=head->next,*p1=p;
	char temp_lett;
	int temp_num[27]={0},count[27]={0};
	int i,j; 
	int temp;

	head=sort_list(head);
	
	while(p1)//得到各元素个数 
	{
		if(p1->name[0]<0)
			sort_lett(temp_num,head_letter(p1->name));
		else
			sort_lett(temp_num,p1->name[0]);
		
		p1=p1->next;
	}
	
	system("cls");
	printf("\n   姓名\t\t\b\b\b性别     电话号码\t\t家庭住址\t\t\t\t备注\n");
	
	for(i=0;i<27;i++)//输出框架 
	{
		if(temp_num[i])
		{	
			if(i<26)
			{
				printf("%c-------------------------------------------------------------------\n",65+i);
				count[i]=_where_().Y;//得到输出起始位置 
			}
				
			else
			{
				printf("#-------------------------------------------------------------------\n");
				count[26]=_where_().Y;//得到输出起始位置 
				break;
			}
			
			for(j=0;j<temp_num[i];j++)//得到输出范围的大小 
				printf("\n");	
		}
	}
	
	while(p)//输出联系人 
	{
		for(i=0;i<27;i++)//重置数组 
			temp_num[i]=0;
		
		if(p->name[0]<0)
		{
			sort_lett(temp_num,head_letter(p->name));//得到首字母 
			
			for(i=0;i<27;i++)//查找首字母 
				if(temp_num[i])
					break;
			
			Gotoxy(3,count[i]);//显示 
			printf("%s",p->name);
			
			Gotoxy(14,count[i]);
			printf("%s",p->sexuality);
			
			Gotoxy(22,count[i]);
			printf("%s",p->number);
			
			Gotoxy(40,count[i]);
			printf("%s",p->address);
			
			Gotoxy(80,count[i]);
			printf("%s",p->remarks);
			
			count[i]++;
		 } 
			
		else
		{
			sort_lett(temp_num,p->name[0]);//得到首字母 
		
			for(i=0;i<27;i++)//查找首字母 
				if(temp_num[i])
					break;
			
			Gotoxy(3,count[i]);//显示 
			printf("%s",p->name);
			
			Gotoxy(14,count[i]);
			printf("%s",p->sexuality);
			
			Gotoxy(22,count[i]);
			printf("%s",p->number);
			
			Gotoxy(40,count[i]);
			printf("%s",p->address);
			
			Gotoxy(80,count[i]);
			printf("%s",p->remarks);
			
			count[i]++;
		}
		
		p=p->next;
	}
 } 
	
/*显示联系人*/
void Input(Cont*head,char name_file[])
{
	Cont*p=head->next,*p1=p,*p2=NULL;
	char name[Na];
	int number[26]={0};//记录数据个数 
	 
	system("cls");
	
 	if(!p)
	{
		printf("你并没有保存过联系人！");
		getch();
		return;
	}
	
	while(1)
	{
		system("cls");
		cover_seek();
		
		out(p);
			
		switch(getch())
		{
			case '1':
				 sort(head);
				 getch();
				break;
			case '2':
				p2=seek(p1);
				out(p2->next);
				release_Cont(p2);
				getch();
				break;
			case 27:return;
				break;
		}
	}	
} 
 
/*添加联系人*/ 
Cont*Add(Cont*head)
{
	Cont*p1=head->next,*p2=p1;
	Cont*temp=NULL; 
	
	while(1)
	{
		temp=(Cont*)malloc(sizeof(Cont));
		
		while(1)
		{
			system("cls");
			p1=p2; 
			printf("\t\t\t请输入需要添加的联系人姓名:");
			gets(temp->name);
		
			while(p1)//判断联系人是否存在 
			{
				if(!strcmp(p1->name,temp->name))
				{
					printf("\t\t\t该联系人已经保存过！");
					break;
				}
			
				p1=p1->next;
			}
		
			if(!p1)//判断是否有这个联系人 
				break;
			
			printf("\n\n\t\t\t如需回到主菜单请按Esc！如需继续输入请按任意键！");
		
			if(getch()==27)//判断是否按下Esc 
			{
				free(temp);
				return head;
			}
				
		}
		
		printf("\n\t\t\t请输入%s的性别:",temp->name);
		fflush(stdin);
		gets(temp->sexuality);
		
	
		printf("\t\t\t请输入%s的电话号码:",temp->name);
		scan_number(temp->number);
	
		printf("\n\t\t\t请输入%s的家庭住址:",temp->name);
		fflush(stdin);
		gets(temp->address);
		
		printf("\n\t\t\t请输入%s的备注:",temp->name);
		fflush(stdin);
		gets(temp->remarks);
		
		head->next=temp;
		temp->next=p2;
		p2=temp;
		 
		printf("\n\n\t\t\t如需退出请按Esc.按任意键继续录入.");
		if(getch()==27)
			break;
	} 
	
	return head; 
} 

/*删除联系人*/
Cont*Delete(Cont*head)
{ 
	int count[NT],temp_count,err,temp,Count[NT];
	int i,j;
	char cont_name[Na][NT];
	Cont*p=head->next,*p1=NULL,*p2=NULL;
	
	system("cls");
	
	if(!p)
	{
		printf("你并没有保存过联系人！");
		getch();
		return head;
	}
	
	while(1)
	{
		if(!(p1=seek(p)))
			return head;
		
		if(!p1->next)//判断是否为空 
		{ 
			printf("\n\t\t\t没有查找到相关联系人！"); 
			printf("\n\t\t\t如需返回主页请按Esc,继续查找请按Enter.");
			err=1;
			while(err)
			{
				switch(getch()) 
				{
					case 27:
						free(p1);
						return head;
						break;
					case '\r':
						err=0;
						break;
				}	
			}	
		} 
		else
			break;
	 } 

	system("cls");

	while(1)
	{
		while(1)
		{
			system("cls");
			if(!out(p1->next))//判断是否有联系人 
				goto come;//跳出多重循环 

			printf("\n\t\t\t如需返回主页请按Esc,按任意键继续…");
			if(getch()==27)
				goto come;
			
			system("cls");
			err=out(p1->next);
			
			printf("\n\t\t\t请输入你需要删除的数据编号:");
			
			for(i=0;Count[i];i++)//数组归零 
				Count[i]=0;
			
			scan_num(Count,err);//得到删除编号 
			
			for(i=0;Count[i];i++)//数组查重
				for(j=i+1;Count[j];j++)
					if(Count[i]==Count[j])
						Count[i]=-1;
			
			system("cls");
			
			for(i=0;Count[i];i++)
			{
				temp_count=Count[i];
				count[i]=1;
				p2=p1->next;
				
				while(p2)
				{
					if(count[i]==temp_count)
					{
						strcpy(cont_name[i],p2->name);
			
						Gotoxy(0,_where_().Y+2);
						printf("%d. ",count[i]);
			
						temp=_where_().X;//得到x坐标 
			
						Gotoxy(temp,_where_().Y);
						printf("%s",p->name);

						Gotoxy(temp+11,_where_().Y);
						printf("%s",p->sexuality);
	
						Gotoxy(temp+19,_where_().Y);
						printf("%s",p->number);
		
						Gotoxy(temp+37,_where_().Y);
						printf("%s",p->address);
		
						Gotoxy(temp+77,_where_().Y);
						printf("%s",p->remarks);
 
						break;
					} 
					
					count[i]++; 
					p2=p2->next;
				}	
			} 
			
		
		printf("\n\t\t\t确认删除按Enter.");
		if(getch()=='\r')
			break;
		}
		
		for(i=0;Count[i];i++)
		{
			temp_count=Count[i];
			
			if(count[i]==temp_count)//删除选中的一项 
			{
				p1=Del(p1,cont_name[i]);//删除一个节点 
				head=Del(head,cont_name[i]);
			}
		}
		
		printf("\n\t\t\t删除成功！");
		printf("\n\n\t\t\t如需退出请按Esc.按任意键继续删除.");
		if(getch()==27)
			break;
	}
	
	come:release_Cont(p1);
	
	return head;
}

/*修改联系人信息*/
Cont*Modify(Cont*head)
{
	Cont*p=head->next,*p1=p;
	char temp_name[Na],temp_num[NL];
	
	system("cls");
	
	if(!p)
	{
		printf("你并没有保存过联系人！");
		getch();
		return head;
	}
	
	while(1)
	{
		system("cls");
		
		printf("\t\t==================================\n");
		printf("\t\t\t1.按姓名查找\n");
		printf("\t\t\t2.按号码查找\n");
		printf("\n\t\t\t退回主页面请按Esc\n"); 
		printf("\t\t==================================\n");
	

		switch(getch())
		{
			case '1':
				printf("\t\t\t请输入要查找的姓名:");
				fflush(stdin);
				gets(temp_name);
				
				p=p1;//回到头节点 
				while(p)//查找联系人 
				{
					if(!strcmp(temp_name,p->name))
						break;
					
					p=p->next;
				}
				
				if(!p)
				{
					printf("\t\t\t没有找到这个联系人！");
					getch();
				}
				
				else
				{
					while(1)
		 			{
		 				system("cls");
						printf("\t\t==================================\n");
						printf("\t\t\t1.修改姓名.\n");
						printf("\t\t\t2.修改姓别.\n");
						printf("\t\t\t3.修改号码.\n");
						printf("\t\t\t4.修改家庭住址.\n");
						printf("\t\t\t5.修改备注.\n");
						printf("\n\t\t\t退回上一层请按Esc\n"); 
			 			printf("\t\t==================================\n");
		 		
		 				switch(getch())
			 			{
			 				case '1':
			 					printf("\t\t\t请输入修改后的姓名:");
	 							fflush(stdin);
								gets(p->name); 
								printf("\n\t\t\t修改成功！"); 
			 					break;
			 					
			 				case '2':
			 					printf("\t\t\t请输入修改后的性别:");
			 					fflush(stdin);
								gets(p->sexuality); 
			 					printf("\n\t\t\t修改成功！"); 
			 					break;
			 					
		 					case '3':
		 						printf("\t\t\t请输入修改后的电话号码:");
							 	scan_number(p->number);
								printf("\n\t\t\t修改成功！"); 
			 					break;
			 					
		 					case '4':
		 						printf("\t\t\t请输入修改后的地址:");
							 	fflush(stdin);
								gets(p->address); 
								printf("\n\t\t\t修改成功！"); 
			 					break;
			 				
			 				
			 					
			 				case '5':
		 						printf("\t\t\t请输入修改后的备注:");
							 	fflush(stdin);
								gets(p->remarks); 
								printf("\n\t\t\t修改成功！"); 
			 					break;
			 					
		 					case 27:goto come1; 
			 					break;
			 			}
			 			getch();
		 			}
		 		
			 		come1:;//goto标签 
				}
				break;
				
			case '2':
				printf("\t\t\t请输入要查找的电话号码:");
				fflush(stdin);
				gets(temp_num);
				
				p=p1;//回到头节点 
				while(p)//查找联系人 
				{
					if(!strcmp(temp_num,p->number))
						break;
					
					p=p->next;
				}
				
				if(!p)
				{
					printf("\t\t\t没有找到这个联系人！");
					getch();
				}
					
				else
				{
					while(1)
		 			{
		 				system("cls");
						printf("\t\t==================================\n");
						printf("\t\t\t1.修改姓名.\n");
						printf("\t\t\t2.修改姓别.\n");
						printf("\t\t\t3.修改号码.\n");
						printf("\t\t\t4.修改家庭住址.\n");
						printf("\t\t\t5.修改备注.\n");
						printf("\n\t\t\t退回上一层请按Esc\n"); 
			 			printf("\t\t==================================\n");
		 		
		 				switch(getch())
			 			{
			 				case '1':
			 					printf("\t\t\t请输入修改后的姓名:");
	 							fflush(stdin);
								gets(p->name); 
								printf("\n\t\t\t修改成功！"); 
			 					break;
			 					
			 				case '2':
			 					printf("\t\t\t请输入修改后的性别:");
			 					fflush(stdin);
								gets(p->sexuality); 
			 					printf("\n\t\t\t修改成功！"); 
			 					break;
			 					
		 					case '3':
		 						printf("\t\t\t请输入修改后的电话号码:");
							 	scan_number(p->number);
								printf("\n\t\t\t修改成功！"); 
			 					break;
			 					
		 					case '4':
		 						printf("\t\t\t请输入修改后的地址:");
							 	fflush(stdin);
								gets(p->address); 
								printf("\n\t\t\t修改成功！"); 
			 					break;
			 					
			 				case '5':
		 						printf("\t\t\t请输入修改后的备注:");
							 	fflush(stdin);
								gets(p->remarks); 
								printf("\n\t\t\t修改成功！"); 
			 					break;
			 					
		 					case 27:goto come2; 
			 					break;
			 			}
			 			getch();
		 			}
		 		
			 		come2:;//goto标签 
				}
				
				break;
				
			case 27:return head;//按Esc 
				break;
		}
	}
	
	return head;
} 

/*保存退出*/
void End(Cont*head,char name_file[])
{
	FILE*pf=NULL; 
	Cont*p=head->next;
	
	if(!(pf=fopen(name_file,"w")))//判断文件是否成功打开 
	{
		printf("\t\t\t程序出错！");
		return; 
	}
	
	while(p)
	{
		fwrite(p,sizeof(Cont),1,pf);
			
		p=p->next;
	}
	
	fclose(pf);
	release_Cont(head);
	
	exit(0);
} 

