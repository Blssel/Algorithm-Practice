class Solution {
public:
    void dfs(vector<vector<int>>& adj, bool* visited,int n, int i, bool& res){
        if(visited[i]){
            res = false;
            return;
        }else{
            visited[i] = true;
            for(int j=0;j<n;j++){
                if(!visited[j]){
                    dfs(adj,visited,n,j,res);
                }
            }
        }
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int numPairs = prerequisites.size();
        int adj[numCourses][numCourses];
        int n=0;
        for(int i=0;i<numCourses;i++){
            adj[prerequisites[i].first][prerequisites[i].second] = 1;
        }

        vector<vector<int>> a;
        for(int i=0;i<numCourses;i++){
            vector<int> b;
            a.push_back(b);
            for(int j=0;j<numCourses;j++){
                 a[i].push_back(adj[i][j]);
            }
        }
        
        bool visited[numCourses+1];
        for(int i=0;i<numCourses;i++){
            visited[i] = false;
        }

        bool res = true;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                dfs(a,visited,numCourses,i,res);
            }
        }
        return res;
        
    }
};

