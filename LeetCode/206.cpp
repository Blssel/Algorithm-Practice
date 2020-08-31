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
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> s;
        ListNode* p=head;
        while(p!=NULL){
            s.push(p);
            p = p->next;
        }
        ListNode* begin = NULL;
        if(!s.empty()){
            begin = s.top();
            s.pop();
        }
        ListNode* node1 = begin;
        while(!s.empty()){
            ListNode node2 = s.top();
            s.pop();
            node1->next = node2;
            node1 = node2;
        }
        if(node1!=NULL)
            node1->next = NULL;

        return begin;
    }
};

// 尝试递归解法
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
    ListNode* reverseList(ListNode* head) {
        
    }
};



// 以上解法空间复杂度为n，不好，
