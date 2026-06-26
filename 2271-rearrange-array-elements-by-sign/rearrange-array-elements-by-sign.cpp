class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> positive_ele;
        vector<int> negative_ele; 

        for(int i = 0 ; i < n ; i++){
            if(nums[i] > 0){
                positive_ele.push_back(nums[i]);
            }
            else{
                negative_ele.push_back(nums[i]);
            }
        }

        int i = 0, k= 0 , j =0 ;
        while(i != n){
            if(i%2 == 0){
                nums[i] = positive_ele[k];
                k++;
            }
            else{
                nums[i] = negative_ele[j];
                j++;
            }
            i++;
        }
         return nums;
    }
};