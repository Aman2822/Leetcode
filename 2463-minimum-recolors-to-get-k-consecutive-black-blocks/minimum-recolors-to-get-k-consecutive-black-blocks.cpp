class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int recolor = INT_MAX;

        for(int i = 0 ; i + k - 1 < n ; i++){
                int w = 0;
                for(int j = i ; j < i + k ; j++){
                   if(blocks[j] == 'W') w++;
                }
                recolor = min(recolor , w);
        }

        return recolor;

        
    }
};