#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>
#include<conio.h>
#include<assert.h>

typedef struct student
{
    char id[20];		// 学号 
    char name[50];		// 姓名 
    char gdsx[10];		// 高等数学成绩 
    char dxyy[10];		// 大学英语成绩 
    char sjjg[10];		//数据结构与算法成绩 
    char jsj[10];		//计算机组成原理成绩 
    char gll[10];		//概率论与数理统计成绩 
    char dxwl[10];		//大学物理成绩 
    int average;	//平均分 
    int total;		//总成绩 
} Student;

typedef struct LNode
{
    Student data;  //数据域 
    struct LNode* next;  // 指针域 
    
}LNode, * LinkList;

void input(LNode* head);
void DisplayAll(LNode* head);
void output(LNode* head);
void research_1(LNode* head, Student e);
void insert(LNode* head, int i, Student e);
void delete_1(LNode* head, int i, Student* e);
void exit_1();
void ModifySystem(LNode** pplist); 
void menu();
void sort(LNode** pplist);
void sort2(LNode** pplist);
void sort3(LNode** pplist);
void sort4(LNode** pplist);								//函数声明 

int main() {
	system("color f8\n");
    LNode* head;
    head = (LinkList)malloc(sizeof(LNode));
    head->next = NULL;
    int select = -1;
    int i;
    Student e;
	menu();
  	scanf("%d",&select);
  	while(select != 0)
  	{
	  	switch(select)
     	{
		case 1: 
            input(head);
            break;
        case 2:
            output(head);
            break;
        case 3:
            research_1(head, e);
            break;
        case 4:
            insert(head, i, e);
            break;
        case 5: 
            delete_1(head, i, &e);
            break;
        case 6:
            ModifySystem(&head);
            break;
        case 7: 
        	DisplayAll(head);
            break;
        case 8: 
            sort(&head);
            break;
        case 9: 
            sort2(&head);
            break;
        case 10: 
            sort4(&head);
            break; 
        case 11: 
            sort3(&head);
            break; 
        case 12: 
            exit_1();
            break;
     	}
    printf("\n输入任意键将返回主菜单\n");
    getch();
    menu();
    scanf("%d",&select);
  	}
    return 0;
}

//输入学生信息 
void input(LNode* head) 
{
    LinkList p, r; //p指向新结点，r指向当前链表的尾结点 
    int i, n; //n 为需要输入的学生人数
    r = head;
    printf("请输入学生的人数：");
    scanf("%d", &n);
    printf("请输入学生的信息");
    for (i = 1; i <= n; i++)
	 {
        p = (LinkList)malloc(sizeof(LNode));
        p->next = NULL;
        printf("\n学号\n");
        scanf("%s", p->data.id);
        printf("姓名\n");
        scanf("%s", p->data.name);
        printf("高等数学成绩\n");
        scanf("%s", p->data.gdsx);
        printf("大学英语成绩\n");
        scanf("%s", p->data.dxyy);
        printf("数据结构与算法成绩\n");
        scanf("%s", p->data.sjjg);
        printf("计算机组成原理成绩\n");
        scanf("%s", p->data.jsj);
        printf("概率论与数理统计成绩\n");
        scanf("%s", p->data.gll);
        printf("大学物理成绩\n");
        scanf("%s", p->data.dxwl);
        r->next = p;
        r = r->next;
        printf("---------------------------");
    }
    printf("************************");
}

//查询全部录入学生情况
void output(LNode* head) 
{
    LinkList p;
    p = head;
    printf("学号\t姓名\t高等数学\t大学英语\t数据结构与算法\t计算机组成原理\t概率论与数理统计\t大学物理\n");
    if (p->next != NULL)
	 {
        while (p->next != NULL)
        {	
            p = p->next;
		printf("%s\t%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\n",p->data.id,p->data.name,p->data.gdsx,p->data.dxyy,p->data.sjjg,p->data.jsj,p->data.gll,p->data.dxwl);
        }
    }
    else
    {
        printf("该系统中还未录入信息!\n");
    }

}

//输出已录入学生的平均分和总成绩 
void DisplayAll(LNode* head)
{  
	LinkList p;
    p = head;
	printf("\n全部学生成绩信息如下：\n\n");
	printf("学号\t姓名\t平均分\t总分\n");
    if (p->next != NULL)
	 {
        while (p->next != NULL)
        {	p = p->next;
			int a,b; 
			a=atoi(p->data.gdsx)+atoi(p->data.dxyy)+atoi(p->data.sjjg)+atoi(p->data.jsj)+atoi(p->data.gll)+atoi(p->data.dxwl);
			p->data.total=a;
			b=a/6;
			p->data.average=b;
            
		printf("%s\t%s\t%d\t%d\n",p->data.id,p->data.name,p->data.average,p->data.total);
		
        }
    }
    else
    {
        printf("该系统中还未录入信息!\n");
    }

}

