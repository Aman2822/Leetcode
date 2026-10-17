class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i = 0 ; i < rows - 1 ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(grid[i][j] != grid[i+1][j]){
                   return false;
                }
            }
        }

        for(int i = 0 ; i < cols - 1 ; i++){
            for(int j = 0 ; j < rows ; j++){
                if(grid[j][i] == grid[j][i+1]){
                   return false;
                }
            }
        }

        return true;
    }
};