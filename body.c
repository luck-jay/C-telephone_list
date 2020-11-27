#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "Adbdy.h" 
#include "Sys.h"
#include "cover.h"

/*�������Ļ*/
int out(Cont*p)
{
	int count=0,temp; 
	
	if(!p)
	{
		printf("\n\t\t\tû����ϵ����Ϣ��");
		return count;
	}
	
	printf("\n   ����\t\t\b\b\b�Ա�     �绰����\t\t��ͥסַ\t\t\t\t��ע");
	
	while(p)//��� 
	{		
		Gotoxy(0,_where_().Y+2);
		printf("%d. ",count+1);

		temp=_where_().X;//�õ�x���� 

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

/*������ϵ��*/
Cont*seek(Cont*p)
{
	int i,j;
	COUNT count=0;//printf("����");while(1);
	char temp[Addre];
	char cont_name[Na],temp_name[Na];
	char temp_number[NL];
	Cont*p1=NULL,*p2=NULL,*head=NULL;
	
	p1=head=(Cont*)malloc(sizeof(Cont));
	head->next=NULL;
	
	printf("\t\t==================================\n");
	printf("\t\t\t1.����������\n");
	printf("\t\t\t2.���������\n");
	printf("\n\t\t\t�˻���ҳ���밴Esc\n"); 
	printf("\t\t==================================\n");
	
	while(1)
	{	
		switch(getch())
		{
			case '1':
				printf("\t\t\t������Ҫ���ҵ���ϵ��������ؼ��֣�");
				fflush(stdin);
				gets(temp_name);
				
				while(p)//������ϵ�� 
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
				printf("\t\t\t������Ҫ���ҵĵ绰���룺");
				scan_number(temp_number);
			
				while(p)//������ϵ�� 
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

/*�ж�����ĸ����*/
char head_letter(char lett[])
{
	int temp;
	
	temp=(unsigned char)lett[0]*256+(unsigned char)lett[1];

	if(temp>=45217&&temp<=45252)//�ж�����ĸ 
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

/*�ж���ĸ*/
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
	
    
	if(!p1||!p1->next)//�ж������Ƿ�ֻ��һ��Ԫ�ػ����ǿ����� 
		return head;

    while(p2->next)//ð������ 
    {
        for(p3 = head, tep = p3 -> next, Next = tep -> next; Next; p3 = p3 -> next, tep = tep -> next, Next = Next -> next)
        {
            
            if(!strcmp(tep->name,Next->name))//�����ڵ� 
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

/*����*/
void sort(Cont*head)
{
	COORD tep;
	Cont*p=head->next,*p1=p;
	char temp_lett;
	int temp_num[27]={0},count[27]={0};
	int i,j; 
	int temp;

	head=sort_list(head);
	
	while(p1)//�õ���Ԫ�ظ��� 
	{
		if(p1->name[0]<0)
			sort_lett(temp_num,head_letter(p1->name));
		else
			sort_lett(temp_num,p1->name[0]);
		
		p1=p1->next;
	}
	
	system("cls");
	printf("\n   ����\t\t\b\b\b�Ա�     �绰����\t\t��ͥסַ\t\t\t\t��ע\n");
	
	for(i=0;i<27;i++)//������ 
	{
		if(temp_num[i])
		{	
			if(i<26)
			{
				printf("%c-------------------------------------------------------------------\n",65+i);
				count[i]=_where_().Y;//�õ������ʼλ�� 
			}
				
			else
			{
				printf("#-------------------------------------------------------------------\n");
				count[26]=_where_().Y;//�õ������ʼλ�� 
				break;
			}
			
			for(j=0;j<temp_num[i];j++)//�õ������Χ�Ĵ�С 
				printf("\n");	
		}
	}
	
	while(p)//�����ϵ�� 
	{
		for(i=0;i<27;i++)//�������� 
			temp_num[i]=0;
		
		if(p->name[0]<0)
		{
			sort_lett(temp_num,head_letter(p->name));//�õ�����ĸ 
			
			for(i=0;i<27;i++)//��������ĸ 
				if(temp_num[i])
					break;
			
			Gotoxy(3,count[i]);//��ʾ 
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
			sort_lett(temp_num,p->name[0]);//�õ�����ĸ 
		
			for(i=0;i<27;i++)//��������ĸ 
				if(temp_num[i])
					break;
			
			Gotoxy(3,count[i]);//��ʾ 
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
	
/*��ʾ��ϵ��*/
void Input(Cont*head,char name_file[])
{
	Cont*p=head->next,*p1=p,*p2=NULL;
	char name[Na];
	int number[26]={0};//��¼���ݸ��� 
	 
	system("cls");
	
 	if(!p)
	{
		printf("�㲢û�б������ϵ�ˣ�");
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
 
/*�����ϵ��*/ 
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
			printf("\t\t\t��������Ҫ��ӵ���ϵ������:");
			gets(temp->name);
		
			while(p1)//�ж���ϵ���Ƿ���� 
			{
				if(!strcmp(p1->name,temp->name))
				{
					printf("\t\t\t����ϵ���Ѿ��������");
					break;
				}
			
				p1=p1->next;
			}
		
			if(!p1)//�ж��Ƿ��������ϵ�� 
				break;
			
			printf("\n\n\t\t\t����ص����˵��밴Esc��������������밴�������");
		
			if(getch()==27)//�ж��Ƿ���Esc 
			{
				free(temp);
				return head;
			}
				
		}
		
		printf("\n\t\t\t������%s���Ա�:",temp->name);
		fflush(stdin);
		gets(temp->sexuality);
		
	
		printf("\t\t\t������%s�ĵ绰����:",temp->name);
		scan_number(temp->number);
	
		printf("\n\t\t\t������%s�ļ�ͥסַ:",temp->name);
		fflush(stdin);
		gets(temp->address);
		
		printf("\n\t\t\t������%s�ı�ע:",temp->name);
		fflush(stdin);
		gets(temp->remarks);
		
		head->next=temp;
		temp->next=p2;
		p2=temp;
		 
		printf("\n\n\t\t\t�����˳��밴Esc.�����������¼��.");
		if(getch()==27)
			break;
	} 
	
	return head; 
} 

/*ɾ����ϵ��*/
Cont*Delete(Cont*head)
{ 
	int count[NT],temp_count,err,temp,Count[NT];
	int i,j;
	char cont_name[Na][NT];
	Cont*p=head->next,*p1=NULL,*p2=NULL;
	
	system("cls");
	
	if(!p)
	{
		printf("�㲢û�б������ϵ�ˣ�");
		getch();
		return head;
	}
	
	while(1)
	{
		if(!(p1=seek(p)))
			return head;
		
		if(!p1->next)//�ж��Ƿ�Ϊ�� 
		{ 
			printf("\n\t\t\tû�в��ҵ������ϵ�ˣ�"); 
			printf("\n\t\t\t���践����ҳ�밴Esc,���������밴Enter.");
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
			if(!out(p1->next))//�ж��Ƿ�����ϵ�� 
				goto come;//��������ѭ�� 

			printf("\n\t\t\t���践����ҳ�밴Esc,�������������");
			if(getch()==27)
				goto come;
			
			system("cls");
			err=out(p1->next);
			
			printf("\n\t\t\t����������Ҫɾ�������ݱ��:");
			
			for(i=0;Count[i];i++)//������� 
				Count[i]=0;
			
			scan_num(Count,err);//�õ�ɾ����� 
			
			for(i=0;Count[i];i++)//�������
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
			
						temp=_where_().X;//�õ�x���� 
			
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
			
		
		printf("\n\t\t\tȷ��ɾ����Enter.");
		if(getch()=='\r')
			break;
		}
		
		for(i=0;Count[i];i++)
		{
			temp_count=Count[i];
			
			if(count[i]==temp_count)//ɾ��ѡ�е�һ�� 
			{
				p1=Del(p1,cont_name[i]);//ɾ��һ���ڵ� 
				head=Del(head,cont_name[i]);
			}
		}
		
		printf("\n\t\t\tɾ���ɹ���");
		printf("\n\n\t\t\t�����˳��밴Esc.�����������ɾ��.");
		if(getch()==27)
			break;
	}
	
	come:release_Cont(p1);
	
	return head;
}

/*�޸���ϵ����Ϣ*/
Cont*Modify(Cont*head)
{
	Cont*p=head->next,*p1=p;
	char temp_name[Na],temp_num[NL];
	
	system("cls");
	
	if(!p)
	{
		printf("�㲢û�б������ϵ�ˣ�");
		getch();
		return head;
	}
	
	while(1)
	{
		system("cls");
		
		printf("\t\t==================================\n");
		printf("\t\t\t1.����������\n");
		printf("\t\t\t2.���������\n");
		printf("\n\t\t\t�˻���ҳ���밴Esc\n"); 
		printf("\t\t==================================\n");
	

		switch(getch())
		{
			case '1':
				printf("\t\t\t������Ҫ���ҵ�����:");
				fflush(stdin);
				gets(temp_name);
				
				p=p1;//�ص�ͷ�ڵ� 
				while(p)//������ϵ�� 
				{
					if(!strcmp(temp_name,p->name))
						break;
					
					p=p->next;
				}
				
				if(!p)
				{
					printf("\t\t\tû���ҵ������ϵ�ˣ�");
					getch();
				}
				
				else
				{
					while(1)
		 			{
		 				system("cls");
						printf("\t\t==================================\n");
						printf("\t\t\t1.�޸�����.\n");
						printf("\t\t\t2.�޸��ձ�.\n");
						printf("\t\t\t3.�޸ĺ���.\n");
						printf("\t\t\t4.�޸ļ�ͥסַ.\n");
						printf("\t\t\t5.�޸ı�ע.\n");
						printf("\n\t\t\t�˻���һ���밴Esc\n"); 
			 			printf("\t\t==================================\n");
		 		
		 				switch(getch())
			 			{
			 				case '1':
			 					printf("\t\t\t�������޸ĺ������:");
	 							fflush(stdin);
								gets(p->name); 
								printf("\n\t\t\t�޸ĳɹ���"); 
			 					break;
			 					
			 				case '2':
			 					printf("\t\t\t�������޸ĺ���Ա�:");
			 					fflush(stdin);
								gets(p->sexuality); 
			 					printf("\n\t\t\t�޸ĳɹ���"); 
			 					break;
			 					
		 					case '3':
		 						printf("\t\t\t�������޸ĺ�ĵ绰����:");
							 	scan_number(p->number);
								printf("\n\t\t\t�޸ĳɹ���"); 
			 					break;
			 					
		 					case '4':
		 						printf("\t\t\t�������޸ĺ�ĵ�ַ:");
							 	fflush(stdin);
								gets(p->address); 
								printf("\n\t\t\t�޸ĳɹ���"); 
			 					break;
			 				
			 				
			 					
			 				case '5':
		 						printf("\t\t\t�������޸ĺ�ı�ע:");
							 	fflush(stdin);
								gets(p->remarks); 
								printf("\n\t\t\t�޸ĳɹ���"); 
			 					break;
			 					
		 					case 27:goto come1; 
			 					break;
			 			}
			 			getch();
		 			}
		 		
			 		come1:;//goto��ǩ 
				}
				break;
				
			case '2':
				printf("\t\t\t������Ҫ���ҵĵ绰����:");
				fflush(stdin);
				gets(temp_num);
				
				p=p1;//�ص�ͷ�ڵ� 
				while(p)//������ϵ�� 
				{
					if(!strcmp(temp_num,p->number))
						break;
					
					p=p->next;
				}
				
				if(!p)
				{
					printf("\t\t\tû���ҵ������ϵ�ˣ�");
					getch();
				}
					
				else
				{
					while(1)
		 			{
		 				system("cls");
						printf("\t\t==================================\n");
						printf("\t\t\t1.�޸�����.\n");
						printf("\t\t\t2.�޸��ձ�.\n");
						printf("\t\t\t3.�޸ĺ���.\n");
						printf("\t\t\t4.�޸ļ�ͥסַ.\n");
						printf("\t\t\t5.�޸ı�ע.\n");
						printf("\n\t\t\t�˻���һ���밴Esc\n"); 
			 			printf("\t\t==================================\n");
		 		
		 				switch(getch())
			 			{
			 				case '1':
			 					printf("\t\t\t�������޸ĺ������:");
	 							fflush(stdin);
								gets(p->name); 
								printf("\n\t\t\t�޸ĳɹ���"); 
			 					break;
			 					
			 				case '2':
			 					printf("\t\t\t�������޸ĺ���Ա�:");
			 					fflush(stdin);
								gets(p->sexuality); 
			 					printf("\n\t\t\t�޸ĳɹ���"); 
			 					break;
			 					
		 					case '3':
		 						printf("\t\t\t�������޸ĺ�ĵ绰����:");
							 	scan_number(p->number);
								printf("\n\t\t\t�޸ĳɹ���"); 
			 					break;
			 					
		 					case '4':
		 						printf("\t\t\t�������޸ĺ�ĵ�ַ:");
							 	fflush(stdin);
								gets(p->address); 
								printf("\n\t\t\t�޸ĳɹ���"); 
			 					break;
			 					
			 				case '5':
		 						printf("\t\t\t�������޸ĺ�ı�ע:");
							 	fflush(stdin);
								gets(p->remarks); 
								printf("\n\t\t\t�޸ĳɹ���"); 
			 					break;
			 					
		 					case 27:goto come2; 
			 					break;
			 			}
			 			getch();
		 			}
		 		
			 		come2:;//goto��ǩ 
				}
				
				break;
				
			case 27:return head;//��Esc 
				break;
		}
	}
	
	return head;
} 

/*�����˳�*/
void End(Cont*head,char name_file[])
{
	FILE*pf=NULL; 
	Cont*p=head->next;
	
	if(!(pf=fopen(name_file,"w")))//�ж��ļ��Ƿ�ɹ��� 
	{
		printf("\t\t\t�������");
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

