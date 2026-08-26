class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));   //Make a grid filled with #s

        //Only i have go from first row of a cell to last cell of first cell and then down to bottom cell from last column

        for(int i = 0 ; i < n ; i++){  // Marked first row with '.' means  free cell
            grid[0][i] = '.';
        }
         
        //Marked last column with '.' means free cell by this it will be exactly one path
        for(int i = 0 ; i < m ; i++){
            grid[i][n-1] = '.';
        }


        return grid;
    }
};