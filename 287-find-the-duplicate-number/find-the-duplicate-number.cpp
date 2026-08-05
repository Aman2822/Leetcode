class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> dupli;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            dupli[nums[i]]++;
        }

        for(auto it : dupli){
            if(it.second > 1) return it.first;
        }

        return -1;


    }
};