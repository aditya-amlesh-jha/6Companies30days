class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int tmax,tmin,cmax,cmin,tt;
        tmax = tmin = cmax = cmin = tt =  nums[0];
        for(int i=1;i<nums.size();i++){
            int a = nums[i];
            cmax = max(cmax+a,a);
            tmax = max(tmax,cmax);
            cmin = min(cmin+a,a);
            tmin = min(tmin,cmin);
            tt += nums[i];
        }
        return tmax<=0?tmax:max(tmax,tt-tmin);
    }
};