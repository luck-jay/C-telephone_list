#ifndef ADBDY_H
#define Na 20
#define NL 13
#define Addre 100
#define NT 50 
#define SEX 5

/*联系人*/
typedef struct Contacts{
	char name[Na];
	char number[NL];
	char address[Addre];
	char sexuality[SEX];
	char remarks[Addre];
	struct Contacts*next;
}Cont; 

extern void Input(Cont*head,char name_file[]);//查看联系人 

extern Cont*Add(Cont*head);//添加联系人 

extern Cont*Delete(Cont*head);//删除联系人

extern Cont*Modify(Cont*head);//修改联系人信息 

extern void End(Cont*head,char name_file[]);//保存退出 

extern Cont*Read_account(char name_file[]);//读取联系人 

extern void release_Cont(Cont*p);//释放联系人链表

extern Cont*Del(Cont*p,char cont_name[]);//删除一个联系人 

extern void Derived(Cont*head,char name_file[]);//导出到表格 

#define ADBDY_H
#endif

