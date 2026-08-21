class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        //Brute Force - Return the max element index
        
        // int max_ele = nums[0];
        // int max_ind = 0;

        // for(int i = 0 ; i < n ; i++){
        //     if(nums[i] > max_ele){
        //         max_ele = nums[i];
        //         max_ind = i;
        //     }
        // }
        // return max_ind;

        //Approach - 2

        for(int i = 0 ; i < n ; i++){
           //Check for left index
           bool left = (i == 0 ) || (nums[i-1] < nums[i]);
           //Check for right index
           bool right = (i == n - 1) || (nums[i] > nums[i+1]);

           //If both are valid then peak element exists
           if(left && right) return i;
        }

        return -1;




    }
};