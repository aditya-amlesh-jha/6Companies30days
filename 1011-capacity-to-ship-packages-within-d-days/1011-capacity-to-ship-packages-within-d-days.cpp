class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int total_weight = accumulate(weights.begin(),weights.end(),0);
        int min_weight = max(total_weight/days,*max_element(weights.begin(),weights.end()));
        return binarySearch(weights, min_weight, total_weight, days);
    }
    int binarySearch(vector<int> &weights, int low, int high, int day){
        int ans = INT_MAX;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isPossible(weights,mid) <= day){
                ans = min(ans,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    int isPossible(vector<int> &weights, int weight){
        int sum = 0, count = 1;
        
        for(auto i:weights){
            sum+=i;
            if(sum > weight){
                sum = i;
                count++;
            }
        }
        
        return count;
    }
};