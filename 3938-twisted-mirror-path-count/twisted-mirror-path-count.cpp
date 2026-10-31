class Solution {
public:
    int MOD = 1e9 + 7;
    int UP = 1;   //arrived at the current cell (means it was moving down)
    int LEFT = 0;  //arrived at the current cell(means it was moving right)
    int m ;
    int n ;

    int solve(vector<vector<int>>& grid , int i , int j , int camefrom , 
        vector<vector<array<int, 2>>>& t){
        if(i >= m || j >= n) return 0;
        if(i == m - 1 && j == n - 1) return 1;

        if(t[i][j][camefrom] != -1){
            return t[i][j][camefrom];
        }

        //Mirror wala case
        if(grid[i][j] == 1){
            if(camefrom == UP){
                return t[i][j][camefrom] = solve(grid , i , j+1 , LEFT , t);
            }
            else{
                return t[i][j][camefrom] = solve(grid , i+1 , j , UP , t);
            }
        }

        //Normal case when grid[i][j] == 0
        int totalpaths = 0;
        totalpaths = (totalpaths +  solve(grid , i , j+1 , LEFT , t)) % MOD;
        totalpaths = (totalpaths + solve(grid , i+1 , j , UP , t)) % MOD;

        return t[i][j][camefrom] = totalpaths % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        //memoization of dp[i][j][camefrom] camefrom = {-1,-1};
        vector<vector<array<int, 2>>> t(m+1 , vector<array<int , 2>>(n , {-1,-1}));

        return solve(grid , 0 , 0 , UP , t);
        
    }
};