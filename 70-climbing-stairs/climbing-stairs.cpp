class Solution {
public:
    int solve(int index , vector<int>& dp){
        if(index == 0) return 1;
        if(index == 1) return 1;
        
        //dp lookup 
        if(dp[index] != -1){
            return dp[index];
        }

        int left = solve(index-1 , dp);
        int right = solve(index-2 , dp);
        
        //dp storing
        return dp[index] = left+right;
    }
    int climbStairs(int n) {
        //1d dp array memoization
        vector<int> dp(n+1 , -1);
        return solve(n , dp);
    }
};