class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();

        //TC - O(n) and SC = O(n)

        // stack<int> st;

        // int score = 0;

        // for(int i = 0 ; i < n ; i++){
        //     if(s[i] == '('){
        //         st.push(score);
        //         score = 0;
        //     }
        //     else{
        //         if(s[i-1] == '('){      // case  = '()'
        //             score = st.top() + 1;
        //         }
        //         else{  // case - nested
        //             score = 2 * score + st.top();
        //         }
        //         st.pop();
        //     }
        // }

        // return score;


        int score = 0;
        int depth = 0;

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                depth++;
            }
            else{
                depth--;
                if(s[i-1] == '('){
                    score += (1 << depth);
                }
            }
        }

        return score;
    }
};