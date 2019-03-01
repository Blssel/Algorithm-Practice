class Solution {
public:
    int maxArea(vector<int>& height) {
        int p=0,q=height.size()-1;
        int res=0;
        while(q-p>=1){
            res = max(res, (q-p)*min(height[p],height[q]));
        }
        if(height[p]<height[q])
            p++;
        else
            q++;
        return res;
    }
};



/*
// 该方法复杂度过高
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0;
        for(int i=0;i<height.size()-1;i++){
            for(int j=i+1;j<height.size;j++){
                int aera = (j-i)*min(height[i],height[j]);
                if aera>res
                    res = aera;
            }
        }
        return res;
    }
};
/*
