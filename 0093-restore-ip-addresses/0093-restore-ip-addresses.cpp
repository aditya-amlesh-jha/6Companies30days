class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> valid;
        for(int i=1;i<4;i++){
            for(int j=1;j<4;j++){
                for(int k=1;k<4;k++){
                    
                    int len = s.size()-i-j-k;
                    if(len<=0 || len>3){
                        continue;
                    }
                    int a = stoi(s.substr(0,i));
                    int b = stoi(s.substr(i,j));
                    int c = stoi(s.substr(i+j,k));
                    int d = stoi(s.substr(i+j+k,len));
                    if(a<=255 && b<=255 && c<=255 && d<=255){
                        string temp = to_string(a)+'.'+to_string(b)+'.'+to_string(c)+'.'+to_string(d);
                        if(temp.size() == s.size()+3){
                            valid.push_back(temp);
                        }
                    }
                }
            }
        }
        return valid;
    }
};