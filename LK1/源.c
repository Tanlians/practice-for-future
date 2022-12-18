#include<stdio.h>
//Definition for singly-linked list.
typedef struct Lnode {
    int val;
    struct Lnode* next;
}Lnode;



struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    Lnode* sum = (Lnode*)malloc(sizeof(Lnode));
    sum->val = 0; sum->next = NULL;
    Lnode* p = sum;

    int carry = 0; //��λ
    for (; l1 != NULL && l2 != NULL; l1 = l1->next, l2 = l2->next) {
        int res = l1->val + l2->val + carry;
        p->val = res % 10;

        p->next = (Lnode*)malloc(sizeof(Lnode));
        p = p->next; //β����ڵ�
        p->next = NULL;

        carry = (res > 9) ? 1 : 0;
    }

    //һ�������Ѿ���ͷ����ʼ���Ž�λ������������һ��
    Lnode* longerList = (l1 != NULL) ? l1 : l2;
    for (; longerList != NULL; longerList = longerList->next) {
        int res = longerList->val + carry;
        p->val = res % 10;

        p->next = (Lnode*)malloc(sizeof(Lnode));
        p = p->next;
        p->next = NULL;

        carry = (res > 9) ? 1 : 0;
    }

    if (carry == 1) {
        p->val = 1;
        p->next = NULL;
    }

    //��λΪ0������������ɾ�����һ���ڵ�
    else {
        Lnode* rear = sum;
        //���ڻ���β�����벹��ڵ㣬���Բ������ֻ��һ���ڵ�����
        while (rear->next->next != NULL)
            rear = rear->next;
        free(rear->next);
        rear->next = NULL;
    }
    return sum;
}

