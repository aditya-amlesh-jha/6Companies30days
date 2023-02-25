class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> index;
        index.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                index.push(i);
            }
            else{
                index.pop();
                if(index.empty()){
                    index.push(i);
                }
                ans = max(ans,i-index.top());
            }
        }
        return ans;
    }
};