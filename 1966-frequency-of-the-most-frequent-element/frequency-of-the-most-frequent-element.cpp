//unordered_map<int,int> mpp;
//int MaxFreq = INT_MIN;

  int bsearch(int target_idx, int k , vector<int>& nums, vector<long>& prefixsum){
           int target = nums[target_idx];

           int l = 0;
           int r = target_idx;

           int best_idx = target_idx;

           while(l<=r){
            int mid = l + (r-l)/2 ; 
            
            long count = (target_idx - mid +1);
            long windowsum = count * target;

 
            long currsum = prefixsum[target_idx]-prefixsum[mid]+nums[mid];

            long operations = windowsum - currsum;

            if(operations > k){
                l = mid + 1;
            }
            else{
                best_idx = mid;
                r = mid-1;
            }
           }
            return target_idx -best_idx +1;
          
        }

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
         

       int n = nums.size();

       sort(nums.begin(), nums.end());

       vector<long> prefixsum(n);
       prefixsum[0] = nums[0];
       for(int i = 1 ; i < n; i++){
        prefixsum[i] = prefixsum[i-1] + nums[i];
       }

       int result = 0;
       
       for(int target_idx = 0; target_idx < n; target_idx++){
         result = max(result, bsearch(target_idx, k, nums, prefixsum));
       }

     return result;
    }

};