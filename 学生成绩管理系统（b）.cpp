#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>
#include<conio.h>
#include<assert.h>

typedef struct student
{
    char id[20];		// ѧ�� 
    char name[50];		// ���� 
    char gdsx[10];		// �ߵ���ѧ�ɼ� 
    char dxyy[10];		// ��ѧӢ��ɼ� 
    char sjjg[10];		//���ݽṹ���㷨�ɼ� 
    char jsj[10];		//��������ԭ��ɼ� 
    char gll[10];		//������������ͳ�Ƴɼ� 
    char dxwl[10];		//��ѧ����ɼ� 
    int average;	//ƽ���� 
    int total;		//�ܳɼ� 
} Student;

typedef struct LNode
{
    Student data;  //������ 
    struct LNode* next;  // ָ���� 
    
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
void sort4(LNode** pplist);								//�������� 

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
    printf("\n������������������˵�\n");
    getch();
    menu();
    scanf("%d",&select);
  	}
    return 0;
}

//����ѧ����Ϣ 
void input(LNode* head) 
{
    LinkList p, r; //pָ���½�㣬rָ��ǰ�����β��� 
    int i, n; //n Ϊ��Ҫ�����ѧ������
    r = head;
    printf("������ѧ����������");
    scanf("%d", &n);
    printf("������ѧ������Ϣ");
    for (i = 1; i <= n; i++)
	 {
        p = (LinkList)malloc(sizeof(LNode));
        p->next = NULL;
        printf("\nѧ��\n");
        scanf("%s", p->data.id);
        printf("����\n");
        scanf("%s", p->data.name);
        printf("�ߵ���ѧ�ɼ�\n");
        scanf("%s", p->data.gdsx);
        printf("��ѧӢ��ɼ�\n");
        scanf("%s", p->data.dxyy);
        printf("���ݽṹ���㷨�ɼ�\n");
        scanf("%s", p->data.sjjg);
        printf("��������ԭ��ɼ�\n");
        scanf("%s", p->data.jsj);
        printf("������������ͳ�Ƴɼ�\n");
        scanf("%s", p->data.gll);
        printf("��ѧ����ɼ�\n");
        scanf("%s", p->data.dxwl);
        r->next = p;
        r = r->next;
        printf("---------------------------");
    }
    printf("************************");
}

//��ѯȫ��¼��ѧ�����
void output(LNode* head) 
{
    LinkList p;
    p = head;
    printf("ѧ��\t����\t�ߵ���ѧ\t��ѧӢ��\t���ݽṹ���㷨\t��������ԭ��\t������������ͳ��\t��ѧ����\n");
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
        printf("��ϵͳ�л�δ¼����Ϣ!\n");
    }

}

//�����¼��ѧ����ƽ���ֺ��ܳɼ� 
void DisplayAll(LNode* head)
{  
	LinkList p;
    p = head;
	printf("\nȫ��ѧ���ɼ���Ϣ���£�\n\n");
	printf("ѧ��\t����\tƽ����\t�ܷ�\n");
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
        printf("��ϵͳ�л�δ¼����Ϣ!\n");
    }

}

//ͨ���ֽܷ����ѧ����Ϣ�������� 
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
	printf("���ֽܷ�������ɹ����뷵�ز鿴\n");
	
}
//ͨ���ܷ������ѧ����Ϣ�������� 
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
	printf("���ܷ���������ɹ����뷵�ز鿴\n");
	
}

//ͨ��ѧ�������ѧ����Ϣ�������� 
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
	printf("��ѧ�����������ɹ����뷵�ز鿴\n");
	
}

//ͨ��ѧ�Ž����ѧ����Ϣ�������� 
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
	printf("��ѧ�Ž��������ɹ����뷵�ز鿴\n");
	
}

