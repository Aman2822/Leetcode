class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        //Prefix array to calcualte max
        vector<int> maxi(n);
        maxi[0] = nums[0];

        for(int i = 1 ; i < n ; i++){
            maxi[i] = max(maxi[i-1] , nums[i]);
            // cout << maxi[i] << endl;
        }

        //Suffix array to calculate min
        vector<int> mini(n);
        mini[n-1] = nums[n-1];

        for(int i = n-2 ; i >= 0 ;i--){
            mini[i] = min(mini[i+1] , nums[i]);
            // cout << mini[i] << endl;
        }

        int ans = -1;
        for(int i = 0 ; i < n ; i++){
            if(maxi[i] - mini[i] <= k){
                ans = i;
                break;
            }
        }

        return ans;
    }
};