class Solution {
public:
    string removeOuterParentheses(string s) {
        int l = s.length();
        int count = 0;
        string ans ;

        int i = 0;

        while(i != l){
           if(s[i] == '('){
            if(count > 0){
                ans.push_back(s[i]);
            }
            count++;
           }
            else if(s[i] == ')'){
            count--;
            if(count > 0){
                ans.push_back(s[i]);
            }
           }
           i++;

        }
        return ans;

    }
};