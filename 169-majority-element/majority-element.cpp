class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
    //     unordered_map<int, int> mpp;
    //     // int max_Apperance  = (n/2) + 1;
    //     // int count  = 0;

    //     for(int i = 0 ;  i < n ; i++  ){
    //        mpp[nums[i]]++;
    //     }

    //     for(auto it : mpp){
    //         if(it.second > n/2){
    //             return it.first;
    //         }
    //     }
    //    return -1;


    //Moore's voting algo
    int count = 0;
    int el;

    for(int i= 0 ; i < n ; i++){
        if(count == 0){
            count++;
            el = nums[i];
        }
        else if(nums[i] == el) {
            count++;
            }
        else {
            count--;
        }
    }
    int count1 = 0;
    for(int i = 0 ; i < n ; i++){
        if(nums[i] == el) count1++;

        if(count1 > n/2){
            return el;
        }
    }
    return -1;
       
    }
};