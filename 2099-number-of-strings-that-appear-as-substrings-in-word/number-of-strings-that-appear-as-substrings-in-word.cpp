class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        vector<string> substrings;
        int ans = 0;

        int n = word.length();

        for(int i = 0 ; i < n ; i++){
            string temp = "";
            for(int j = i ; j < n ; j++){
                temp += word[j];
                substrings.push_back(temp);
            }
        }

        set<string> mySet(substrings.begin() , substrings.end());

        for(int i = 0 ; i < patterns.size() ; i++){
            if(mySet.contains(patterns[i])){
                ans++;
            }
        }

        return ans;
    }
};