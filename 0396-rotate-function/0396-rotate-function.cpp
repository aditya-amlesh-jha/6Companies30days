class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        //derive formula
        //f(n+1) = f(n)+sum-size*nums[last*index];
        
        int initial_sum = 0;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            initial_sum += i*nums[i];
            sum+=nums[i];
        }
        int ans = initial_sum;
        for(int i=nums.size()-1;i>=0;i--){
            initial_sum = initial_sum +sum - nums.size()*nums[i];
            ans = max(initial_sum,ans);
        }
        return ans;
    }
};