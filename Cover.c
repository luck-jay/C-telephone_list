#include <stdio.h>

/*Output longin page*/
void cover_pass()
{
	printf("\t\t\t欢迎使用通讯录管理系统\n");
	printf("\t\t\t----------------------\n\n");
	printf("\t\t\t1.用户登录\n");
	printf("\t\t\t2.用户注册\n");
	printf("\t\t\t3.密码修改\n");
	printf("\t\t\t0.退出\n\n");
	printf("\t\t\t----------------------\n\n");
}

/*Output main page*/
void cover_main(char name[])
{
	printf("\t\t\t-----------------------------------------------\n");
	printf("\t\t\t        %s的通讯录       \n",name);
	printf("\t\t\t-----------------------------------------------\n\n");
	printf("\t\t\t1.查看联系人\n");
	printf("\t\t\t2.添加联系人\n");
	printf("\t\t\t3.删除联系人\n");
	printf("\t\t\t4.修改信息\n");
	printf("\t\t\t5.保存并退出\n");
	printf("\t\t\t6.导出到表格\n");
	printf("\t\t\t0.退出\n\n");
	printf("\t\t\t-----------------------------------------------\n");
	printf("\t\t\t-----------------------------------------------\n");
}

/*注册界面*/
void cover_register()
{
	printf("\t\t\t--------------\n\n");
	printf("\t\t\t欢迎新用户注册\n\n");
	printf("\t\t\t--------------\n\n");
} 

/*登录界面*/
void cover_password()
{
	printf("\t\t\t----------------------\n");
	printf("\t\t\t|      欢迎登录      |\n");
	printf("\t\t\t----------------------\n");
} 

/*查看联系人*/ 
void cover_seek()
{
	printf("\t\t\t1.排序\n");
	printf("\t\t\t2.查找\n"); 
	printf("\t\t\t如需退出查看状态请按Esc.\n");
	printf("===============================================================\n\n");
}
