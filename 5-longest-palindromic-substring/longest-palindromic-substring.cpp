class Solution {
public:
    
    //Recursive way of checking palindrome
    //Lets memomize this because there are overlapping subproblems

    //Declare a 2d cache table
    int t[1001][1001];

    bool solve(string &s , int i , int j){
        if(i >= j){
            return 1;
        }
        
        //Cache look up
        if(t[i][j] != -1){
            return t[i][j];
        }
        
        //Saving states 
        if(s[i] == s[j]){
            return  t[i][j] = solve(s , i+1 , j-1);
        }

        return t[i][j] = 0;
    }


    string longestPalindrome(string s) {
        int n = s.length();
        int max_len = INT_MIN;
        int start = 0;

        //Initalize memset with -1
        memset(t , -1 , sizeof(t));

        for(int i = 0  ; i < n ; i++){
            for(int j = i ; j < n ; j++){
               if(solve(s, i , j)){
                if(j-i+1 > max_len){
                    max_len = j - i + 1;
                    start = i;
                }
               }
            }
        }

        return s.substr(start , max_len);


    }
};