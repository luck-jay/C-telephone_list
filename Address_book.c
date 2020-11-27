#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cover.h"
#include "Adbdy.h"
#include "Sys.h"

/*通讯录管理主体函数*/ 
void _main_(char name[])
{
	extern judge;
	FILE*pf=NULL;
	Cont*Head=NULL;
	char name_file[Acc+4],name_file_xlsx[Acc+4];
	
	strcpy(name_file,name);
	strcat(name_file,".txt");
	
	if(!(pf=fopen(name_file,"at+")))//判断文件是否成功打开 
	{
		printf("\t\t\t程序出错！");
		exit(0); 
	}
	
	Head=Read_account(name_file);//读取联系人 
	
	fclose(pf);//关闭文件
	
	while(1)
	{
		system("cls");
		
		cover_main(name);
	
		switch(getch())
		{
			case '1':Input(Head,name_file);
				break;
				
			case '2':Head=Add(Head);
				break;
				
			case '3':Delete(Head);
				break;
				
			case '4':Head=Modify(Head);
				break;
				
			case '5':
				End(Head,name_file);
				break;
			
			case '6':
				strcpy(name_file_xlsx,name);
				Derived(Head,name_file_xlsx); 
				printf("\t\t\t导出成功！");
				getch();
				break;
				
			case '0':
				release_Cont(Head);
			//	 CloseHandle(handle);
				exit(0);
				break;
		}
	}
}
