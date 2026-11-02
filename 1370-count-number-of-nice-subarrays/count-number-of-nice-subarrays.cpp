class Solution {
public:
    /*
    sliding window
    lastidx odd ka kaha pe wo dekhte hai
    */
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> pref(n);
        int lastidx = n;
        for (int i = n - 1; i >= 0; i--) {
            pref[i] = lastidx;
            if (nums[i] & 1) {
                lastidx = i;
            }
        }

        int res = 0;
        int odd = 0;

        int i = 0, j = 0;

        while (j < n) {
            if (nums[j] & 1)
                odd++;

            while (i <= j && odd > k) {
                if(nums[j] & 1) odd--;
                i++;
            }

            while(i <= j && odd == k){
                res += pref[j] - j;
                if(nums[i] & 1) odd--;
                i++;
            }

            j++;
        }

        return res;
    }
};