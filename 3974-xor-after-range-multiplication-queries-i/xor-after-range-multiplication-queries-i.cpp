class Solution {
public:
    int MOD = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();

        for(int i = 0 ; i < n ; i++){

            for(int j = queries[i][0] ; j <= queries[i][1] ; j = j + queries[i][2]){
                nums[j] = (1LL * nums[j] * queries[i][3]) % MOD; 
            }
        }

        long long res = nums[0];
        for(int i = 1 ; i < nums.size() ;i++){
            res ^= nums[i];
        }

        return res;
    }
};