//ͨ��ѧ�Ų鿴ѧ���ĳɼ� 
void research_1(LNode* head, Student e)
{
    int flag = 1;
    LinkList p;
    p = head;
    printf("��������ҵ�ѧ�ţ�\n");
    scanf("%s", e.id);
    while ((p->next != NULL) && strcmp(e.id, p->data.id))
    {
        p = p->next;
        flag = 0;
    }
    if (flag!=0)
	{
        printf("δ�ҵ���\n");
    }
    else
    {
        printf("�ɹ��ҵ���\n\n");
        printf("ѧ��\t����\t�ߵ���ѧ�ɼ�\t��ѧӢ��ɼ�\t���ݽṹ���㷨�ɼ�\t��������ԭ��ɼ�\t������������ͳ�Ƴɼ�\t��ѧ����ɼ�\n");
		printf("%s\t%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\n",p->data.id,p->data.name,p->data.gdsx,p->data.dxyy,p->data.sjjg,p->data.jsj,p->data.gll,p->data.dxwl);
    }
} 

//����ѧ������Ϣ�� 
void insert(LNode* head, int i, Student e)
{
    int k;
    LNode* p;
    LNode* r;
    r = head; k = 0;
    printf("��������Ҫ�����λ�ã�\n");
    scanf("%d", &i);
    printf("����ѧ�ţ�");
    scanf("%s", e.id);
    getchar();
    printf("�������֣�\n");
    scanf("%s", e.name);
    getchar();
    printf("����ߵ���ѧ�ɼ���");
    scanf("%s", e.gdsx);
    getchar();
    printf("�����ѧӢ��ɼ���");
    scanf("%s", e.dxyy);
    getchar();
    printf("�������ݽṹ���㷨�ɼ���");
    scanf("%s", e.sjjg);
    getchar();
    printf("�����������ԭ��ɼ���");
    scanf("%s", e.jsj);
    getchar();
    printf("���������������ͳ�Ƴɼ���");
    scanf("%s", e.gll);
    getchar();
    printf("�����ѧ����ɼ���");
    scanf("%s", e.dxwl);
    getchar();
    while (r != NULL && k < i - 1)
    {
        r = r->next;
        k = k + 1;
    }
    if (r == NULL)
    {
        printf("����ʧ�ܣ�\n");
    }
    p = (LinkList)malloc(sizeof(LNode));
    p->data = e;
    p->next = r->next;
    r->next = p;
    printf("����ɹ���\n");
}

//ɾ��ѧ����Ϣ 
void delete_1(LNode* head, int i, Student* e)
{
    LinkList p, r;
    int k;
    r = head; k = 0;
    printf("��������Ҫɾ����λ�ã�\n");
    scanf("%d", &i);
    while (r->next != NULL && k < i - 1)
    {
        r = r->next;
        k++;
    }
    if (r == NULL)
    {
        printf("ɾ��ʧ�ܣ�\n");
    }
    p = r->next;
    r->next = p->next;
    *e = p->data;
    free(p);
    printf("ɾ���ɹ���\n");
}

//�˳����� 
void  exit_1()
{
    printf("�˳��ɹ����밴�����������");
    exit(0);
}

//��������ң���Ϊ�޸ĵĸ�����
static LNode* SListFind(LNode* plist, char name[])
{
    LNode* cur = plist->next;
    LNode* pos = plist;
    //1.������ֱ�ӷ���
    if (cur == NULL)
    {
        return NULL;
    }

    //��������
    while (cur != NULL)
    {
        //����ҽڵ�ֵ����x�򷵻�
        if (strcmp(cur->data.name, name) == 0)
        {
            return pos;
        }
        //û�ҵ���������
        pos = pos->next;
        cur = cur->next;
    }
    return NULL;
}

