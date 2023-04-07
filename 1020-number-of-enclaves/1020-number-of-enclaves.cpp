class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int no = 0;
                if(grid[i][j] == 1 && dfs(grid,i,j,no)){
                    count += no;
                }
            }
        }
        return count;
    }
    bool dfs(vector<vector<int>> &grid, int i, int j, int &no){
            if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
                return false;
            }
            else if(grid[i][j] == 0){
                return true;
            }
            grid[i][j] = 0;
            no++;
            bool a = dfs(grid,i+1,j,no);
            bool b = dfs(grid,i-1,j,no);
            bool c = dfs(grid,i,j+1,no);
            bool d = dfs(grid,i,j-1,no);
            return a && b && c && d;
    }
};