struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == NULL) return res;

    stack<TreeNode*> q;
    stack<TreeNode*> s;
    int flag = 0; //使用栈
    q.push(root);
    while (true) {
      vector<int> ele;
      if (flag == 0) {
        while (!q.empty()) {
          TreeNode* cur = q.top();
          q.pop();
          if (cur == NULL) continue;
          ele.push_back(cur->val);
          s.push(cur -> left);
          s.push(cur -> right);
        }
        flag = 1;
      }
      else {
        while (!s.empty()) {
          TreeNode* cur = s.top();
          s.pop();
          if (cur == NULL) continue;
          ele.push_back(cur->val);
          q.push(cur->right);
          q.push(cur->left);
        }
        flag = 0;
      }
      res.push_back(ele);
      if (q.empty() && s.empty())
        break;
    }
    return res;
    
  }
};
