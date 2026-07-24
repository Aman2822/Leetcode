class Solution {
public:
    int romanToInt(string s) {
        int l = s.length();
        unordered_map<char,int> roman = {{'I', 1}, {'V' , 5} ,{'X',10}, {'L',50}, {'C', 100},{'D', 500}, {'M',1000}};
        int ans = 0;
        int max_val = INT_MIN;

        for(int i = l - 1 ; i >= 0 ; i--){
            int curr = roman[s[i]];

            if(curr < max_val){
                ans -= curr;
            }
            else{
                ans+= curr;
                max_val = curr;
            }
        }
        return ans;
    }
};