#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //can be solved by dikstra algorithm
        //need to revise dikstra algorithm
        
        
        //adjacency list (V+E)
        vector<vector<pair<ll,ll>>> edge(n);
        for(auto i:roads){
            edge[i[0]].push_back(make_pair(i[1],i[2]));
            edge[i[1]].push_back(make_pair(i[0],i[2]));
        }
        
        return dikstra(edge,n);
        
    }
    
    int dikstra(vector<vector<pair<ll,ll>>> &edge, int n){
        
        vector<ll> distance(n,LONG_MAX);
        distance[0] = 0;
        
        //min pq for getting shortest distance
        //first: distance, second:vertex
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        pq.push(make_pair(0,0));
        
        //now tweak
        //store count for each minimum path
        
        vector<ll> count(n,0);
        count[0] = 1;
        
        while(!pq.empty()){
            int vertex = pq.top().second;
            ll dist = pq.top().first;
            pq.pop();
            
            if(dist > distance[vertex]){
                continue;
            }
            
            for(int i=0;i<edge[vertex].size();i++){
                ll temp_distance = edge[vertex][i].second+dist;
                if(temp_distance < distance[edge[vertex][i].first]){
                    distance[edge[vertex][i].first] = temp_distance;
                    pq.push(make_pair(temp_distance,edge[vertex][i].first));
                    count[edge[vertex][i].first] = count[vertex];
                }
                else if(temp_distance == distance[edge[vertex][i].first]){
                    count[edge[vertex][i].first] = (count[vertex]+count[edge[vertex][i].first])%1000000007;
                }
            }
        }
        
        return count[n-1];
    }
};