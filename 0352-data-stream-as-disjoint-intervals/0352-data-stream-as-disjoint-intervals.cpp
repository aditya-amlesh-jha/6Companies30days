class SummaryRanges {
    set<int> parent;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        parent.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        int k = INT_MAX;
        for(auto i = parent.rbegin();i!=parent.rend();++i){
            if(*i >= k){
                continue;
            }
            int temp = findParent(*i);
            ans.push_back({temp,*i});
            k = min(temp,k);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int findParent(int n){
        if(parent.count(n-1)){
            return findParent(n-1);
        }
        return n;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */