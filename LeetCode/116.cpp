/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
  Node* connect(Node* root) {
        if(root==NULL) return root;
    Node* first;
    Node* cur = root;
    while (true) {
      bool isfirst = true;
      Node* last = NULL;
      while(cur!=NULL){
        if (last != NULL) {
                    if(last->right!=NULL)
              last->right -> next = cur->left;
        }
                last = cur;
        if (isfirst) {
          first = cur->left;
          isfirst = false;
        }

                if(cur->left!=NULL)
            cur->left->next = cur->right;
        cur = cur->next;
      }
      if (first == NULL) break;
      cur = first;
    }
        return root;
  }
};
