class Solution {
public:
    typedef long long ll;
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        ll res = 0 , sum = 0;

        unordered_map<int , int> mp;
        int i = 0 , j = 0;

        while(j < n){
            sum += nums[j];
            mp[nums[j]]++;

            if(i < j && j-i+1 > k){
                sum -= nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }

            if(i < j && j - i + 1 == k && mp.size() < m){
                sum -= nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }

            if(j-i+1 == k && mp.size() >= m){
                res = max(res , sum);
            }

            j++;
        }

        return res;
    }
};