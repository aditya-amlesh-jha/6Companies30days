class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1){
            return s;
        }
        
        vector<string> ans(numRows);
        
        int temp = min(1ul*numRows,s.size());
        for(int i=0;i<temp;i++){
            ans[i].push_back(s[i]);
        }
        
        bool flag = true;
        int i = numRows;
        numRows--;
        
        while(i<s.size()){
            
            int k = i+numRows-1;
            k = min(1ul*k,s.size()-1);
            
            int index =(flag)?numRows-1:1;
            while(i<s.size() && i<=k){
                if(flag){
                    ans[index--].push_back(s[i++]);
                }
                else{
                    ans[index++].push_back(s[i++]);
                }
            }
            flag = !flag;
        }
        
        string a;
        for(auto x:ans){
            a+=x;
        }
        return a;
    }
};