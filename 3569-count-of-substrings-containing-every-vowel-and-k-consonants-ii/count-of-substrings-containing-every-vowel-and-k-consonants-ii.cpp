class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        long long count = 0;
        unordered_map<char , int> mp;

        //Checking for vowel 
        auto isVowel = [](char &ch){
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };

        //Consonant count bana na hai next consonant kab hai uska 
        vector<int> nextConso(n);
        int lastidx = n;
        for(int i = n - 1 ; i >=0 ; i--){
            nextConso[i] = lastidx;
            if(!isVowel(word[i])){
                lastidx = i;
            }
        }

        //Now use sliding window
        int i = 0 , j = 0;
        int consonant = 0;
        while(j < n){
            char ch = word[j];
            if(isVowel(ch)){
                mp[ch]++;
            }
            else consonant++;

            //When consonant > k
            while(i < j && consonant > k){
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }
                }
                else{
                    consonant--;
                }
                i++;
            }

            while(i < j && mp.size() == 5 && consonant == k){
                count += nextConso[j] - j;
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }
                }
                else{
                    consonant--;
                }
                i++;
            }

            j++;
        }

        return count;

    }
};