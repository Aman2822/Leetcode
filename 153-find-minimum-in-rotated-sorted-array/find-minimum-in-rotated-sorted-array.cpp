class Solution {
public:
    int findMin(vector<int>& nums) {
        //sort(nums.begin(), nums.end());   //taking O(n logn) time

        //return nums[0];

        // Min element - O(n)
        return *min_element(nums.begin() , nums.end());


        

    }
};