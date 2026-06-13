class Solution {
public:
    int maxPower(string s) {
        int n = s.length();
        int count = 1;
        int maxcount = 1;

        for(int i = 1; i < n; i++){
           if(s[i] == s[i-1]){
            count++;
            if(count > maxcount){
                maxcount++;
            }
           }
           else{
            count = 1;
           }
        }
        return maxcount;
    }
};