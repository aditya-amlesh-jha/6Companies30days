class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> index(26,-1);
        for(int i=0;i<order.size();i++){
            int in = order[i]-'a';
            index[in] = i;
        }
        
        for(int i=0;i<words.size()-1;i++){
            int m = 0, n = 0;
            string &a = words[i];
            string &b = words[i+1];
            
            while(m<a.size() && n<b.size()){
                if(index[a[m]-'a'] < index[b[n]-'a']){
                    break;
                }
                else if(a[m] == b[n]){
                    m++;
                    n++;
                }
                else{
                    cout<<a[m]<<" "<<a[n]<<endl;
                    return false;
                }
            }
            
            if(m < a.size()){
                if(n < b.size()){
                    continue;
                }
                return false;
            }
        }
        
        return true;
    }
};