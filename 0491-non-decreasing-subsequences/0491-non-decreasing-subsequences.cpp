class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        find(ans,temp,nums,0);
        return ans;
        
    }
    void find(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int index){
        if(temp.size() >= 2){
            ans.push_back(temp);
        }
        unordered_set<int> set;
        for(int i=index;i<nums.size();i++) {
            if((temp.empty() || nums[i] >= temp.back()) && set.find(nums[i]) == set.end()) {
                temp.push_back(nums[i]);
                find(ans, temp, nums, i + 1);
                temp.pop_back();
                set.insert(nums[i]);
            }
        }
        
    }
};