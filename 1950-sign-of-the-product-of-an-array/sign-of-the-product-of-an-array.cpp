class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negative_cnt = 0;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0){
                return 0;
            }
            else if(nums[i] < 0) negative_cnt++;
        }

        if(negative_cnt % 2 == 0) return 1;
        else return -1;



    }
};