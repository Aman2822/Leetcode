class Solution {
public:

    //Approach 1 - using set


    // int n;
    // vector<vector<int>> res;
    // unordered_set<int> st;

    // void solve(vector<int>& temp , vector<int>& nums){

    //     if(temp.size() == n){
    //         res.push_back(temp);
    //         return;
    //     }
        
    //     //we are using loop by only tree we will miss out the indexes
    //     for(int i = 0 ; i < n ; i++){

    //         if(st.find(nums[i]) == st.end()){  

    //             temp.push_back(nums[i]);   // do
    //             st.insert(nums[i]);

    //             solve(temp , nums);  // explore

    //             temp.pop_back();   // delete
    //             st.erase(nums[i]);
    //         }
    //     }
    // }

    // vector<vector<int>> permute(vector<int>& nums) {
    //     n = nums.size();

    //     vector<int> temp;

    //     solve(temp , nums);

    //     return res;
    // }
    
    vector<vector<int>> res;
    int n ;

    void solve(vector<int>& nums , int idx){

        if(idx == n){
            res.push_back(nums);
            return;
        }

        for(int i = idx ; i < n ; i++){

            swap(nums[i] , nums[idx]);

            solve(nums , idx + 1);

            swap(nums[idx]  , nums[i]);
        }
    }


    vector<vector<int>> permute(vector<int>& nums){
        n = nums.size();

        solve(nums , 0);

        return res;
    }
};