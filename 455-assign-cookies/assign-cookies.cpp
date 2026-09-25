class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g) , end(g));
        sort(begin(s) , end(s));

        int ans = 0;
        int n = g.size();
        int m = s.size();

        int i = 0 , j = 0;

        while(i < n && j < m){
            //whenever the greed of a student is less than current cookie then 
            //increment  g[i] pointer and and increment the ans
            if(g[i] <= s[j]){
                ans++;
                i++;
            }
            j++;
        }

        return ans;
    }
};