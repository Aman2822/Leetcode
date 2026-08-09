class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        int i = 0 , j = 0;

        while(j < m){
            if(i < n && s[i] == t[j]){
                i++;
            }
            j++;
        }

        if(i == n) return true;
        else return false; 
    }
};