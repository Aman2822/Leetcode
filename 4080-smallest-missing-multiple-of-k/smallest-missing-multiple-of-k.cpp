class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int cnt = 1;
        int mul = k;

        for(int i = 0 ; i < n ;i++){
            if(nums[i] == mul){
                cnt++;
                mul = k * cnt;
            }
        } 

        return mul;
    }
};