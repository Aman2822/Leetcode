class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int i = 0 , j = 1;
        vector<int> altitude(n+1);
        altitude[0] = 0;
        int max_altitude = 0;

        for(int i = 0 ; i < n;i++){
            altitude[i+1] = altitude[i] + gain[i];
            max_altitude = max(max_altitude , altitude[i+1]);
           
        }       
        return max_altitude;
    }
};