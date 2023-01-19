class Solution {
public:
    int numSquares(int n) {
        unordered_set<int> square;
        for(int i=1;i<=ceil(sqrt(n));i++){
            square.insert(i*i);
        }
        //minimum no to sum upto k;
        vector<int> dp(n+1,-1);
        return ans(dp,square,n);
    }
    int ans(vector<int> &dp, unordered_set<int> &square, int sum){
        if(sum < 0){
            return 9999;
        }
        if(sum == 0){
            return 0;
        }
        if(dp[sum]!=-1){
            return dp[sum];
        }
        int factor = 9999;
        for(auto i:square){
            if(i<=sum){
                factor = min(factor,1+ans(dp,square,sum-i));
            }
        }
        return dp[sum] = factor;
    }
};