class Solution {
public:
    /* lets just make the keypad using hashmap
     */
    vector<string> res;

    void solve(string &digits , string temp , int i , unordered_map<char ,string> &mp){
        int n = digits.length();

        if(i >= n){
            res.push_back(temp);
            return;
        }

        char ch = digits[i];
        //nikalna hai ki digit ke map characters
        string str = mp[ch];

        for(int k = 0 ; k < str.length() ; k++){
            temp.push_back(str[k]);  //do
            solve(digits , temp , i+1 , mp); //explore in an another digit
            temp.pop_back(); //undo
        }

    }
    vector<string> letterCombinations(string digits) {
       
       unordered_map<char , string> mp;

       mp['2'] = "abc";
       mp['3'] = "def";
       mp['4'] = "ghi";
       mp['5'] = "jkl";
       mp['6'] = "mno";
       mp['7'] = "pqrs";
       mp['8'] = "tuv";
       mp['9'] = "wxyz";

       solve(digits , "" , 0 , mp);

       return res;
    }
};