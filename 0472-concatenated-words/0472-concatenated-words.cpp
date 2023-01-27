class TrieNode{
    public:
    vector<TrieNode*> child;
    bool isEnd;
    TrieNode(){
        isEnd = false;
        child.resize(26,0);
    }
};

class Solution {
    TrieNode *root;
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        root = new TrieNode();
        for(auto i:words){
            insert(i);
        }
        vector<string> a;
        bool flag = false;
        for(auto i:words){
            vector<vector<int>> dp(i.size(),vector<int>(i.size(),-1));
            ans(dp,a,i,0,i.size()-1,0,flag);
            flag = false;
        }
        return a;
    }
    void ans(vector<vector<int>> &dp,vector<string> &a, string &word, int start, int end, int count,bool &flag){
        if(start == word.size() && count>=2){
           a.push_back(word);
           flag = true;
           return;
        }
        for(int i=start;i<=end;i++){
            if(flag){
                return;
            }
            else if(dp[i][start]==0){
                continue;
            }
            else if(dp[i][start] == -1){
                dp[i][start] = search(word.substr(start,i-start+1));
            }
            if(dp[i][start]){
                ans(dp,a,word,i+1,end,count+1,flag);
            }
        }
    }
    void insert(string &a){
        TrieNode *curr = root;
        for(int i=0;i<a.size();i++){
            int index = a[i]-'a';
            if(curr->child[index] == nullptr){
                curr->child[index] = new TrieNode();
            }
            curr = curr->child[index];
        }
        curr->isEnd = true;
    }
    bool search(string a){
        TrieNode *curr = root;
        for(int i=0;i<a.size();i++){
            int index = a[i]-'a';
            if(curr->child[index] == nullptr){
                return false;
            }
            curr = curr->child[index];
        }
        return curr->isEnd == true;
    }
};