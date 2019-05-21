class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res;
        if(s.length()<10){
            return res; 
        } 
    map<string, int> m;
    for (int i = 0; i <= s.length()-10; i++) {
      string sub = s.substr(i, 10);
      if (m.find(sub) != m.end()) {  // exist
        m[sub]++;
      }
      else {
        m[sub] = 1;
      }
    }
    for (map<string, int>::iterator ite = m.begin(); ite != m.end(); ite++) {
      if (ite->second > 1) {
        res.push_back(ite->first);
      }
    }
    return res;
  }
};
