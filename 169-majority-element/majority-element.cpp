class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        // int max_Apperance  = (n/2) + 1;
        // int count  = 0;

        for(int i = 0 ;  i < n ; i++  ){
           mpp[nums[i]]++;
        }

        for(auto it : mpp){
            int element  = it.first;
            int maj_element = it.second;

            if(maj_element > n/2){
                return it.first;
            }
        }
       return {};
       
    }
};