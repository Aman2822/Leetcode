class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 2) return nums;

        //Approach 1 - Hashmap - TC = O(N logM) + M   and SC O(M) ,  m is map size
        // unordered_map<int, int> mp;
        // vector<int> ans;

        // for(int &num : nums){
        //     mp[num]++;
        // }

        // for(auto it : mp){
        //     if(it.second == 1){
        //         ans.push_back(it.first);
        //     }
        // }

        // return ans;


        //Approach 2 - Sorting - TC = O(N logN) + N   SC = O(1)
        // sort(begin(nums) , end(nums));

        // for(int i = 0 ; i < n - 1 ; i++){
        //    int val = nums[i] ^ nums[i+1];
        //    if(val == 0){
        //     i++;
        //    }
        //    else{
        //     ans.push_back(nums[i]);
        //    }
        // }

        // if(ans.size() == 1){
        //     ans.push_back(nums[n-1]);
        // }

        // return ans;

        //Approach 3 - with help of buckets and bit manipulation  tC= O(2N) and SC = O(1)
        long xorr = 0;
        for(int i = 0 ; i < n ; i++){
            xorr = xorr ^ nums[i];
        }

        int rightmost = (xorr & xorr - 1) ^ xorr;
        int b1 = 0 , b2 = 0;

        for(int i = 0 ; i < n ; i++){
            //with the help of that rightmost seperate nums in two buckets
            if(rightmost & nums[i]){
                b1 = b1 ^ nums[i];
            }
            else{
                b2 = b2 ^ nums[i];
            }
        }

        return {b1 , b2};



        

    }
};