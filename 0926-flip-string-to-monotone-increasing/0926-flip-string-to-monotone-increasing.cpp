class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count_one = 0;
        int min_flips = 0;
        
        for(int i=0;i<s.size();i++){
            if(s[i] == '1'){
                count_one++;
            }
            else{
                min_flips = min(count_one,min_flips+1);
            }
        }
        return min_flips;
    }
};