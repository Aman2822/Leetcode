class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> special;

        for(int i = 0 ; i < n ; i++){
            if(n % (i+1) == 0){
                special.push_back(nums[i]);
            }
        }

        int square = 0;
        for(int i = 0 ; i < special.size() ; i++){
            square += (special[i] * special[i]);
        }

        return square;
    }
};