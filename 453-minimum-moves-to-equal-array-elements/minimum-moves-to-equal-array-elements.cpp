class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mini = *min_element(nums.begin() , nums.end());
        int moves = 0;

        // for(int i = 0 ; i < n ; i++){
        //    moves += (nums[i] - mini);
        // }

        //we can derive a mathematical formula from for loop = sum - n * mini;
        int sum = accumulate(nums.begin() , nums.end() , 0);

        return sum - n * mini;
    }
};