#ifndef ADBDY_H
#define Na 20
#define NL 13
#define Addre 100
#define NT 50 
#define SEX 5

/*��ϵ��*/
typedef struct Contacts{
	char name[Na];
	char number[NL];
	char address[Addre];
	char sexuality[SEX];
	char remarks[Addre];
	struct Contacts*next;
}Cont; 

extern void Input(Cont*head,char name_file[]);//�鿴��ϵ�� 

extern Cont*Add(Cont*head);//�����ϵ�� 

extern Cont*Delete(Cont*head);//ɾ����ϵ��

extern Cont*Modify(Cont*head);//�޸���ϵ����Ϣ 

extern void End(Cont*head,char name_file[]);//�����˳� 

extern Cont*Read_account(char name_file[]);//��ȡ��ϵ�� 

extern void release_Cont(Cont*p);//�ͷ���ϵ������

extern Cont*Del(Cont*p,char cont_name[]);//ɾ��һ����ϵ�� 

extern void Derived(Cont*head,char name_file[]);//��������� 

#define ADBDY_H
#endif

