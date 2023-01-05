class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //overlapping intervals problem
        
        sort(points.begin(),points.end());
        int end = INT_MAX;
        int count = 1;
        for(auto i:points){
            if(end>=i[0]){
                end = min(end,i[1]);
            }
            else{
                count++;
                end = i[1];
            }
        }
        return count;
    }
};