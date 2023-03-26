class Solution {
public:
    int longestCycle(vector<int>& edges) {
        vector<bool> visited(edges.size(),0);
        int ans = -1;
        for(int i=0;i<edges.size();i++){
            if(visited[i] == false){
                unordered_map<int,int> map;
                int dist = 0;
                for(int j=i;j!=-1;j=edges[j]){
                    if(map.count(j)){
                        ans = max(ans,dist-map[j]);
                        break;
                    }
                    if(visited[j] == 1){
                        break;
                    }
                    visited[j] = 1;
                    map[j] = dist++;
                }
            }
        }
        return ans;
    }
};