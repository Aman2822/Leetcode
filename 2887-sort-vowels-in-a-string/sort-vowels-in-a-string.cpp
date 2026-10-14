class Solution {
public:
    string sortVowels(string s) {

        //Approach 1 - Sorting

        int n = s.length();
        set<int> ascii = {65, 69, 73, 79, 85, 97, 101, 105, 111, 117};

        vector<int> vowels;
        // vector<int> indices;

        for (int i = 0; i < n; i++) {
            int val = s[i];
            if (ascii.contains(val)) {
                vowels.push_back(val);
                // indices.push_back(i);
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

        //Approach 2 - using frequency map

        // int count[128] = {0};

        // auto isVowel = [](char c){
        //     char lower = tolower(c);
        //     return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
        // };

        // for(char &ch : s){
        //     if(isVowel(ch)){
        //         count[ch]++;
        //     }
        // }

        // int j = 0;
        // for(int i = 0 ; i < s.length() ; i++){
        //     if(isVowel(s[i])){
        //         while(count[j] == 0){
        //             j++;
        //         }
        //         s[i] = j;
        //         count[j]--;
        //     }
        // }

        // return s;
    }
};