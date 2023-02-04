class Solution {
public:
    bool checkInclusion(string a, string s) {
        unordered_map<int,int> map;
        for(auto x:a){
            map[x]++;
        }
        int count = map.size();
        int curr = 0;
        
        for(int i=0;i<s.size();i++){
            map[s[i]]--;
            
            if(map[s[i]] == 0){
                count--;
            }
            if(count == 0){
                return true;
            }
            
            while(map[s[i]] < 0){
                map[s[curr]]++;
                
                if(map[s[curr]] == 1){
                    count++;
                }
                
                curr++;
            }   
        }
        return false;
    }
};