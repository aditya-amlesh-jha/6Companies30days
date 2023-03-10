class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.size() < str2.size()){
            return gcdOfStrings(str2,str1);
        }
        else if(str2.size() == 0){
            return str1;
        }
        else if(str1.substr(0,str2.size()) != str2){
            return "";
        }
        return gcdOfStrings(str1.substr(str2.size()),str2);
    }
};