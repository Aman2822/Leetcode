class Solution {
public:
    // int sliding(vector<int>& nums, int k) {
    //     int n = nums.size();

    //     if( k == 0 ) return 0;
        
    //     int res = 0;
    //     unordered_map<int, int> mp;

    //     int i = 0, j = 0;

    //     while (j < n) {
    //         mp[nums[j]]++;

    //         while (i < j && mp.size() > k) {
    //             mp[nums[i]]--;
    //             if (mp[nums[i]] == 0) {
    //                 mp.erase(nums[i]);
    //             }
    //             i++;
    //         }

    //         res += (j - i + 1); // count all the subarrays which are ending with j and forming k elements

    //         j++;
    //     }

    //     return res;
    // }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //by subtracting it will remove the wrong subarrays
        // return sliding(nums, k) - sliding(nums, k - 1);


        //Approach 2
        int n = nums.size();
        int i = 0 , j = 0 , i_bada = 0 , res = 0;

        unordered_map<int , int> mp;

        while(j < n ){
            mp[nums[j]]++;

            while(i < j && mp.size() > k){
                //Shrinking the window
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
                //we are also shifting i bada because now all the subarrays are invalid
                i_bada = i;
            }
            
            //shortest valid subarray at i position
            while(mp[nums[i]] > 1){
                mp[nums[i]]--;
                i++;
            }

            if(mp.size() == k){
                //count all the valid subarrays
                res += (i - i_bada) + 1;
            }
            j++;
        }

        return res;
    }
};