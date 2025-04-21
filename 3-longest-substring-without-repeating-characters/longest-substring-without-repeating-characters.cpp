class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_set<char> seen;
    int left = 0, right = 0, maxLen = 0;

    while (right < s.length()) {
        if (seen.find(s[right]) == seen.end()) {
            // Character not in set, insert it and update maxLen
            seen.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
            right++;
        } else {
            // Character already in set, remove the leftmost one
            seen.erase(s[left]);
            left++;
        }
    }

    return maxLen;
}

};