class Solution {
public:
    int findMin(vector<int>& nums) {
        //sort(nums.begin(), nums.end());   //taking O(n logn) time

        //return nums[0];

        // Min element - O(n)
        //return *min_element(nums.begin() , nums.end());

        // optimized approach
        int n = nums.size();
        int low  = 0 , high = n - 1;

        while(low < high){
            int mid = low + (high - low)/2;
            if(nums[mid] > nums[high] ){
               low = mid + 1;
            }
            else{
                high = mid;
            }

        }
        return nums[low];



        

    }
};