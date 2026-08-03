class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int a_cnt = 0 , b_cnt = 0;
        int i = 0 , j = n-1;

        while( i < j){
            if(piles[i] > piles[j]){
                a_cnt += piles[i];
                i++;
            }
            else{
                a_cnt += piles[j];
                j--;
            }
            if(piles[i] > piles[j]){
                b_cnt += piles[j];
                i++;
            }
            else{
                b_cnt += piles[i];
                j--;
            }
        }

        if(a_cnt > b_cnt ) return true;
        else return false;


    }
};