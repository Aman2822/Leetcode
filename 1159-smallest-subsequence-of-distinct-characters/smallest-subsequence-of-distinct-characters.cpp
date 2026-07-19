class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        string ans = "";
        vector<int>last_index(26 ,0);
        vector<bool> visited(26, false);

        for(int i = 0 ; i < n ; i++){
            last_index[s[i] - 'a'] = i;
        }

        for(int i = 0; i < n ;i++){
            char curr = s[i];

            if(visited[curr -'a'] == 1){
                continue;
            }

            while(ans.length() > 0 && ans.back() > curr && last_index[ans.back() -'a'] > i){
                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans += curr;
            visited[curr -'a'] = true;
        }
        return ans;


    }
};