//�޸��˵���Ϣ
void ModifySystem(LNode** pplist)//����ModifySystem(&Plist);
{
    assert(*pplist);

    char name[50];
    printf("������Ҫ�޸��˵�����:");
    scanf("%s", name);
    getchar();

    LNode* mod = SListFind(*pplist, name);
    if (NULL == mod)
    {
        printf("Ҫ�޸ĵ��˲�����!\n");
    }
    else
    {
        mod = mod->next;

        printf("����������:>");
        scanf("%s", mod->data.name);
        getchar();
        printf("������ѧ��:>");
        scanf("%s", mod->data.id);
        getchar();
        printf("������ߵ���ѧ�ɼ�:");
        scanf("%s", mod->data.gdsx);//�ߵ���ѧ�ɼ�
        getchar();
        printf("�������ѧӢ��ɼ�:");
        scanf("%s", mod->data.dxyy);//��ѧӢ��ɼ�
        getchar();
        printf("���������ݽṹ���㷨�ɼ�:");
        scanf("%s", mod->data.sjjg);//���ݽṹ���㷨�ɼ�
        getchar();
        printf("�����������ԭ��ɼ���");
        scanf("%s", mod->data.jsj);//��������ԭ��ɼ�
        getchar();
        printf("���������������ͳ�Ƴɼ���");
        scanf("%s", mod->data.gll);//������������ͳ�Ƴɼ�
        getchar();
        printf("�����ѧ����ɼ���");
        scanf("%s", mod->data.dxwl);//��ѧ����ɼ�
        getchar();

        printf("�޸ĳɹ�!\n");
    }
}

void Change(LNode* nest)
{
    char name[50];
    printf("����Ҫ�޸ĵ��˵�����\n");
    scanf("%s", &name);
    getchar();
    LNode* q = nest;
    int p = 1;
    while (p)
    {
        q = q->next;
        if (strcmp(q->data.name, name) == 0)//�ж��Ƿ��ҵ������ֵ���
            p = 0;
        if (q == NULL)
            p = 0;
    }
    if (q == NULL)
    {
        printf("��ѯ����");
    }
    else
    {
        printf("�������֣�");
        scanf("%s", q->data.name);
        getchar();
        printf("����id��");
        scanf("%s", q->data.id);
        getchar();
        printf("����ߵ���ѧ�ɼ���");
        scanf("%s", q->data.gdsx);//�ߵ���ѧ�ɼ�
        getchar();
        printf("�����ѧӢ��ɼ���");
        scanf("%s", q->data.dxyy);//��ѧӢ��ɼ�
        getchar();
        printf("�������ݽṹ���㷨�ɼ���");
        scanf("%s", &q->data.sjjg);//���ݽṹ���㷨�ɼ�
        getchar();
        printf("�����������ԭ��ɼ���");
        scanf("%s", q->data.jsj);//��������ԭ��ɼ�
        getchar();
        printf("���������������ͳ�Ƴɼ���");
        scanf("%s", q->data.gll);//������������ͳ�Ƴɼ�
        getchar();
        printf("�����ѧ����ɼ���");
        scanf("%s", q->data.dxwl);//��ѧ����ɼ�
        getchar();

    }

}


//������ 
void menu()
{
	system("cls");
	printf("********************************************************************\n");
	printf("*      1. ¼��ѧ����Ϣ��                                           *\n");
    printf("*      2. ��ʾѧ��������¼�������ѧ����Ϣ��                       *\n");
    printf("*      3. ͨ��ѧ�Ų�����¼��ѧ����Ϣ��                             *\n");
    printf("*      4. �ڱ���ָ��λ�ò���һ��ѧ����Ϣ��                         *\n");
    printf("*      5. ɾ��ָ��λ�õ�ѧ����Ϣ��                                 *\n");
    printf("*      6. ͨ�������޸�ѧ����Ϣ��                                   *\n");
    printf("*      7. ��ƽ�������ܷ����ѧ����Ϣ��                             *\n");
    printf("*      8. ��ѧ����Ϣ�����ֽܷ�������                             *\n");
    printf("*      9. ��ѧ����Ϣ�����ܷ���������                             *\n");
    printf("*      10. ��ѧ����Ϣ����ѧ�Ž�������                            *\n");
    printf("*      11. ��ѧ����Ϣ����ѧ����������                            *\n");
    printf("*      12. �˳�����                                                *\n");
    printf("********************************************************************\n");
    printf("\n");
    printf("��ѡ����Ҫ������ѡ�");
}
