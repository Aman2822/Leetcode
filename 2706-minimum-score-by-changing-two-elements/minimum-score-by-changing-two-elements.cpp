class Solution {
public:
    /*
     1 4 5 7 8
     8 28 42 58 75
     25 31 65 72 74 79
    */
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());

        return min ({
            nums[n-3] - nums[0] ,
            nums[n-1] - nums[2],
            nums[n-2] - nums[1]
        });

    }
};