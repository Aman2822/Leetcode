class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();
        int vec[26] = {0};

        for(char &ch : s){
            vec[ch - 'a']++;
        }

        int max_dist = -1;

        for(int i = 0 ; i <26 ; i++){
            if(vec[i] > 1){
               int first = -1 , last = -1;
               for(int j = 0 ; j < n ; j++){
                if(s[j] == i + 97 ){
                    if(first == -1) first = j;
                    last = j;
                }
               }
               max_dist = max(max_dist , last - first - 1);
            }
        }

        return max_dist;
    }
};