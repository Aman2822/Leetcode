class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        
        // unordered_map<int,int> hashh;

        // for(int i = 0 ; i< n ;i++){
        //     hashh[nums[i]]++;
        // }

        // for(int i = 0; i<n ;i++){
        //     if(hashh[nums[i]] == 1){
        //         return nums[i];
        //     }
        // }

        // return -1;


        //Optimal 

        int ans  = 0;

        for(int i = 0 ; i < n; i++){
            ans = ans ^ nums[i];
        }
        
        return ans;
    }
};