class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        bool p1 = true;
        bool p2 = false;
        int score1 = 0 , score2 = 0;
        int swap_6 = 5;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] % 2 == 1){
                swap(p1,p2);
            }
            if(i == swap_6){
                swap(p1,p2);
                swap_6 += 6;
            }
            if(p1) score1 += nums[i];
            else score2 += nums[i];
        }

        return score1 - score2;
    }
};