/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* p=head;
        int len=0;
        while(p!=NULL){
            len++;
            p = p->next;
        }
        if(len<=1 || k==0) return head;
        int kValid = k%len;
        if(kValid==0) return head;

        ListNode* joint=head, *tail, *res;
        for(int i=1;i<(len-kValid);i++){
            joint = joint->next;
        }
        tail = joint;
        for(int i=1;i<=kValid;i++){
            tail = tail->next;
        }

        res = joint->next;
        joint->next = tail->next;
        tail->next = head;

        return res;
    }
};

