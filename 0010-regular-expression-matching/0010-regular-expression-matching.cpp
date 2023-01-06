class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.size()+1,vector<bool>(s.size()+1,false));
        for(int i=0;i<=p.size();i++){
            for(int j=0;j<=s.size();j++){
                if(i==0 && j==0){
                    dp[i][j] = 1;
                }
                else if(j==0){
                    dp[i][j] = (p[i-1]=='*')?dp[i-2][j]:0;
                }
                else if(i==0){
                    dp[i][j] = 0;
                }
                else if(p[i-1] == s[j-1] || p[i-1]=='.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1]=='*'){
                    dp[i][j] = dp[i-2][j];
                    dp[i][j] = (p[i-2]=='.' || p[i-2]==s[j-1])?dp[i][j] || dp[i][j-1]:dp[i][j];
                }
            }
        }
        return dp[p.size()][s.size()];
    }
};