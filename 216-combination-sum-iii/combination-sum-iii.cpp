class Solution {
public:
    vector<vector<int>> res;

    void solve(vector<int>& nums , vector<int>& temp , int k , int n , int i , int sum){
        int p = nums.size();

        if(i > p || sum > n || temp.size() > k){
            return;
        }
        else if(sum == n && temp.size() == k){
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(nums , temp , k , n , i+1 , sum +  nums[i] );
        temp.pop_back();

        solve(nums , temp , k , n, i+1 , sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;

        for(int i = 1 ; i <= 9 ; i++){
            nums.push_back(i);
        }

        vector<int> temp;
        solve(nums , temp , k , n , 0 , 0);

        return res;
    }
};