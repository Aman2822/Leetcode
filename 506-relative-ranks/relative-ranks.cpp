class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        
        // Step 1: Create a map from score to its index in the original array.
        vector<pair<int, int>> scoreWithIndex;
        for (int i = 0; i < n; ++i) {
            scoreWithIndex.push_back({score[i], i});
        }
        
        // Step 2: Sort the scores in descending order.
        sort(scoreWithIndex.rbegin(), scoreWithIndex.rend());
        
        // Step 3: Create a result array to store the ranks.
        vector<string> result(n);
        
        // Step 4: Assign ranks based on sorted scores.
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                result[scoreWithIndex[i].second] = "Gold Medal";
            } else if (i == 1) {
                result[scoreWithIndex[i].second] = "Silver Medal";
            } else if (i == 2) {
                result[scoreWithIndex[i].second] = "Bronze Medal";
            } else {
                result[scoreWithIndex[i].second] = to_string(i + 1);
            }
        }
        
        return result;
    }
};