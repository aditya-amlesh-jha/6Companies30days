class Solution {
    vector<int> ans;
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),-1),temp;
        find(nums,dp,temp,0,1);
        return ans;
    }
    void find(vector<int> &nums, vector<int> &dp, vector<int> &temp, int curr, int prev){
        if(curr >= nums.size()){
            if(temp.size() > ans.size()){
                ans = temp;
            }
            return;
        }
        
        if((int)temp.size()>dp[curr] && nums[curr]%prev==0){
            dp[curr] = temp.size();
            temp.push_back(nums[curr]);
            find(nums,dp,temp,curr+1,nums[curr]);
            temp.pop_back();
        }
        find(nums,dp,temp,curr+1,prev);
    }
};