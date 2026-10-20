class Solution {
public:
    /*
    brute force : i generated all substrings and then checked if the freq of three is there but is giving me MLE
    optimal approach : lets use sliding window and hashmap 
    */
    int numberOfSubstrings(string s) {
        int n = s.length();

        int res = 0;

        unordered_map<char , int> mp;

        int i = 0 , j = 0;

        while(j < n){
            mp[s[j]]++;
            while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0){
                res += n - j;
                mp[s[i]]--;
                i++;
            }
            j++;
        }

        return res;

       
    }
};