class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> ageScore;
        for(int i=0;i<ages.size();i++){
            ageScore.push_back(make_pair(ages[i],scores[i]));
        }
        sort(ageScore.begin(),ageScore.end(),greater<>());
        
        int ans = 0;
        vector<int> dp(ages.size(),0);
        for(int i=0;i<ageScore.size();i++){
            dp[i] = ageScore[i].second;
            for(int j=0;j<i;j++){
                if(ageScore[j].second >= ageScore[i].second){
                    dp[i] = max(dp[i],dp[j]+ageScore[i].second);
                }
            }
            ans = max(dp[i],ans);
        }
        return ans;
    }
};