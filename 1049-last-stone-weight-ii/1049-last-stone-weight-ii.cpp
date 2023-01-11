class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //hints
        //0-1 knapsack
        //find subset with sum <= n/2
        // int sum = accumulate(stones.begin(),stones.end());
        
        int sum = 0;
        for(auto i:stones){
            sum+=i;
        }
        
        vector<vector<int>> dp(stones.size()+1, vector<int>(sum/2+1));
        
        for(int i=1;i<=stones.size();i++){
            for(int j=0;j<=sum/2;j++){
                if(stones[i-1]<=j){
                    dp[i][j] = max(dp[i-1][j],stones[i-1]+dp[i-1][j-stones[i-1]]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return sum-2*dp[stones.size()][sum/2];
    }
};
