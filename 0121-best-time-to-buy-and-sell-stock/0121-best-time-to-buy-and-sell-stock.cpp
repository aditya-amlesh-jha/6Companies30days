class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = INT_MIN;
        int profit = INT_MIN;
        
        for(int i=prices.size()-1;i>=0;i--){
            k = max(k,prices[i]);
            profit = max(profit,k-prices[i]);
        }
        return profit;
    }
};