class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int n = words.size();
        int ans = 0 ;

        for(int i = left ; i <= right ; i++){
            int p = words[i].size();

            if((words[i][0] == 'a' || words[i][0] == 'e' || words[i][0] == 'i' || words[i][0] == 'o' || words[i][0] == 'u') &&
            (words[i][p-1] == 'a' || words[i][p-1] == 'e' || words[i][p-1] == 'i' || words[i][p-1] == 'o' || words[i][p-1] == 'u')){
                
                ans++;
            }
        }

        return ans;
    }
};