class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> map;
        int ans = INT_MAX;
        int curr = 0;
        for(int i=0;i<cards.size();i++){
            if(++map[cards[i]] == 2){
                while(cards[curr]!=cards[i]){
                    map[cards[curr++]]--;
                }
                cout<<i<<" "<<curr<<endl;
                ans = min(ans,i-curr+1);
                map[cards[curr]]--;
                curr++;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};