//通过总分降序对学生信息进行排序 
void sort(LNode** pplist)
{
	for (LNode* p = (*pplist)->next; p != NULL; p = p->next)
	{
		for (LNode* q = p->next; q != NULL; q = q->next)
		{
			if (p->data.total > q->data.total)
			{
				LNode tmp;
				tmp.data = p->data;
				p->data = q->data;
				q->data = tmp.data;
			}
		}
	}
	printf("按总分降序排序成功！请返回查看\n");
	
}
//通过总分升序对学生信息进行排序 
void sort2(LNode** pplist)
{
	for (LNode* p = (*pplist)->next; p != NULL; p = p->next)
	{
		for (LNode* q = p->next; q != NULL; q = q->next)
		{
			if (p->data.total < q->data.total)
			{
				LNode tmp;
				tmp.data = p->data;
				p->data = q->data;
				q->data = tmp.data;
			}
		}
	}
	printf("按总分升序排序成功！请返回查看\n");
	
}

//通过学号升序对学生信息进行排序 
void sort3(LNode** pplist)
{
	for (LNode* p = (*pplist)->next; p != NULL; p = p->next)
	{	
		for (LNode* q = p->next; q != NULL; q = q->next)
		{	int a,b;
			a= atoi(p->data.id);
			b= atoi(q->data.id);
			if (a > b)
			{
				LNode tmp;
				tmp.data = p->data;
				p->data = q->data;
				q->data = tmp.data;
			}
		}
	}
	printf("按学号升序号排序成功！请返回查看\n");
	
}

//通过学号降序对学生信息进行排序 
void sort4(LNode** pplist)
{
	for (LNode* p = (*pplist)->next; p != NULL; p = p->next)
	{
		for (LNode* q = p->next; q != NULL; q = q->next)
		{	int a,b;
			a= atoi(p->data.id);
			b= atoi(q->data.id);
			if (a < b)
			{
				LNode tmp;
				tmp.data = p->data;
				p->data = q->data;
				q->data = tmp.data;
			}
		}
	}
	printf("按学号降序号排序成功！请返回查看\n");
	
}

//通过学号查看学生的成绩 
void research_1(LNode* head, Student e)
{
    int flag = 1;
    LinkList p;
    p = head;
    printf("请输入查找的学号：\n");
    scanf("%s", e.id);
    while ((p->next != NULL) && strcmp(e.id, p->data.id))
    {
        p = p->next;
        flag = 0;
    }
    if (flag!=0)
	{
        printf("未找到！\n");
    }
    else
    {
        printf("成功找到！\n\n");
        printf("学号\t姓名\t高等数学成绩\t大学英语成绩\t数据结构与算法成绩\t计算机组成原理成绩\t概率论与数理统计成绩\t大学物理成绩\n");
		printf("%s\t%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\n",p->data.id,p->data.name,p->data.gdsx,p->data.dxyy,p->data.sjjg,p->data.jsj,p->data.gll,p->data.dxwl);
    }
} 

//插入学生的信息· 
void insert(LNode* head, int i, Student e)
{
    int k;
    LNode* p;
    LNode* r;
    r = head; k = 0;
    printf("请输入你要插入的位置：\n");
    scanf("%d", &i);
    printf("输入学号：");
    scanf("%s", e.id);
    getchar();
    printf("输入名字：\n");
    scanf("%s", e.name);
    getchar();
    printf("输入高等数学成绩：");
    scanf("%s", e.gdsx);
    getchar();
    printf("输入大学英语成绩：");
    scanf("%s", e.dxyy);
    getchar();
    printf("输入数据结构与算法成绩：");
    scanf("%s", e.sjjg);
    getchar();
    printf("输入计算机组成原理成绩：");
    scanf("%s", e.jsj);
    getchar();
    printf("输入概率论与数理统计成绩：");
    scanf("%s", e.gll);
    getchar();
    printf("输入大学物理成绩：");
    scanf("%s", e.dxwl);
    getchar();
    while (r != NULL && k < i - 1)
    {
        r = r->next;
        k = k + 1;
    }
    if (r == NULL)
    {
        printf("插入失败！\n");
    }
    p = (LinkList)malloc(sizeof(LNode));
    p->data = e;
    p->next = r->next;
    r->next = p;
    printf("插入成功！\n");
}

//删除学生信息 
void delete_1(LNode* head, int i, Student* e)
{
    LinkList p, r;
    int k;
    r = head; k = 0;
    printf("请输入你要删除的位置：\n");
    scanf("%d", &i);
    while (r->next != NULL && k < i - 1)
    {
        r = r->next;
        k++;
    }
    if (r == NULL)
    {
        printf("删除失败！\n");
    }
    p = r->next;
    r->next = p->next;
    *e = p->data;
    free(p);
    printf("删除成功！\n");
}

