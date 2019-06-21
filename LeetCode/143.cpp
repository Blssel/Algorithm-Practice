class Solution {
public:
  void reorderList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
      return;
    }
    ListNode *fast = head, *slow = head;  //快慢指针，快的走两步，慢的走一步，最终慢的指向中间
    while (fast->next&&fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode *first = head, *second = slow->next;
    slow->next = NULL;  //分为两个链表 first和second
    
    //反转第二个链表
    ListNode *cur=second, *pre=NULL, *next=cur->next;
    while (cur) {
      cur->next = pre;
      if (next == NULL) {
        second = cur;
        break;
      }
      pre = cur;
      cur = next;
      next = next->next;
    }
    //逐个插入
    head = first;
    ListNode *tmp;
    while (second != NULL) {
      tmp = first->next;
      first->next = second;
      second = second->next;
      first->next->next = tmp;
      first = first->next->next;
    }
  }
};

