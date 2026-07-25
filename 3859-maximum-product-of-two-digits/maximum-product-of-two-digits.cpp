class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        sort(s.begin() , s.end());
        int p = s.length();

        int last_digit = s[p-1] - '0';
        int second_last_digit =  s[p-2] - '0';

        return last_digit * second_last_digit;

    }
};