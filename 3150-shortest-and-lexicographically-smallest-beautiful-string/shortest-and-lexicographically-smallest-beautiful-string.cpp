class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l = s.length();
        // unordered_map<int ,int> mp;  //Sliding Window and Hashmap
        // vector<string> beautiful;

        // int i = 0 , j = 0;

        // while(j < l){
        //     mp[s[j]]++;

        //     while( i < j && mp.count(1) > k){
        //         mp[s[i]]--;
        //         i++;
        //     }

        //     if(mp.count(1) == k){
        //       string res = s.substr(i , j-i+1);

        //     }
        //     j++;
        // }

        // for(int i = 0 ; i < beautiful.size() ; i++){
        //     cout << beautiful[i] << " ";
        // }

        // return s;

        for (int len = k; len <= l; len++) { // k size ka string toh chahiye
            string result = "";

            for (int j = 0; j <= l - len; j++) {
                string temp = s.substr(j, len); // substring

                int ones = 0;
                for (char& ch : temp) {    //for count 1's
                    ones += (ch == '1') ? 1 : 0;
                }

                if (ones == k) {   //If ones count=k then  result is empty we can add or smaller than result
                    if (result.empty() || temp < result) {
                        result = temp;
                    }
                }
            }
            if(!result.empty()) return result;     //whenever we found the result we should it because it is lexicographically smaller than future one

        }

        return "";
    }
};