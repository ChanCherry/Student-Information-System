#include <iostream>
using namespace std;
#include "sym.h"
#include <cstdlib>
#include <cstring>
STU *insert(STU *head)							/*输入学生学号和各课成绩，并计算平均分*/
{	
  	STU *p,*q,*pr;
 	int j;
  	pr=(STU *)malloc(sizeof(STU));
 	cout<<"\n姓名："; cin>>pr->name;
 	cout<<"\n学号："; cin>>pr->num;
 	cout<<"\n英语 高数 C语言：\n";
 	pr->aver=0;
 	for(j=0;j<3;j++)
	{	
      		cin>>pr->score[j];
	 	pr->aver+=pr->score[j];
	}
  	pr->aver/=3;
  	p=head;								/*新结点按照学号从小到大插入链表*/
  	if(head==NULL) 							/*链表是空链表*/
	{	
      	   	head=pr;
	   	pr->next=NULL;
	}
  	else
	{
      	   	while((p->next!=NULL)&&(p->num < pr->num))		/*寻找插入位置*/
		{
        		q=p; p=p->next;
      		}
	   	if(p->num >= pr->num) 
		{	
        		if(head==p) 					/*链表非空，插入到第一个结点前*/
          			pr->next=head; head=pr;
			else                      			/*链表非空，插入到链表中间*/
			{
				q->next=pr; pr->next=p;
        		} 			
		}
	   	else							/*链表非空，插入到链表末尾*/
		{
			p->next=pr; pr->next=NULL;
		} 			
	}
  	return head;
}
void search_num(STU *head) 						/*按照输入学生的学号查找各科成绩和平均分*/
{	
  	STU *p;
 	long in_num;
 	cout<<"\n请输入要查询的学生学号：";
 	cin>>in_num;
 	p=head;
 	if(head==NULL) 							/*链表是空链表*/
	cout<<"无学生数据！\n";
 	while((p->next!=NULL)&&(p->num!=in_num)) 			/*寻找结点位置*/
	p=p->next;
 	if(in_num==p->num)
	{	
    		cout.precision(1);					/*限制浮点数输出为一位小数*/
 		cout<<fixed<<"\n姓名："<<p->name<<"，英语成绩："<<p->score[0]<<"，高数成绩："<<p->score[1]<<"，C语言成绩："<<p->score[2]
	 	<<"，平均成绩："<<p->aver<<endl;
	}
 	else
	cout<<"查无此学号\n";
} 
void search(STU *head,float max)					/*查找平均分最高的学生姓名、学号、平均分*/ 
{	STU *p=head;
 	long high_num;
 	while(p!=NULL) 							/*寻找平均分最高的学生学号*/
	{	
    		if(p->aver>max)
		{
      			max=p->aver; high_num=p->num;
    		}
	  	p=p->next;
	}
  	p=head;								/*寻找平均分最高的学生位置*/
  	while((p->next!=NULL)&&(p->num!=high_num))
	{
		p=p->next;
	}
	cout.precision(1);
  	cout<<fixed<<"\n姓名："<<p->name<<"，英语成绩："<<p->score[0]<<"，高数成绩："<<p->score[1]<<"，C语言成绩："<<p->score[2]
	<<"，平均成绩："<<p->aver<<endl;
}
void search(STU *head,int min)						/*查找低于输入的平均分的学生姓名、学号、平均分*/ 
{	
  	STU *p=head;
	int &m=min;							/*引用，方便输入*/ 
	int flag=0;
	cout<<"请输入要查找的最低平均分：";
	cin>>min;
	cout.precision(1);
 	while(p!=NULL)
 	{
	 	if((p->aver < m) && (p->aver > 0))
		{	
      			cout<<fixed<<"\n姓名："<<p->name<<"，英语成绩："<<p->score[0]<<"，高数成绩："<<p->score[1]<<"，C语言成绩："<<p->score[2]
			<<"，平均成绩："<<p->aver<<endl;
			flag=1;
    		}
		p=p->next;
 	}
 	if(!flag)	
  	cout<<"没有低于"<<m<<"的学生！"; 
}
STU *dele_num(STU *head) 						/*按照输入学生的学号删除记录*/
{	
  	STU *p,*q;
 	long in_num;
 	cout<<"\n请输入要删除的学生学号：";
 	cin>>in_num;
 	p=head;
 	if(head==NULL)  						/*链表是空链表*/
	{
    		cout<<"无学生数据！\n";
	  	return(head);  
  	}
 	while((p->next!=NULL)&&(p->num!=in_num)) 			/*寻找删除结点位置*/
	{
    		q=p; 
    		p=p->next;
  	}
 	if(p->num==in_num)
	{	
    		if(head==p) head=p->next; 				/*删除链表第一个结点*/ 
	 	else q->next=p->next;					/*删除链表结点*/
	  	free(p);
	  	cout<<"已删除\n";
	}
 	else
  	{
    		cout<<"数据库中无此学生学号！\n";
  	}
 	return head;
} 
STU *modi_num(STU *head)  		 				/*按照输入学生的学号修改记录*/
{	
  	STU *p;
 	long in_num; 
  	int j;
 	cout<<"\n请输入要修改的学生学号：";
 	cin>>in_num;
 	p=head;
 	if(head==NULL) 							/*链表是空链表*/
	{	
    		cout<<"无学生数据!\n";
	  	return(head);	 
  	}
 	while((p->next!=NULL)&&(p->num!=in_num)) 			/*寻找要修改结点的位置*/
	p=p->next;
 	if(p->num==in_num)
	{
    		cout<<"\n姓名："; 
    		cin>>p->name;
	 	cout<<"\n英语 高数 C语言：\n";
	 	p->aver=0;
	 	for(j=0;j<3;j++)
		{	
        		cin>>p->score[j];
		  	p->aver+=p->score[j]; 
    		}
		p->aver/=3;
	}
 	else
	cout<<"数据库中无此学生学号！\n";
 	return head;
}
void output(STU *head)  						/*按照学号从小到大顺序显示输出*/
{
  	STU *p=head;
	cout.precision(1);
 	if(head==NULL) 							/*链表是空链表*/
	cout<<"无学生数据！\n";
 	else
	{	
      		cout<<"\n学号\t\t姓名\t英语\t高数\tC语言\t平均分\n";
	  	while(p!=NULL)
		{	
        		cout<<fixed<<p->num<<"\t\t"<<p->name<<"\t"<<p->score[0]<<"\t"<<p->score[1]<<"\t"<<p->score[2]<<"\t"<<p->aver<<endl;
		   	p=p->next; 
      		}
	}
}
