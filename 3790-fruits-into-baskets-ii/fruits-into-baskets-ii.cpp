class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {\
        int n = fruits.size();
        int m = baskets.size();
        int unplaced = 0;
        vector<bool> usedbaskets(n,false);


        for(int i = 0 ; i < n ;i++){
            bool isplaced = false;
            for( int j=0; j < m ; j++){
                if(!usedbaskets[j] && fruits[i] <= baskets[j]){
                    usedbaskets[j] = true;
                    isplaced = true;
                    break;
                }
            }
            if(!isplaced){
            unplaced++;
        }
        }
       

        

        return unplaced;
    }
};