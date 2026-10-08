class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxprod = INT_MIN;

        //Generate all subarrays and take max product   TC = O(N^2) and SC = O(1)

        // for(int i = 0 ; i < n ; i++){
        //     int prod = 1;
        //     for(int j = i ; j < n ; j++){
        //         prod *= nums[j];
        //         maxprod = max(maxprod , prod);
        //     }
        // }

        //Better Approach 
        int pref = 1 , suff = 1;

        for(int i = 0 ; i < n ; i++){
            if(pref == 0) pref = 1;
            if(suff == 0) suff = 1;

            pref = pref * nums[i];
            suff = suff * nums[n-i-1];

            maxprod = max(maxprod , max(pref , suff));
        }


        return maxprod;

        
    }
};