class Solution {
public:
    int firstMatchingIndex(string s) {
        int n = s.length();
        int i = 0 , j = n - 1;

        while(j >= i){
            if(s[i] == s[j]){
                return i;
            }
            i++;
            j--;
        }
        return -1;
    }
};