#include <iostream>
#include <cstring>
using namespace std;
#include "sym.h"
int main() 
{
	int x;             /*x为菜单的选择*/
	STU *head=NULL;
	float max;int min;
	while(1)
	{	
    		cout<<"\n\t\t\t主菜单\n";
		cout<<"\t==================================\n";
		cout<<"\t\t1. 输入学生成绩\n";
		cout<<"\t\t2. 学号查询学生成绩\n";
		cout<<"\t\t3. 学号删除学生成绩\n";
		cout<<"\t\t4. 学号修改学生成绩\n";
		cout<<"\t\t5. 打印学生成绩\n";
		cout<<"\t\t6. 查找平均分最高\n";
		cout<<"\t\t7. 查找平均分最低\n";
		cout<<"\t\t0. 退出系统\n";
		cout<<"\t==================================\n";
		cout<<"\t请选择（0~7）："; 
		cin>>x;
		switch(x)
		{	
        		case 1:head=insert(head); break;
		   	case 2:search_num(head); break;
		   	case 3:head=dele_num(head); break;
		   	case 4:head=modi_num(head); break;
		   	case 5:output(head); break;
		   	case 6:search(head,max); break;
		   	case 7:search(head,min); break;
		   	case 0:cout<<"谢谢使用！";exit(0);
		   	default:cout<<"\n输入错误，请重新输入！"; break;
	  	}
	}
	return 0;
}
