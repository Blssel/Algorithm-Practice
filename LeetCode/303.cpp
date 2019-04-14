class NumArray {
vector<int> m_nums;
public:
    NumArray(vector<int>& nums) {
        m_nums = nums;
    }
    
    int sumRange(int i, int j) {
        int res=0;
        for(int x=i;x<=j;x++){
            res += m_nums[x];
        }
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
