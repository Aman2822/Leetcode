class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0 , j = 0;
        int zerocnt = 0;
        int result = 0;

        while(j < n){
           if(nums[j] == 0) zerocnt++;

           while(i < j && zerocnt > k){
            if(nums[i] == 0) zerocnt--;
            i++;
           }

           if(zerocnt <= k){
            result = max(result , j - i + 1);
           }
           j++;
        }

        return result;
    }
};