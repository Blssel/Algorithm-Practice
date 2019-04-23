/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 只用一遍遍历方法https://www.cnblogs.com/grandyang/p/4606920.html
class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* target = head, *p = head;
    for (int i = 1; i <= n; i++) {
      p = p->next;
    }
    if (p == NULL) {
      return head->next;;
    }
    else {
      while (p->next != NULL) {
        p = p->next;
        target = target->next;
      }
      target->next = target->next->next;
      return head;
    }
  }
};