//退出程序 
void  exit_1()
{
    printf("退出成功！请按任意键结束！");
    exit(0);
}

//单链表查找（此为修改的辅助）
static LNode* SListFind(LNode* plist, char name[])
{
    LNode* cur = plist->next;
    LNode* pos = plist;
    //1.空链表直接返回
    if (cur == NULL)
    {
        return NULL;
    }

    //遍历链表
    while (cur != NULL)
    {
        //如果找节点值等于x则返回
        if (strcmp(cur->data.name, name) == 0)
        {
            return pos;
        }
        //没找到继续遍历
        pos = pos->next;
        cur = cur->next;
    }
    return NULL;
}

//修改人的信息
void ModifySystem(LNode** pplist)//例：ModifySystem(&Plist);
{
    assert(*pplist);

    char name[50];
    printf("请输入要修改人的名字:");
    scanf("%s", name);
    getchar();

    LNode* mod = SListFind(*pplist, name);
    if (NULL == mod)
    {
        printf("要修改的人不存在!\n");
    }
    else
    {
        mod = mod->next;

        printf("请输入名字:>");
        scanf("%s", mod->data.name);
        getchar();
        printf("请输入学号:>");
        scanf("%s", mod->data.id);
        getchar();
        printf("请输入高等数学成绩:");
        scanf("%s", mod->data.gdsx);//高等数学成绩
        getchar();
        printf("请输入大学英语成绩:");
        scanf("%s", mod->data.dxyy);//大学英语成绩
        getchar();
        printf("请输入数据结构与算法成绩:");
        scanf("%s", mod->data.sjjg);//数据结构与算法成绩
        getchar();
        printf("输入计算机组成原理成绩：");
        scanf("%s", mod->data.jsj);//计算机组成原理成绩
        getchar();
        printf("输入概率论与数理统计成绩：");
        scanf("%s", mod->data.gll);//概率论与数理统计成绩
        getchar();
        printf("输入大学物理成绩：");
        scanf("%s", mod->data.dxwl);//大学物理成绩
        getchar();

        printf("修改成功!\n");
    }
}

void Change(LNode* nest)
{
    char name[50];
    printf("输入要修改的人的名字\n");
    scanf("%s", &name);
    getchar();
    LNode* q = nest;
    int p = 1;
    while (p)
    {
        q = q->next;
        if (strcmp(q->data.name, name) == 0)//判断是否找到该名字的人
            p = 0;
        if (q == NULL)
            p = 0;
    }
    if (q == NULL)
    {
        printf("查询错误");
    }
    else
    {
        printf("输入名字：");
        scanf("%s", q->data.name);
        getchar();
        printf("输入id：");
        scanf("%s", q->data.id);
        getchar();
        printf("输入高等数学成绩：");
        scanf("%s", q->data.gdsx);//高等数学成绩
        getchar();
        printf("输入大学英语成绩：");
        scanf("%s", q->data.dxyy);//大学英语成绩
        getchar();
        printf("输入数据结构与算法成绩：");
        scanf("%s", &q->data.sjjg);//数据结构与算法成绩
        getchar();
        printf("输入计算机组成原理成绩：");
        scanf("%s", q->data.jsj);//计算机组成原理成绩
        getchar();
        printf("输入概率论与数理统计成绩：");
        scanf("%s", q->data.gll);//概率论与数理统计成绩
        getchar();
        printf("输入大学物理成绩：");
        scanf("%s", q->data.dxwl);//大学物理成绩
        getchar();

    }

}


//主界面 
void menu()
{
	system("cls");
	printf("********************************************************************\n");
	printf("*      1. 录入学生信息；                                           *\n");
    printf("*      2. 显示学生表中已录入的所有学生信息；                       *\n");
    printf("*      3. 通过学号查找已录入学生信息；                             *\n");
    printf("*      4. 在表中指定位置插入一个学生信息；                         *\n");
    printf("*      5. 删除指定位置的学生信息；                                 *\n");
    printf("*      6. 通过名字修改学生信息；                                   *\n");
    printf("*      7. 以平均分与总分输出学生信息：                             *\n");
    printf("*      8. 对学生信息进行总分降序排序：                             *\n");
    printf("*      9. 对学生信息进行总分升序排序：                             *\n");
    printf("*      10. 对学生信息进行学号降序排序：                            *\n");
    printf("*      11. 对学生信息进行学号升序排序：                            *\n");
    printf("*      12. 退出程序                                                *\n");
    printf("********************************************************************\n");
    printf("\n");
    printf("请选择你要操作的选项：");
}
