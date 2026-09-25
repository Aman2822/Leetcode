class Solution {
public:
    vector<string> result;

    // Approach 1 - All strings generated and then check valid or invalid
    //  bool isValid(string& str){
    //      int cnt = 0;

    //     for(char &ch : str){
    //         if(ch == '('){
    //             cnt++;
    //         }
    //         else{
    //             cnt--;
    //         }

    //         if(cnt < 0) return false;
    //     }

    //     return cnt == 0;
    // }

    // void solve(string& s , int n){
    //     if(s.length() == 2*n){
    //         if(isValid(s)){
    //             result.push_back(s);
    //         }
    //         return;
    //     }

    //     //Two possilibilites

    //     //open bracket
    //     s.push_back('(');
    //     solve(s , n);
    //     s.pop_back();

    //     //close bracket
    //     s.push_back(')');
    //     solve(s , n);
    //     s.pop_back();

    // }
    // vector<string> generateParenthesis(int n) {
    //     string curr = "";

    //     solve(curr , n);

    //     return result;
    // }

    // Approach 2 - only generate the strings which are valid  we will be saving time 
    // valid check time
    void solve(string& s, int n, int open, int close) {
        if (s.length() == 2 * n) {
            result.push_back(s);
            return;
        }

        // Two possilibilites

        // open bracket when open < n

        if (open < n) {
            s.push_back('(');
            solve(s, n, open + 1, close);
            s.pop_back();
        }

        // close bracket when close < open
        if (close < open) {
            s.push_back(')');
            solve(s, n, open, close + 1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";

        // int open = 0 , close = 0;

        solve(curr, n, 0, 0);

        return result;
    }
};