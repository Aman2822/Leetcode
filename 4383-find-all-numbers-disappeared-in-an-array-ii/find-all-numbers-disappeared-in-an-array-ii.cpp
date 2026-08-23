class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
       int n = nums.size();
       unordered_set<int> disappear;

       for(int i = 0 ; i < n ; i++){  //Insert all elements in the set
        disappear.insert(nums[i]);
       }

       vector<int> missing;
       for(int i = lower ; i <= upper ; i++){
        if(!disappear.contains(i)){
            missing.push_back(i);              // Missing array 
        }
       }

       vector<vector<int>>ans;
       int i = 0;
       int m = missing.size();

       while(i < m){
        int first_no = missing[i];
        int second_no = missing[i];
        while(i+1 < m &&  missing[i+1] == missing[i] + 1){
            second_no = missing[i+1];
            i++;
        }
        vector<int> range = {first_no , second_no};
        ans.push_back(range);
        i++;
       }

       return ans;


        
    }
};