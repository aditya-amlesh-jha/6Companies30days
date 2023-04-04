class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> map;
        int ans = 1;
        for(int i=0;i<s.size();i++){
            if(map[s[i]]>=1){
                ans++;
                map.clear();
            }
            map[s[i]]++;
        }
        return ans;
    }
};