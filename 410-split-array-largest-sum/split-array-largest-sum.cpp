class Solution {
public:
    int split(int curr , vector<int>& nums){
        int student = 1 , pagescurr = 0;

        for(int i = 0 ; i < nums.size() ; i++){
           if(nums[i] + pagescurr <= curr){
            pagescurr += nums[i];
           }
           else{
            student++;
            pagescurr = nums[i];
           }
        }

        return student;
    }

    
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        
        int low = *max_element(nums.begin() , nums.end());

        int high = accumulate(nums.begin() , nums.end() , 0);   //For sum of array we can use accumulate

        // int high = 0;
        // for(int i = 0 ; i < n ; i++){
        //     high += nums[i];
        // }

        // //I got the boundaries of the ans the ans is in boundaries
        // for(int pages = low ; pages <= high ; pages++){
        //     int curr_sum = split(pages , nums);
        //     if(curr_sum  <= k){
        //         return pages;
        //     }
        // }

        // return -1;


        //Applying binary search
        while(low <= high){
            int mid = low + (high-low)/2;
            int curr_sum = split(mid , nums);

            if(curr_sum > k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return low;
    }
};