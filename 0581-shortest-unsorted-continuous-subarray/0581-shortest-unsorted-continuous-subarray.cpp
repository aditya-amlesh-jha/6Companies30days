class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy = nums;
        sort(copy.begin(),copy.end());
        
        int i = 0, j = nums.size()-1;
        while(i<nums.size()){
            if(nums[i]==copy[i]){
                i++;
            }
            else{
                break;
            }
        }
        while(j>=0){
            if(nums[j]==copy[j]){
                j--;
            }
            else{
                break;
            }
        }
        
        if((i==nums.size() && j==-1)){
            return 0;
        }
        

        return j-i+1;
    }
};