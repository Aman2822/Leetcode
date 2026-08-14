class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = s.length();

        // Sliding Window
        unordered_map<char , int> mp;
        int i = 0 , j = 0;
        int result = 0;

        while( j < l ){
            mp[s[j]]++;

            while(i < j && mp[s[j]] > 2){
                mp[s[i]]--;
                i++;
            }

            result = max(result , j-i+1);
            j++;
        }
        return result;
    }
};