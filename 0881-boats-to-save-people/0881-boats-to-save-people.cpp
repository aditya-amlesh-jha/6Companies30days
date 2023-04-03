class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i = 0, j = people.size()-1, count = 0;
        while(i<j){
            if(people[j]+people[i] > limit){
                j--;
                count++;
            }
            else if(people[j]+people[i]<=limit){
                i++;
                j--;
                count++;
            }
        }
        if(i==j){
            count++;
        }
        return count;
    }
    
};