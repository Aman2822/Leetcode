class Solution {
public:
    int maxDepth(string s) {
        int l = s.length();
        int cnt = 0;
        int max_cnt = INT_MIN;
        int leftBracket = 0 , rightBracket = 0;

        for(int i = 0 ; i < l ; i++){
            if(s[i] == '(') leftBracket++;
            else if(s[i] == ')') rightBracket++;
            int count = leftBracket - rightBracket;
            max_cnt = max(max_cnt , count);
        }
        return max_cnt;

    
    }
};