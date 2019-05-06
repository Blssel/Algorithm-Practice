class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> m;
    for (int i = 0; i < strs.size(); i++) {
      string str = strs[i]; //类似深拷贝，原数组不受影响
      sort(str.begin(), str.end());
      if (m.find(str) != m.end()) {
        m[str].push_back(strs[i]);
      }
      else {
        vector<string> v;
        v.push_back(strs[i]);
        m[str] = v;
      }
    }
    vector<vector<string>> res;
    for (map<string, vector<string>>::iterator ite = m.begin(); ite != m.end(); ite++) {
      res.push_back(ite->second);
    }
    return res;
  }
};

