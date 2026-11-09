class Solution {
public:
    vector<vector<int>> res;

    void solve(vector<int>& nums , vector<int>& temp , int start){
        int n = nums.size();

        res.push_back(temp);
        
        for(int i = start ; i < n ; i++){
            if(i > start && nums[i] == nums[i-1]) continue;

            temp.push_back(nums[i]);
            solve(nums , temp , i+1 );
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin() , nums.end());

        solve(nums , temp , 0);

        return res;
    }
};