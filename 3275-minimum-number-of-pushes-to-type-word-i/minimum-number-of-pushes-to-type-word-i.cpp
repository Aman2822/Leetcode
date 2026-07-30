class Solution {
public:
    int minimumPushes(string word) {
        int l = word.length();
        int cost = 0;
        int count = 0 , opn_cost = 1;

        for(int i = 0 ; i < l ; i++){
            count++;
            if(count > 8){
                opn_cost++;
                count = 1;
            }
            cost += opn_cost;
        }

        
        return cost;


    }
};