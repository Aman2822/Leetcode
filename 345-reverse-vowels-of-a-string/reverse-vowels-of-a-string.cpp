class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a' , 'e' ,'i' ,'o' ,'u', 'A', 'E','I','O','U'};
        int i = 0 , j = s.length() - 1 ;

        while(j > i){
            if(vowels.count(s[i]) && vowels.count(s[j])){
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }
            else if(vowels.count(s[i])){
                j--;
            }
            else{
                i++;
            }
        }
        return s;
    }
};