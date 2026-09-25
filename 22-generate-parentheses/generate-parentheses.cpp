class Solution {
public:
    vector<string> result;

    bool isValid(string& str){
        int cnt = 0;

        for(char &ch : str){
            if(ch == '('){
                cnt++;
            }
            else{
                cnt--;
            }

            if(cnt < 0) return false;
        }

        return cnt == 0;
    }

    void solve(string& s , int n){
        if(s.length() == 2*n){
            if(isValid(s)){
                result.push_back(s);
            }
            return;
        }

        //Two possilibilites

        //open bracket
        s.push_back('(');
        solve(s , n);
        s.pop_back();

        //close bracket
        s.push_back(')');
        solve(s , n);
        s.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        string curr = "";

        solve(curr , n);

        return result;
    }
};