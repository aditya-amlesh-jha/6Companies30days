class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> ans;
        for(int i=0;i<profits.size();i++){
            ans.push_back(make_pair(capital[i],profits[i]));
        }
        sort(ans.begin(),ans.end());
        priority_queue<int> ca;
        int i = 0;
        // int a = 0;
        while(k--){
            while(i<ans.size() && ans[i].first<=w){
                ca.push(ans[i].second);
                i++;
            }
            if(ca.size()){
                w += ca.top();
                ca.pop();
            }
        }
        return w;
    }
};