class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
    int i=0,j=numbers.size()-1;
    while(1){
      if(numbers[i]+numbers[j] == target){
        res.push_back(i+1);
        res.push_back(j+1);
        return res;
      }else if(numbers[i]+numbers[j] < target){
        i++;
        continue;
      }else{
        j--;
        continue;
      }
    }
    }
};


// 二分法 time limit exceeded
/*class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        for(int i=0;i<numbers.size();i++){
          int l=i+1,r=numbers.size(),mid;
        while(l<=r){
        mid = (l+r)/2;
                if(numbers[i]+numbers[mid] == target){
                    res.push_back(i+1);
                    res.push_back(mid+1);
                    return res;
                }else{
                    l=mid-1;
                }
            }
        }
        return res;
    }
};*/
