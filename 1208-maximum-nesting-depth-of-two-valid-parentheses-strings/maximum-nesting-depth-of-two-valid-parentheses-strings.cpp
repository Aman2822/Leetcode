class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();

        vector<int> ans(n);
        int depth = 0;

        for(int i = 0 ; i  < n ; i++){
            if(seq[i] == '('){
                depth++;
                if(depth & 1) ans[i] = 1;
                else ans[i] = 0;
            }
            else{
                if(depth & 1) ans[i] = 1;
                else ans[i] = 0;
                depth--;
            }
        }

        return ans;
    }
};