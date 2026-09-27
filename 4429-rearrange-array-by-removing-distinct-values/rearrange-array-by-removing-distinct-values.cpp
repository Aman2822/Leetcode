class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        map<int , int> mp;

        for(int &num : nums){
            mp[num]++;
        }

        // vector<pair<int, int>> freq;
        // for(auto it : mp){
        //     freq.push_back({it.first , it.second});
        // }

        // while(ans.size() < n ){
        //     for(auto &it : freq){
        //         if(it.second > 0){
        //             ans.push_back(it.first);
        //             it.second--;
        //         }
        //     }
        // }

        while(ans.size() < n){
            for(auto &it : mp){
                if(it.second > 0){
                    ans.push_back(it.first);
                    it.second--;
                }
            }
        }
        
        return ans;
    }
};