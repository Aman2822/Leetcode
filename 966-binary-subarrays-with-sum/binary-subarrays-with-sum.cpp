class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int res = 0;
        int sum = 0;

        int i = 0 , j = 0;

        //Hume track karna hai next 1 kab aayega
        vector<int> pref(n);
        int lastidx = n;
        for(int j =  n - 1 ; j >= 0 ; j--){
            pref[j] = lastidx;
            if(nums[j] == 1){
                lastidx = j;
            }
        }

        while(j < n){
            sum += nums[j];

            while(i <= j && sum > goal){
                sum -= nums[i];
                i++;
            }

            while(i <= j && sum == goal){
                res += pref[j] - j;
                sum -= nums[i];
                i++;
                
            }

            j++;

        }

        return res;
    }
};