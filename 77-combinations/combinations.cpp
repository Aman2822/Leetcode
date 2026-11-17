class Solution {
public:  
    vector<vector<int>> res;

    void solve(vector<int>& temp , int n  , int k , int idx){

        if(temp.size() == k){
            res.push_back(temp);
            return;
        }

        for(int i = idx ; i <= n ; i++){
            temp.push_back(i);
            solve(temp , n , k , i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;

        solve(temp , n , k , 1);

        return res;
    }
};