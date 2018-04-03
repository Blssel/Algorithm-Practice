// 2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
//本程序中的结构体名，在LeetCode中必须加上struct，否则编译错误

struct ListNode {
  int val;
  struct ListNode *next;
};
//尾插法
void tailInsert(struct ListNode* tail, struct ListNode* node) {
  tail->next = node;
  tail = node;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  ListNode* sum; //使用头结点
  sum = (ListNode*)malloc(sizeof(ListNode));
  sum->next = NULL;
  ListNode* tail = sum; //尾节点
  int carry = 0;
  while (l1 != NULL && l2 != NULL) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));//先分配出一个节点
    node->next = NULL;
    //计算
    node->val = ((l1->val + l2->val) +carry) % 10;
    carry = (l1->val + l2->val+carry) / 10;
    //尾插
    tailInsert(tail, node);
    tail = node;
    //free(node);
    l1 = l1->next;
    l2 = l2->next;
  }

  while (l1 != NULL) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));//配出一个节点
    node->next = NULL;
    node->val = (l1->val + carry)%10;
    carry = (l1->val + carry) / 10;
    tailInsert(tail, node);
    tail = node;
    //free(node);
    l1 = l1->next;
  }

  while (l2 != NULL) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));//配出一个节点
    node->next = NULL;
    node->val = (l2->val + carry)%10;
    carry = (l2->val + carry) / 10;
    tailInsert(tail, node);
    tail = node;
    //free(node);
    l2 = l2->next;
  }
  if (carry != 0) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));//配出一个节点
    node->next = NULL;
    node->val = carry;
    tailInsert(tail, node);
    tail = node;
  }
 // printf("%d %d", sum->val,tail->val);
  return sum->next;
}


int main()
{
  ListNode* l1 = (ListNode*)malloc(sizeof(ListNode));
  l1->val = 2;
  ListNode* l11 = (ListNode*)malloc(sizeof(ListNode));
  l11->val = 4;
  ListNode* l111 = (ListNode*)malloc(sizeof(ListNode));
  l111->val = 3;
  l111->next = NULL;
  l1->next = l11;
  l11->next = l111;

  ListNode* l2 = (ListNode*)malloc(sizeof(ListNode));
  l2->val = 5;
  ListNode* l22 = (ListNode*)malloc(sizeof(ListNode));
  l22->val = 6;
  ListNode* l222 = (ListNode*)malloc(sizeof(ListNode));
  l222->val = 4;
  l222->next = NULL;
  l2->next = l22;
  l22->next = l222;

  ListNode* s = addTwoNumbers(l1, l2);
  s = s->next;
  while (s != NULL) {
    printf("%d\n", s->val);
    s = s->next;
  }
  return 0;
}