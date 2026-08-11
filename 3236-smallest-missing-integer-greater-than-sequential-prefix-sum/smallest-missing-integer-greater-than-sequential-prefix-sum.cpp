class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];

       // Get the sum
        for(int i = 1 ; i < n ; i++){
            if(nums[i] == nums[i-1] + 1){
                sum += nums[i];
            }
            else{
                break;
            }
        }

        unordered_set<int> st(nums.begin() , nums.end());


       // count means it searches in a set if that empty is present or not 
        while(st.count(sum)){
            sum++;
        }

        return sum;


    }
};