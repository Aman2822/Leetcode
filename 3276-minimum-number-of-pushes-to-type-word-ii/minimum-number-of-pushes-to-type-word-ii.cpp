class Solution {
public:
    int minimumPushes(string word) {
        int l = word.length();
        vector<int> push(26,0);
        int cost = 0;

        for(char &ch: word){
            push[ch -'a']++;
        }
        
        sort(push.begin() ,push.end() , greater<int>());

        for(int i = 0 ; i < 26 ; i++){
            int freq = push[i];
            int press = (i / 8) + 1;
            cost += (freq * press);
        }

        return cost;



    }
};