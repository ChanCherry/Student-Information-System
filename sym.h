typedef struct student      
{ 	long num;             				//学号
	  int score[3];         				//三门课成绩
	  float aver;           				//平均分
	  char name[20];        				//姓名
	  struct student *next; 				//指针域，指向链表的下一个结点
}STU;
STU *insert(STU *head);								    //输入学生学号和各课成绩，并计算平均分
void search_num(STU *head);				 			  //按照输入学生的学号查找各科成绩和平均分
STU *dele_num(STU *head); 							  //按照输入学生的学号删除记录
STU *modi_num(STU *head);  		 					  //按照输入学生的学号修改记录
void output(STU *head);  							    //按照学号从小到大顺序显示输出
void search(STU *head,float max);					//查找平均分最高的学生姓名、学号、平均分
void search(STU *head,int min);						//查找低于输入的平均分的学生姓名、学号、平均分
