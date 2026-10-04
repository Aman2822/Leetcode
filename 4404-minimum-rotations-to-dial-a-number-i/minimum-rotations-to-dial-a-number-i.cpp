class Solution {
public:
    int minRotations(string s) {
        int n = s.length();
        int dial = 0;
        int ptr = 0;

        for(int i = 0 ; i < n ; i++){
            if(ptr != s[i] - '0'){
                int clock = abs(ptr - (s[i] - '0'));
                int anti = 10 - clock;
                dial += min(clock , anti);
            }
            ptr = s[i] - '0';

        }

        return dial;
    }
};