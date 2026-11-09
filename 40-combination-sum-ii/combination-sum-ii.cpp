class Solution {
public:
    vector<vector<int>> res;

    void solve(vector<int>& candidates, vector<int>& temp, int target,  int start, int sum) {
        int n = candidates.size();

        if (sum > target)
            return;
        else if (sum == target) {
            res.push_back(temp);
            return;
        }

        for (int i = start; i < n; i++) {

            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // recursiom
            temp.push_back(candidates[i]);
            solve(candidates, temp, target, i + 1, sum + candidates[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;

        solve(candidates, temp, target, 0, 0);

        return res;
    }
};