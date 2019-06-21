class Solution {
public:
  void reorderList(ListNode* head) {
    vector<ListNode*> pointers;
    ListNode* p = head;
    while (p != NULL) {
      pointers.push_back(p);
      p = p->next;
    }
    if (pointers.size() <= 2) {
      return;
    }
    ListNode *cur, *next, *last, *pre;
    for (int i = 0; i < (pointers.size() - 1) / 2; i++) {
      cur = pointers[i];
      next = cur->next;
      last = pointers[pointers.size() - 1 - i];
      pre = pointers[pointers.size() - 2 - i];

      cur->next = last;
      last->next = next;
      pre->next = NULL;
    }
  }
};
