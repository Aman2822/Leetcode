class Solution {
public:
    /*
    straight forward recursion we have to two options one -ve and +ve
    */
    
    int solve(vector<int>& nums , int target , int i , int sum){
        int n = nums.size();

        if(i >= n){
            return (sum == target) ? 1 : 0;
        }

        int posi = solve(nums , target , i + 1 , sum + nums[i]);

        int negi = solve(nums , target , i+1 , sum-nums[i]);

        return posi + negi;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int res = solve(nums , target , 0 , 0);

        return res;
    }
};