class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> edges(n);
        for(auto i:flights){
            edges[i[0]].push_back(make_pair(i[1],i[2]));
        }
        return dikstra(edges,src,dst,k);
    }
    int dikstra(vector<vector<pair<int,int>>> &edges, int src, int dest, int k){
        
        vector<int> distance(edges.size(),INT_MAX);
        distance[src] = 0;
        priority_queue<vector<int>> pendingNodes;
        pendingNodes.push({distance[src],src,k+1});
        
        int ans = INT_MAX;
        
        while(pendingNodes.size()){
            int parent = pendingNodes.top()[1];
            int dParent = pendingNodes.top()[0];
            int steps = pendingNodes.top()[2];
            pendingNodes.pop();
            
            if(steps > 0){
                for(int j=0;j<edges[parent].size();j++){
                    int child = edges[parent][j].first;
                    int dChild = edges[parent][j].second;
                    if(dParent+dChild < distance[child]){
                        distance[child] = dParent+dChild;
                        pendingNodes.push({distance[child],child,steps-1});
                    }
                    
                    if(dest==child){
                        ans = min(ans,distance[child]);
                    }
                    
                }
            }
        }
        
        return ans == INT_MAX?-1:ans;
    }
    
};