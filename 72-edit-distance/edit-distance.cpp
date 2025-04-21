class Solution {
public:
    int minDistance(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialize base cases
    for (int i = 0; i <= m; ++i) dp[i][0] = i; // Delete all
    for (int j = 0; j <= n; ++j) dp[0][j] = j; // Insert all

    // DP computation
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // No operation needed
            } else {
                dp[i][j] = 1 + min({ 
                    dp[i - 1][j],    // Delete
                    dp[i][j - 1],    // Insert
                    dp[i - 1][j - 1] // Replace
                });
            }
        }
    }

    return dp[m][n];
}

};