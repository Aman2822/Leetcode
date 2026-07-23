class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n = nums.size();
        int single_digit = 0;
        int double_digit = 0;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] > 9) double_digit += nums[i];
            if(nums[i] < 10 )single_digit += nums[i];
        }

        if(single_digit == double_digit) return false;
        else return true;

        


    }
};