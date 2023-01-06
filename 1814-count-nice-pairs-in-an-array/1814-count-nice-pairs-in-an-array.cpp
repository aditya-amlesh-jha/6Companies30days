class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        //create a map
        //count[sum]++ for each sum
        //now iterate through each sum
        //and pair possible are count[sum]*(count[sum]-1)/2;
        unordered_map<int,int> map;
        int ans = 0;
        for(auto x:nums){
            map[x-reverse(x)]++;
        }
        
        for(auto [x,y]:map){
            cout<<y<<endl;
            long long temp = ((1ll*y*(y-1))/2)%1000000007;
            ans = (ans+temp)%1000000007;
        }
        
        return ans;
    }
    int reverse(int n){
        int r = 0;
        while(n){
            r = r*10+n%10;
            n = n/10;
        }
        return r;
    }
};