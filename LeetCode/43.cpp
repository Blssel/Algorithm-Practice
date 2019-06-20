class Solution {
public:
  string sumOf(string str1, string str2) {
    string s = "";
    int carry = 0;
    string s1, s2;
    if (str1.length() < str2.length()) {
      s1 = str1;
      s2 = str2;
    }
    else {
      s1 = str2;
      s2 = str1;
    }
    int index;
    for (index = 0; index < s1.length(); index++) {
      int i = s1.length() - 1 - index;
      int j = s2.length() - 1 - index;
      char tmp[12];
      //itoa(((s1[i] - '0') + (s2[j] - '0') + carry) % 10, tmp, 10);
      int l = sprintf(tmp, "%d", ((s1[i] - '0') + (s2[j] - '0') + carry) % 10);
      s = tmp + s;
      carry = ((s1[i] - '0') + (s2[j] - '0') + carry) / 10;
    }
    for (index = s1.length(); index < s2.length(); index++) {
      int j = s2.length() - 1 - index;
      char tmp[12];
      //itoa(((s2[j] - '0') + carry) % 10, tmp, 10);
      int ll = sprintf(tmp, "%d", ((s2[j] - '0') + carry) % 10);
      s = tmp + s;
      carry = ((s2[j] - '0') + carry) / 10;
    }
    if (carry != 0) {
      char tmp[12];
      //itoa(carry, tmp, 10);
      int lll = sprintf(tmp, "%d", carry);
      s = tmp + s;
    }
    return s;
  }
  string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
    string str1, str2;
    if (num1.length() < num2.length()) {
      str1 = num1;
      str2 = num2;
    }
    else {
      str1 = num2;
      str2 = num1;
    }
    string res = "";
    int num_zero = -1;
    for (int i = str1.length() - 1; i >= 0; i--) {
      num_zero++;
      int carry = 0;
      string intermediate = "";
      for (int j = str2.length() - 1; j >= 0; j--) {
        char tmp[12];
        //itoa(((str1[i] - '0')*(str2[j] - '0') + carry) % 10, tmp, 10);
        int l = sprintf(tmp, "%d", ((str1[i] - '0')*(str2[j] - '0') + carry) % 10);
        intermediate = tmp + intermediate;
        carry = ((str1[i] - '0')*(str2[j] - '0') + carry) / 10;
      }
      if (carry != 0) {
        char tmp[12];
        //itoa(carry, tmp, 10);
        int ll = sprintf(tmp, "%d", carry);
        intermediate = tmp + intermediate;
      }
      //后面补0
      for (int i = 0; i < num_zero; i++) {
        intermediate = intermediate + "0";
      }
      //并入结果中
      res = sumOf(res, intermediate);
    }
    return res;
  }
};
