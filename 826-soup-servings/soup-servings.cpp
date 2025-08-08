class Solution {
public:
    vector<pair<int,int>> serves = {{100,0},{75,25},{50,50},{25,75}};
    
    vector<vector<double>> memo ;

    double solution(double A, double B){
        if(A<=0 && B<=0){
            return 0.5;
        }

        if(A<=0){
            return 1.0;
        }
        
        if(B<=0){
            return 0.0;
        }
        if (memo[A][B] != -1.0) {
            return memo[A][B];
        }
        double prob = 0.0;

        for(auto &p:serves){
            int A_taken = p.first;
            int B_taken = p.second;

            prob += solution(A-A_taken , B-B_taken);
        }
         return memo[A][B] = 0.25 * prob;

    }
    double soupServings(int n) {

         if(n>=5000){
            return 1;
        }

        memo.resize(n + 1, vector<double>(n+1,-1.0));
       
        return solution(n,n);
    }
};