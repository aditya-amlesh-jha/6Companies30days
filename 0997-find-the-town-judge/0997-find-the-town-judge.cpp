class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,int>> dp(n,{0,0});
        //first : trusted by other person
        //second : trusts other person
        for(auto i:trust){
            dp[i[0]-1].second += 1;
            dp[i[1]-1].first +=1;
        }
        for(int i=0;i<dp.size();i++){
            if(dp[i].first==n-1 && dp[i].second==0){
                return i+1;
            }
        }
        return -1;
    }
};