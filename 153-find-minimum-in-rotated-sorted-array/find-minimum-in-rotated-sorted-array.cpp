class Solution {
public:
    int findMin(vector<int>& nums) {
        //sort(nums.begin(), nums.end());   //taking O(n logn) time

        //return nums[0];

        // Min element - O(n)
        //return *min_element(nums.begin() , nums.end());

        // optimized approach
         int n = nums.size();
        // int low  = 0 , high = n - 1;

        // while(low < high){
        //     int mid = low + (high - low)/2;
        //     if(nums[mid] > nums[high] ){
        //        low = mid + 1;
        //     }
        //     else{
        //         high = mid;
        //     }

        // }
        // return nums[low];

        // One more binary search approach
        int low = 0 , high = n - 1;
        int min_ele  = INT_MAX;

        while(low <= high){
            int mid = low + (high - low)/2;
            //If the search space is sorted then there is no need of binary search
            if(nums[low] <= nums[high]){
                min_ele = min(min_ele , nums[low]);
                break;
            }
             // Identify the sorted part take the min value of and eliminate that part
            if(nums[low] <= nums[mid]){     
               min_ele = min(min_ele , nums[low]);
               low = mid + 1;
            }
            else{
                min_ele = min(min_ele , nums[mid]);
                high = mid - 1;
            }
        }
        return min_ele;



        

    }
};