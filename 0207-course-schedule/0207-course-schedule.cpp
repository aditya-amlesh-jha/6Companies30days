class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edge(numCourses);
        for(auto x:prerequisites){
            edge[x[1]].push_back(x[0]);
        }
        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0 && dfs(edge,visited,i)==false){
                return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<int>> &edge, vector<int> &visited, int parent){
        if(visited[parent]!=0){
            return visited[parent] == 1;
        }
        visited[parent] = 2;
        for(auto x:edge[parent]){
            if(!dfs(edge,visited,x)){
                return false;
            }
        }
        visited[parent] = 1;
        return true;
    }
};