class Solution {
public:
    bool winnerSquareGame(int n) {

        // Bottom up Approach - Recursion
        //Cache of t for precompute subproblems
        vector<bool> t(n+1 , false);

        t[0] = false; // Base case if n == 0 alice loses

        for(int i = 1 ; i < n+1 ; i++){
            for(int k = 1 ; k*k <= i ; k++){

                //It calculates for the opponent 
                if(t[i-(k*k)] == false){
                    t[i] = true;
                    break;
                }
            }
        }
        return t[n];
    }
};