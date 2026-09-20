class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();

        // //Make a pair of char and there value and store them in 2d array
        // vector<pair<char,int>> values;
        // int i = 0;

        // for(int k = 26; k >= 1 ; k-- ){
        //     char ch = 'a' + i;
        //     values.push_back({ch , k});
        //     i++;
        // }

        // unordered_map<char , int> mp(values.begin() , values.end());
        long long prod = 0;
        // for(int i = 0 ; i < n ; i++){
        //   int val = mp[s[i]];
        //   prod += (val * (i+1));
        // }

        // return prod;




        //One more approach
        
        for(int i = 0 ; i < n ; i++){
            prod += (i+1) * (26 - (s[i] - 'a'));
        }

        return prod;

    }
};