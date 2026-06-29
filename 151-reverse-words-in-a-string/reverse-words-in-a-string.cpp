class Solution {
public:
    string reverseWords(string s) {
        
        //Using stringstream Library
        stringstream ss(s);
        string token = " ";

        string result = "";

        while(ss >> token){
            result = token + " " + result;
        }
        return result.substr(0 ,result.length()-1);
    }
};