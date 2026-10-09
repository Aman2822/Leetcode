class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxsum = 0 , lsum = 0 , rsum = 0;
        
        //Jitna ka window lena hai pehle left se le lete hai and usko max mei store kar denge
        for(int i = 0 ; i < k ; i++){
            lsum += cardPoints[i];
        }

        maxsum = lsum;
        
        //Aab ek ek index left hatayege and right ek index add karenge and dono ka sum leke max karege 
        int rightIdx = n-1;
        for(int i = k - 1 ; i >= 0 ; i--){
           lsum -= cardPoints[i];
           rsum += cardPoints[rightIdx];
           rightIdx--;

           maxsum = max(maxsum ,  lsum + rsum);
        }

        return maxsum;

    }
};