class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
        if(n==0) {
            digits.push_back(1); 
            return digits;
        }
    int carry = 0;

    int tmp = ((digits[n-1] + 1) + carry) % 10;
    carry = (digits[n - 1] + 1) / 10;
    digits[n - 1] = tmp;

    for (int i = digits.size() - 2; i > 0; i--) {
      tmp = (digits[i]  + carry) % 10;
      carry = (digits[i] + carry) / 10;
      digits[i] = tmp;
    }
    if (n >= 2) {
      tmp = (digits[0] +carry) % 10;
      carry = (digits[0] + carry) / 10;
      digits[0] = tmp;
    }
    if (carry != 0) {
      digits.insert(digits.begin(), carry);
    }

    return digits;
  }
};
