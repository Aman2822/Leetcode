class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged_Intervals;
 
        // Brute force

        // for (int i = 0; i < n; i++) {
        //     int start = intervals[i][0];
        //     int end = intervals[i][1];

        //     if (!merged_Intervals.empty() && end <= merged_Intervals.back()[1]) {
        //         continue;
        //     }

        //     for (int j = i + 1; j < n; j++) {
        //         if(intervals[j][0] <= end){
        //             end = max(end, intervals[j][1]);
        //         }
        //         else{
        //             break;
        //         }
        //     }
        //     merged_Intervals.push_back({start , end});
        // }
        // return merged_Intervals;

        //Optimize approach 
        for(int i = 0 ; i < n ; i++){
            if(merged_Intervals.empty() || intervals[i][0] > merged_Intervals.back()[1]){
                merged_Intervals.push_back(intervals[i]);
            }
            else{
                merged_Intervals.back()[1] = max(merged_Intervals.back()[1] , intervals[i][1]);
            }
        }
        return merged_Intervals;
    }
};