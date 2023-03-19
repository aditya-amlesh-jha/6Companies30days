class TrieNode{
    public:
    vector<TrieNode*> child;
    bool isend;
    TrieNode(){
        isend = false;
        child.resize(26,nullptr);
    }
};

class WordDictionary {
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *curr = root;
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if(curr->child[index] == nullptr){
                curr->child[index] = new TrieNode();
            }
            curr = curr->child[index];
        }
        curr->isend = true;
    }
    
    bool search(string word) {
        return search(word,root,0);
    }
    bool search(string &word, TrieNode *root, int index){
        if(index == word.size()){
            return root->isend;
        }
        if(word[index] == '.'){
            for(int i=0;i<26;i++){
                if(root->child[i] && search(word,root->child[i],index+1)){
                    return true;
                }
            }
            return false;
        }
        int in = word[index] - 'a';
        return root->child[in] && search(word,root->child[in],index+1);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */