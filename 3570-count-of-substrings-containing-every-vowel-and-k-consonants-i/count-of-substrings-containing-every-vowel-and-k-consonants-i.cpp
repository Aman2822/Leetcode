class Solution {
public:
    bool isVowel(char &ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    };

    bool contain(string &s , int k){
        int n = s.length();
        // unordered_map<char , int> mp;
        int conso = 0;

        for(int i = 0 ; i < n ; i++){
            if(!isVowel(s[i])){
                conso++;
            }
        }

        if(conso == k) return 1;

        return 0;
    }


    int countOfSubstrings(string word, int k) {
        int n = word.length();
        int res = 0;
        
        for(int i = 0 ; i + 4 < n ; i++){
            string temp = "";
            unordered_map<char, int> mp;

            for(int j = i ; j < n ; j++){
                if(isVowel(word[j])){
                    mp[word[j]]++;
                }
                temp.push_back(word[j]);
                if(mp.size() == 5 && temp.length() > 4){
                    res += contain(temp , k);
                }
            }
        }

        return res;
    }
};