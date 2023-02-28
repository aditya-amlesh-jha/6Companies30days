class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int i=0,j=n;
        bool flag = true;
        while(i<n || j<nums.size()){
            if(flag){
                ans.push_back(nums[i++]);
            }
            else{
                ans.push_back(nums[j++]);
            }
            flag = !flag;
        }
        return ans;
    }
};