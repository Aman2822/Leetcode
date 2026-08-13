class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        //Linear Search

        // for(int i = 0 ; i < n ; i++){
        //     if(nums[i] == target) return true;
        // }

        // return false;

        //Binary Search
        int low = 0 , high = n - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target){  // If found return true
               return true;
            }

            //edge case - [1 0 1 1 1] shrink down until this case appars left = mid = right
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }
            // if it is sorted on left side then surely low will be smaller than mid
            else if(nums[low] <= nums[mid]){  
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            //right sorted part
            else{
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }

            }
        }
        return false;
       
    }
};