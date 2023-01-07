class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //first we have to determine whether journey is possible or not
        // this can be done by maintaining total diff of gas and cost
        // then we have to find the optimal station
        // we have to maintain a index from where the fuel is positive
        
        int total_diff = 0;
        int index = 0;
        int current = 0;
        for(int i=0;i<gas.size();i++){
            int diff = gas[i]-cost[i];
            total_diff += diff;
            current += diff;
            //now check if current is negative
            //if it is negative means that journey is not possible
            // ans we have to start from some other index
            
            if(current<0){
                index = i+1;
                //reset current
                current = 0;
            }
        }
        
        //now check if total fuel is positive
        return total_diff < 0 ? -1:index;
    }
};