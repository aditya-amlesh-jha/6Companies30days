class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        // for(int i=0;i<nums.size();i++){
        //     int sum = 0;
//         here we are doing overlapping caluculations
//         so we can use prefix sum technique to reduce the redundant calclations
        //     for(int j=i;j<nums.size();j++){
        //         sum+=nums[j];
        //         if(sum%k == 0){
        //             ans++;
        //         }
        //     }
        // }
        
        unordered_map<int,int> map;
        //this indicates that we have 1 subarray with sum = 0;
        map[0] = 1;
        
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            //first we are adding the current to the sum
            sum = (sum+nums[i])%k;
            //if the sum is lesser than 0, then mod is also negative
            //but let's say we have sum = -2, then we need 3 as 3-(-2) for it to be divisible by 5
            if(sum < 0){
                sum += k;
            }
            //updating the ans
            //we have seen this many subarrays of sum sum
            ans+=map[sum];
            //we are incrementing it;
            map[sum]++;
        }
        
        return ans;
    }
};