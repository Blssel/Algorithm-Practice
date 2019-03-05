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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = NULL;
        ListNode* tail = NULL;
        bool isFirst = true; //标记是否是第一个，方便为头指针赋值
        
        // if(lists.size() == 0) return res;
        while(true){
            bool isEnd = true;
            int minValue = INT_MAX;
            int minIndex = -1;
            for(int i=0;i<lists.size();i++){
                isEnd = !((!isEnd) || (lists[i]!=NULL));
                if(lists[i]!=NULL && lists[i]->val < minValue){
                    minValue = lists[i]->val;
                    minIndex = i;
                }
            }
            if(isEnd){
                printf("33333");
                break;   
            }

            if(isFirst){
                printf("11111");
                ListNode* node = new ListNode(lists[minIndex]->val);
                res = node;
                tail = node;
                isFirst = false;
            }else{ //尾插
                printf("22222");
                ListNode* node = new ListNode(lists[minIndex]->val);
                tail->next = node;
                tail = node;
            }
            lists[minIndex] = lists[minIndex]->next ;// 将选出来的那个链表指针往后移动一个
        }
        //tail->next = NULL;
        return res;
    }
};

