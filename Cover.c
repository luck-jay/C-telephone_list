#include <stdio.h>

/*Output longin page*/
void cover_pass()
{
	printf("\t\t\t��ӭʹ��ͨѶ¼����ϵͳ\n");
	printf("\t\t\t----------------------\n\n");
	printf("\t\t\t1.�û���¼\n");
	printf("\t\t\t2.�û�ע��\n");
	printf("\t\t\t3.�����޸�\n");
	printf("\t\t\t0.�˳�\n\n");
	printf("\t\t\t----------------------\n\n");
}

/*Output main page*/
void cover_main(char name[])
{
	printf("\t\t\t-----------------------------------------------\n");
	printf("\t\t\t        %s��ͨѶ¼       \n",name);
	printf("\t\t\t-----------------------------------------------\n\n");
	printf("\t\t\t1.�鿴��ϵ��\n");
	printf("\t\t\t2.�����ϵ��\n");
	printf("\t\t\t3.ɾ����ϵ��\n");
	printf("\t\t\t4.�޸���Ϣ\n");
	printf("\t\t\t5.���沢�˳�\n");
	printf("\t\t\t6.���������\n");
	printf("\t\t\t0.�˳�\n\n");
	printf("\t\t\t-----------------------------------------------\n");
	printf("\t\t\t-----------------------------------------------\n");
}

/*ע�����*/
void cover_register()
{
	printf("\t\t\t--------------\n\n");
	printf("\t\t\t��ӭ���û�ע��\n\n");
	printf("\t\t\t--------------\n\n");
} 

/*��¼����*/
void cover_password()
{
	printf("\t\t\t----------------------\n");
	printf("\t\t\t|      ��ӭ��¼      |\n");
	printf("\t\t\t----------------------\n");
} 

/*�鿴��ϵ��*/ 
void cover_seek()
{
	printf("\t\t\t1.����\n");
	printf("\t\t\t2.����\n"); 
	printf("\t\t\t�����˳��鿴״̬�밴Esc.\n");
	printf("===============================================================\n\n");
}
