class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l = s.length();
        //Sliding Window and Hashmap
        string beautiful = "";

        int i = 0 , j = 0;
        int ones = 0;

        while(j < l){
            if(s[j] == '1'){
                ones++;
            }

            // Shrinking logic when ones is greater than k then shrink down upto we see 0
            while(ones > k || s[i] == '0'){ 
                if(s[i] == '1') ones--;
                i++;
            }
    
            if(ones == k){
                string temp = s.substr(i , j-i+1);
                if(beautiful.empty() || beautiful.length() > j-i+1 || 
                (temp.length() == beautiful.length() &&  temp < beautiful)){
                    beautiful = temp;
                }
            }
            j++;
        }


        return beautiful;

        //Brute Force - TC = O(N*N*N)

        // for (int len = k; len <= l; len++) { // k size ka string toh chahiye
        //     string result = "";

        //     for (int j = 0; j <= l - len; j++) {
        //         string temp = s.substr(j, len); // substring

        //         int ones = 0;
        //         for (char& ch : temp) {    //for count 1's
        //             ones += (ch == '1') ? 1 : 0;
        //         }

        //         if (ones == k) {   //If ones count=k then  result is empty we can add or smaller than result
        //             if (result.empty() || temp < result) {
        //                 result = temp;
        //             }
        //         }
        //     }
        //     if(!result.empty()) return result;     //whenever we found the result we should it because it is lexicographically smaller than future one

        // }

        // return "";
    }
};