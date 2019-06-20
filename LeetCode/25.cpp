class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1||head==NULL||head->next==NULL) {
      return head;
    }
    ListNode* first = new ListNode(0);  //新建一个首结点
    first->next = head;
    ListNode *begin, *end, *pre = first;
    while (true) {
      if (pre->next == NULL) {
        return first->next;
      }
      begin = pre->next;
      end = begin;
      for (int i = 0; i < k - 1; i++) {
        end = end->next;
        if (end == NULL) {
          return first->next;
        }
      }
      // 翻转
      ListNode* cur = begin;
      ListNode* next = begin->next;
      ListNode* next_next = next->next;
      while (true) {
        if (cur == end) {
          break;
        }
        else {
          next->next = cur;
          cur = next;
          next = next_next;
          if (next != NULL) {
            next_next = next->next;
          }
        }
      }
      pre->next = end;
      begin->next = next;
      pre = begin;
    }
  }
};
