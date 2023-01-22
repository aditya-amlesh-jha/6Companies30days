class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        vector<vector<string>> ans;
        for(int i=0;i<s.size();i++){
            dp[i][i] = true;
        }
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i+1;j<s.size();j++){
                if(s[i]==s[j] &&(j-i==1 || dp[i+1][j-1])){
                    dp[i][j] = true;
                }
            }
        }
        vector<string> temp;
        find(dp,ans,temp,s,0);
        return ans;
    }
    void find(vector<vector<bool>> &dp, vector<vector<string>> &ans, vector<string> &temp,string &s, int index){
        if(index==s.size()){
            ans.push_back(temp);
        }
        for(int i=index;i<s.size();i++){
            if(dp[index][i] == true){
                temp.push_back(s.substr(index,i-index+1));
                find(dp,ans,temp,s,i+1);
                temp.pop_back();
            }
        }
    }
};