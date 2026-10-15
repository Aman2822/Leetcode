class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        //Sorted according to there end time
        sort(intervals.begin() , intervals.end() , [](vector<int>& a , vector<int>& b){
            return a[1] < b[1];
        });

        int freetime = intervals[0][1];
        int cnt = 0;
        

        //if last end time is greter than or equal to next interval start then its not overlapping
        for(int i = 1 ; i < n ; i++){
            if(freetime <= intervals[i][0]){
                cnt++;
                freetime = intervals[i][1];
            }
        }

        return n - cnt - 1;

    }
};