class Solution {
public:

   //Approach 1 : recursion + memo because here there is options and overlapping problems
    int t[10001];

    bool solve(vector<int>& nums , int n , int idx){
        if(idx == n-1) return true;

        if(idx >= n) return false;

        if(t[idx] != -1){
            return t[idx];
        }
        
        //options exploring
        for(int i = 1 ; i <= nums[idx] ; i++){
            if(solve(nums , n , idx + i)){
                return t[idx] = true;
            }
        }

        return t[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;

        memset(t , -1 , sizeof(t));

        return solve(nums , n , idx);
    }
};