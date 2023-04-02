class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            spells[i] = binarySearch(potions,spells[i],success);
        }
        return spells;
    }
    int binarySearch(vector<int> &nums, int element, long long limit){
        int low = 0, high = nums.size()-1;
        int ans = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            long long k = 1ll*element*nums[mid];
            if(k>=limit){
                ans = nums.size() - mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};