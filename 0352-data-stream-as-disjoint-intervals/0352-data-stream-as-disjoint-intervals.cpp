class SummaryRanges {
    set<int> nums;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        nums.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        int start, end;
        start = end = -1;
        for(auto x:nums){
            if(end < 0){
                start = end = x;
            }
            else if(x-end == 1){
                end = x;
            }
            else{
                ans.push_back({start,end});
                start = end = x;
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */