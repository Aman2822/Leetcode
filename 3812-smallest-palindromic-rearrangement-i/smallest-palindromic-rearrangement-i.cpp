class Solution {
public:
    string smallestPalindrome(string s) {
        // vector<int> freq(26, 0);
        // int p = s.length();

        // if (p == 1)
        //     return s;

        // for (char ch : s) {
        //     freq[ch - 'a']++;
        // }

        // string first_part = "", odd_ele = "";

        // for(int i = 0 ; i < freq.size() ; i++){
        //     if(freq[i] % 2 != 0){
        //         char letter = 'a' + i;
        //         int count = freq[i];
        //         string temp = string(count , letter);
        //         odd_ele += temp;
        //     }
        // }

        // for (int i = 0; i < freq.size(); i++) {
        //     if (freq[i] % 2 == 0) {
        //         while(freq[i] > 0){
        //            char ch = 'a' + i;
        //            first_part += ch;
        //            freq[i] = freq[i]/2;
        //         }
        //     }
        // }
        // string ans = first_part + odd_ele + reverse(first_part.begin(), first_part.end());
        // return ans;

        int p = s.length();

        int mid = p/2;

        sort(begin(s) , begin(s) + mid);

        for(int  i = 0 ; i < mid ; i++){
            s[p-1-i] = s[i];
        }

        return s;
       
    }
};