class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> map;
        int curr = 0;
        int sum = 0;
        int ans = 0;
        for(int i=0;i<fruits.size();i++){
            map[fruits[i]]++;
            sum++;
            while(map.size()>2){
                sum--;
                map[fruits[curr]]--;
                if(map[fruits[curr]] == 0){
                    map.erase(fruits[curr]);
                }
                curr++;
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};