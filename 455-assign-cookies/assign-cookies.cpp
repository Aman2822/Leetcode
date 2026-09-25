class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g) , end(g));
        sort(begin(s) , end(s));

        // int n = s.size();
        // int m = g.size();
        // int ans = 0;
        // int i = 0 , j = 0;

        // while( i < n && j < m){
        //     if(g[i] >= s[j]){
        //         ans++;
        //         i++;
        //         j++;
        //     }
        //     else if(s[i] < g[j]){
        //         j++;
        //     }
        // }

        // return ans;

        int ans = 0;
        int n = g.size();
        int m = s.size();

        int i = 0 , j = 0;

        while(i < n && j < m){
            // cout << s[i] <<  " " << g[j] << endl;
            if(g[i] <= s[j]){
                ans++;
                i++;
            }
            j++;
        }

        return ans;
    }
};