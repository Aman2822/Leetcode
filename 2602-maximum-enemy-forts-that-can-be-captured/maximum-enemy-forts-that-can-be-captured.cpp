class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size();
        int maxcount = 0;
        int lastIndexmark = -1;

        for(int i = 0 ; i < n ;i++){
            if(forts[i] == -1 || forts[i] == 1){
                if(lastIndexmark!= -1 && forts[lastIndexmark] != forts[i]){
                    int currentcaptured = i - lastIndexmark -1;
                    maxcount = max(currentcaptured, maxcount);
                }
                lastIndexmark = i;
            }
        }

        return maxcount;



    }
};