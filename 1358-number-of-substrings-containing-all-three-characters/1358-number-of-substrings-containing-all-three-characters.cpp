class Solution {
public:
    int numberOfSubstrings(string s) {
        //sliding window problem
        unordered_map<char,int> map;
        int curr = 0;
        int count = 0;
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
            while(map['a'] && map['b'] && map['c']){
                count += (s.size()-i);
                map[s[curr++]]--;
            }
        }
        return count;
    }
};