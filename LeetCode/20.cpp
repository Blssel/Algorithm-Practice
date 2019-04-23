// 简单的栈就可实现   没啥
class Solution {
 public:
   bool isValid(string s) {
     stack<char> stk;
     for (int i = 0; i<s.length(); i++) {
       if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
         if (stk.empty()) return false;
         else {
           char t = stk.top();
           stk.pop();
           char target;
           if (s[i] == ')') target = '(';
           else if (s[i] == ']') target = '[';
           else target = '{';
           if (t == target) continue;
           else return false;
         }
       }
       else {
         stk.push(s[i]);
       }
     }
     if (stk.empty()) return true;
     else return false;
   }
 };
