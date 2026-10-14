class Solution {
public:
    string sortVowels(string s) {
        int n = s.length();
        set<int> ascii = {65, 69, 73, 79, 85, 97, 101, 105, 111, 117};

        vector<int> vowels;
        vector<int> indices;

        for (int i = 0; i < n; i++) {
            int val = s[i];
            if (ascii.contains(val)) {
                vowels.push_back(val);
                indices.push_back(i);
            }
        }

        sort(vowels.begin() , vowels.end());

        int j = 0;
        for(int i = 0 ; i < n ; i++){
            int val = s[i];
            if(ascii.contains(val)){
                s[i] = vowels[j];
                j++;
            }
        }

        return s;
    }
};