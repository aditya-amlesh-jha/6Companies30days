class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> map(26);
        for(auto i:ideas){
            map[i[0]-'a'].insert(i.substr(1));
        }
        long long ans = 0;
        for(int i=0;i<26;i++){
            // since starting letter should be different i and j should be different
            for(int j=i+1;j<26;j++){
                
                int common_suffix = 0;
                for(auto suff:map[i]){
                    if(map[j].count(suff)){
                        common_suffix++;
                    }
                }
                
                ans += 2ll*(map[i].size()-common_suffix)*(map[j].size()-common_suffix);
            }
        }
        return ans;
    }
};