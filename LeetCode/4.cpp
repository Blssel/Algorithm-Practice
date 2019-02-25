class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums[nums1.size()+nums2.size()];
        int i=0,j=0,k=0;
        while(i!=nums1.size() && j!=nums2.size()){
            if(nums1[i]<nums2[j]){
                num[k]=nums1[i];
                i++;
            }else{
                nums[k]=nums2[j];
                j++;
            }
            k++;
        }
        if(i==nums1.size()){
            for(int m=j; m<nums2.size; m++){
                nums[k] = nums2[m];
                k++;
            }
        }else{
            for(int n=i; n<nums1.size; n++){
                nums[k] = nums1[n];
                k++;
            }
        }
        
        float res;
        int mid = (nums1.size()+nums2.size())/2;
        if((nums1.size()+nums2.size())%2==0){ //偶数
            res = (float(nums1[mid-1]) + float(nums2[mid])) / 2.0;
        }else{
            res = float(nums2[mid]) / 2.0;
        }
        return res;

    }
};
