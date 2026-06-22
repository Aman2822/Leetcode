class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int t[26] = {0};
        for(char ch : s){
            t[ch - 'a']++;
        }
        
        int targ[26] = {0};
        for(char ch : target){
            targ[ch - 'a']++;
        }

        int count = INT_MAX;

        for(int i = 0 ; i < 26 ;i++){
           if(targ[i]> 0){
              int possible_Copies = t[i] / targ[i];
             count = min(count, possible_Copies);
           }
        }


       return count; 
    }
};