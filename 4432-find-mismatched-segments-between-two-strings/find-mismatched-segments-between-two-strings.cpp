class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n = s1.length();
        vector<vector<string>> res;

        for (int i = 0; i < n; i++) {
            bool flag = false;
            if (s1[i] != s2[i]) {
                flag = true;
                string temp1 = "";
                string temp2 = "";
                while (flag) {
                    temp1 += s1[i];
                    temp2 += s2[i];
                    i++;
                    if(s1[i] == s2[i]){
                        flag = false;
                        break;
                    }
                }
                res.push_back({temp1 , temp2});
            }
        }

        return res;
    }
};