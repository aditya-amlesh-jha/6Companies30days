class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> edge(n);
        for(auto x:edges){
            edge[x[0]].push_back(x[1]);
            edge[x[1]].push_back(x[0]);
        }
        
        vector<bool> visited(n,false);
        
        long long ans = ((1ll*n)*(1ll*n-1ll))/2; 
        
        for(int i=0;i<n;i++){
            if(visited[i] == false){
                long long count = 0;
                dfs(edge,visited,i,count);
                
                ans -= (count*(count-1))/2;
                
            }
        }
        
        

        return ans;
        
    }
    void dfs(vector<vector<int>> &e, vector<bool> &visited, int parent, long long &count){
        if(visited[parent] == true){
            return;
        }
        count++;
        visited[parent] = 1;
        for(auto x:e[parent]){
            dfs(e,visited,x,count);
        }
    }
};