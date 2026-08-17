class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        //Brute Force - Return the max element index
        int max_ele = nums[0];
        int max_ind = 0;


        for(int i = 0 ; i < n ; i++){
            if(nums[i] > max_ele){
                max_ele = nums[i];
                max_ind = i;
            }
        }
        return max_ind;

    }
};