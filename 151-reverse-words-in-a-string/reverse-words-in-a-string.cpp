class Solution {
public:
    string reverseWords(string s) {
        
        //Using stringstream Library
        // stringstream ss(s);
        // string token = " ";

        // string result = "";

        // while(ss >> token){
        //     result = token + " " + result;
        // }
        // return result.substr(0 ,result.length()-1);

        // Two - pointer
        int n = s.length();

        reverse(s.begin() , s.end());
        int i = 0 ,l = 0 ,r =0 ;

        while(i < n ){
            while(i < n && s[i] != ' '){
                s[r++] = s[i++];
            }
            if(l < r){
                reverse(s.begin()+l , s.begin()+r);
                 s[r] = ' ';
                r++;

                l = r;
            }
            i++;
        }
        s = s.substr(0 , r-1);
        return s;
    }
};