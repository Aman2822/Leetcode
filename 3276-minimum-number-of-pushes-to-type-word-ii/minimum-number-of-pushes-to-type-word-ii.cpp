class Solution {
public:
    int minimumPushes(string word) {
        vector<int> push(26,0);
        int cost = 0;

        for(char &ch: word){
            push[ch -'a']++;
        }
        
        sort(push.begin() ,push.end() , greater<int>());  // For descending sort of array

        for(int i = 0 ; i < 26 ; i++){
            int freq = push[i];
            int press = (i / 8) + 1;
            cost += (freq * press);
        }

        return cost;



    }
};