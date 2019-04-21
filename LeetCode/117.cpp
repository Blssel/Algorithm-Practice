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
    if (root == NULL) return root;
    Node* cur = root;
    while (true) {
            Node* first=NULL;
      bool isfirst = true;
      Node* last = NULL;
      while (cur != NULL) {
                cout<<cur->val<<endl;
                if(cur->next!=NULL)
                    cout<<cur->next->val<<endl;
        if (last != NULL) {
          if (last->right != NULL) {
            if (cur->left != NULL) {
              last->right->next = cur->left;
            }
            else if (cur->right != NULL) {
              last->right->next = cur->right;
            }
          }
          else if (last->left != NULL) {
            if (cur->left != NULL) {
              last->left->next = cur->left;
            }
            else if (cur -> right != NULL) {
              last->left->next = cur->right;
            }
          }
            
        }
                
        if (isfirst) {
          if (cur->left != NULL) {
            first = cur->left;
            isfirst = false;
          }
          else if(cur->right != NULL) {
            first = cur->right;
            isfirst = false;
          }
          
        }

        if (cur->left != NULL && cur->right != NULL)
          cur->left->next = cur->right;
                if(cur->left!=NULL||cur->right!=NULL)
            last = cur;
        cur = cur->next;
      }
      if (first == NULL) break;
      cur = first;
    }
    return root;
  }
};
