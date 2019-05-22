class Solution {
public:
  int lenList(ListNode* head) {
    int len = 0;
    while (head->next != NULL) {
      len++;
      head = head->next;
    }
    return len;
  }
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
    int len1 = lenList(headA);
    int len2 = lenList(headB);
    ListNode* shorter = len1 <= len2 ? headA : headB;
    ListNode* longer = len1 > len2 ? headA : headB;
    while (len2 != len1) {
      longer = longer->next;
      len1>len2?len1--:len2--;
    }
    while (shorter != NULL) {
      if (shorter == longer) {
        return shorter;
      }
      else {
        shorter = shorter->next;
        longer = longer->next;
      }
    }
    return NULL;
  }
};
