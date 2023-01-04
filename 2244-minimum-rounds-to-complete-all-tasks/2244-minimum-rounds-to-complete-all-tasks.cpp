class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        vector<int> dp(tasks.size()+1,-1);
        
        unordered_map<int,int> count;
        for(auto i:tasks){
            count[i]++;
        }
        
        int round = 0;
        for(auto [x,y]:count){
            int k = cal(dp,y);
            if(k >= tasks.size()){
                return -1;
            }
            else{
                round+=k;
            }
        }
        
        return round;
    }
    int cal(vector<int> &dp, int size){
        if(size==0){
            return 0;
        }
        if(size==2 || size==3){
            return 1;
        }
        if(size == 1 || size<0){
            return dp.size();
        } 
        if(dp[size]!=-1){
            return dp[size];
        }
        return dp[size] = 1+min(cal(dp,size-2),cal(dp,size-3));
    }
    
};