class Solution {
public:
    int helper(string &s , int i , long long num , int sign){
        //This function with return when the pointer is out of bounds or whenever is nota digit
        if(i > s.size() || !isdigit(s[i])){
            return (int)(sign * num);
        }
        
        //If it is a digit 
        num = num*10 + (s[i] - '0');

       //Whenever greater than int 
        if(sign * num <= INT_MIN) return INT_MIN;
        if(sign * num >= INT_MAX) return INT_MAX;

        // Recurse for next character
        return helper(s , i+1 , num , sign);
    }
    int myAtoi(string s) {
        int l = s.length();
        int i = 0;
        
        //This will handle leading whitespaces
        while(i < l && s[i] == ' ' )i++;

        //Handling  '+' and '-' sign
        int sign = 1;
        if(i < l &&  (s[i] == '-' || s[i] == '+')){
            sign = (s[i] == '-')? -1:1;
            i++;
        }

        return helper(s,i , 0 , sign); //For digit and char we are passing string s , pointer  , num = 0 , sign that is


    }
};