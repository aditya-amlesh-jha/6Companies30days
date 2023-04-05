class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());
        int ans = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isPossible(nums,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    bool isPossible(vector<int> &nums, int val){
        long sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            long temp = 1l*val*(i+1);
            if(sum > temp){
                return false;
            }
        }
        return true;
    }
};