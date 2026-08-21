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

        //Approach - 2 - O(N)

        // for(int i = 0 ; i < n ; i++){
        //    //Check for left index
        //    bool left = (i == 0 ) || (nums[i-1] < nums[i]);
        //    //Check for right index
        //    bool right = (i == n - 1) || (nums[i] > nums[i+1]);

        //    //If both are valid then peak element exists
        //    if(left && right) return i;
        // }

        // return -1;

        //Approach 3 - Binary Search

        if(n == 1) return 0;

        //Check for first element and last element
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        int low = 1 , high = n-2;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]){  // Peak condition
                return mid;
            }
            else if(nums[mid] > nums[mid-1]){ // means it is on a linear curve
                low = mid + 1;
            }
            else{                               
                high = mid - 1;
            }
        }

        return -1;





    }
};