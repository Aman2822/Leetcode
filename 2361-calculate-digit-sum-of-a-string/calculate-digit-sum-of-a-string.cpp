class Solution {
public:
    string sum(string &s){
        int n = s.length();
        int total = 0;
        
        for(char &ch : s){
           total += ch - '0';
        }

        return to_string(total);
    }

    
    string solve(string &temp , int k){
        int n = temp.length();
        string ans = "";
        
        int i = 0;

        while(i < n){
            string s = "";
            int p = k;
            while( i < n && p > 0){
                s += temp[i];
                p--;
                i++;
            }
            ans += sum(s);
        }

        return ans;

    }
    string digitSum(string s, int k) {
        int n = s.length();
        string temp = s;

        while(temp.length() > k){
            temp = solve(temp , k);
        }

        return temp;
    }
};