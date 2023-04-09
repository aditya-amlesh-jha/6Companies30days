class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<vector<int>> adj(colors.size());
        vector<int> visited(colors.size(),0);
        vector<vector<int>> freq(colors.size(), vector<int>(26,0));
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
        }
        int ans = 0;
        for(int i=0;i<colors.size();i++){
            ans = max(ans,dfs(adj,visited,freq,colors,i));
        }
        return ans == INT_MAX?-1:ans;
    }
    int dfs(vector<vector<int>> &edges, vector<int> &visited, vector<vector<int>> &freq, string &colors, int parent){
        if(visited[parent] == 1){
            return INT_MAX;
        }
        else if(visited[parent] == 2){
            return freq[parent][colors[parent]-'a'];
        }
        visited[parent] = 1;
        for(auto x:edges[parent]){
            if(dfs(edges,visited,freq,colors,x) == INT_MAX){
                return INT_MAX;
            }
            for(int i=0;i<26;i++){
                freq[parent][i] = max(freq[parent][i],freq[x][i]);
            }
        }
        freq[parent][colors[parent]-'a']++;
        visited[parent] = 2;
        return freq[parent][colors[parent]-'a'];
    }
};