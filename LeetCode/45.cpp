// 自己想的方法，类似于层序遍历，从最后一个开始，不断寻找有能力达到目的地的点，
// 从可以直接达到的（即步数为1）开始，否则，其它点将通过这些点间接到达
// 注意防止重复计算
// 只faster than 31.03%的C++ submissions
class Solution {
public:
    int jump(vector<int>& nums) {
        struct node{
            int index;
            int layer;
            node(int x,int y): index(x),layer(y){};
        };
        
        queue<node*> q;
        int len = nums.size();
        int dp[len];
        for(int i=0;i<len;i++)
            dp[i] = INT_MAX;
        q.push(new node(len-1, 0));
        while(!q.empty()){
            node* n = q.front();
            q.pop();
            for(int i=0;i<n->index;i++){
                if(nums[i]>=(n->index-i)){
                    if(dp[i]<=n->layer+1) continue;
                    if(i==0) return n->layer+1;
                    q.push(new node(i,n->layer+1));
                    dp[i] = n->layer+1;
                }
            }
        }
        return 0;
    }
};

