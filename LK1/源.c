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

    int carry = 0; //进位
    for (; l1 != NULL && l2 != NULL; l1 = l1->next, l2 = l2->next) {
        int res = l1->val + l2->val + carry;
        p->val = res % 10;

        p->next = (Lnode*)malloc(sizeof(Lnode));
        p = p->next; //尾补充节点
        p->next = NULL;

        carry = (res > 9) ? 1 : 0;
    }

    //一个链表已经到头，开始带着进位继续遍历另外一个
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

    //进位为0，遍历和链表，删除最后一个节点
    else {
        Lnode* rear = sum;
        //由于会在尾部插入补充节点，所以不会出现只有一个节点的情况
        while (rear->next->next != NULL)
            rear = rear->next;
        free(rear->next);
        rear->next = NULL;
    }
    return sum;
}

