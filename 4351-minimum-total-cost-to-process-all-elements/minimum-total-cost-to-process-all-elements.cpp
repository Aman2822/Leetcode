class Solution {
public:
    int MOD = 1e9 + 7;
    typedef long long ll;

    int minimumCost(vector<int>& nums, int k) {
        int n = nums.size();
        ll opn_count = 0;
        ll temp = k , rem_k = k;
        ll total_cost = 0;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] <= rem_k)  rem_k -=nums[i];
            else if(nums[i] > rem_k){
                ll shortage = nums[i] - rem_k;
                ll count = (shortage+temp-1)/temp;         //Ceil value
                rem_k += count * temp;
                ll start_cost = opn_count + 1 , end_cost = opn_count + count;
                ll step_cost = (ll)(((__int128)count * (start_cost + end_cost) / 2) % MOD);
                total_cost = (total_cost + step_cost) % MOD;
                opn_count +=count;
                rem_k -=nums[i];
                }
        }
        return (total_cost + MOD) % MOD;  
        
    }
};