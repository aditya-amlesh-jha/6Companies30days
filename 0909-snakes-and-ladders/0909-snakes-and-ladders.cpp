class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int size = board.size()*board.size();
        
        vector<int> ladders;
        bool flag = false;
        
        for(int i=board.size()-1;i>=0;i--){
            for(int j=0;j<board.size();j++){
                int index = flag?board.size()-1-j:j;
                ladders.push_back(board[i][index]);
            }
            flag = !flag;
        }
        
        vector<bool> visited(size,false);
        int start = ladders[0]>-1?ladders[0]-1:0;
        queue<int> pendingNodes;
        pendingNodes.push(start);
        visited[start] = true;
        
        int level = 0;
        while(pendingNodes.size()){
            int sizeQ = pendingNodes.size();
            for(int i=0;i<sizeQ;i++){
                
                int curr = pendingNodes.front();
                cout<<curr<<" ";
                pendingNodes.pop();
                if(curr == size - 1) {
                    return level;
                }
                for(int j=curr+1;j<min(curr+7,size);j++){
                    int index = ladders[j]>-1?ladders[j]-1:j;
                    if(visited[index] == false){
                        pendingNodes.push(index);
                        visited[index] = true;
                    }
                }
            }
            level++;
        }
        
        return -1;
    }
};