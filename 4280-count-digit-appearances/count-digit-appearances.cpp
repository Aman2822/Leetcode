class Solution {
public:
    int occurence(int p, int digit) {
        int res = 0;

        while(p > 0){
            int rem = p % 10;
            if(rem == digit) res++;
            p /= 10;
        }
        return res;
    }

    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            cnt += occurence(nums[i], digit);
        }

        return cnt;
    }
};