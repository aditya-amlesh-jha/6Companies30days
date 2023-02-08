class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),INT_MAX);
        dp[0] = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<min(nums.size(),nums[i]+i*1ul+1ul);j++){
                dp[j] = min(dp[j],1+dp[i]);
            }
        }
        return dp[nums.size()-1];
    }
};