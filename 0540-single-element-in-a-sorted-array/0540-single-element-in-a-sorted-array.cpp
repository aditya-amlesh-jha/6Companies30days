class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while(low<high){
            int mid = low+(high-low)/2;
            if((mid%2==0 && nums[mid+1]==nums[mid]) || (mid%2==1 && nums[mid-1]==nums[mid])){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return nums[low];
    }
};