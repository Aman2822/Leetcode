class Solution {
public:
    //    //Approach 1 : recursion + memo because here there is options and
    //    overlapping problems
    //     int t[10001];

    //     bool solve(vector<int>& nums , int n , int idx){
    //         if(idx == n-1) return true;

    //         if(idx >= n) return false;

    //         if(t[idx] != -1){
    //             return t[idx];
    //         }

    //         //options exploring
    //         for(int i = 1 ; i <= nums[idx] ; i++){
    //             if(solve(nums , n , idx + i)){
    //                 return t[idx] = true;
    //             }
    //         }

    //         return t[idx] = false;
    //     }

    // bool canJump(vector<int>& nums) {
    // int n = nums.size();
    // int idx = 0;

    // memset(t , -1 , sizeof(t));

    // return solve(nums , n , idx);

    // }

    // bool canJump(vector<int>& nums) {
    //     int n = nums.size();
        
    //     //Approach 2 : bottom up approach

    //     vector<bool> t(n , false);
    //     t[0] = true;

    //     //t[i] = true : matlab hum uss i index tak pohoch sakte ho
    //     //t[i] = false : we cant reach to ith index

    //     for(int i = 1 ; i < n ; i++){
    //         for(int j = i - 1 ; j >=0 ; j--){
    //             if(t[j] == true && j + nums[j] >= i){
    //                 t[i] = true;
    //                 break;
    //             }
    //         }
    //     }

    //     return t[n-1];
    // }


     bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        
       //Approach 3 : Greedy approach
       int max_left = 0;

       for(int i = 0 ;i < n ; i++){
        if(i > max_left) return false;

        max_left = max(max_left , i + nums[i]);
       }
       return true;
    }
};