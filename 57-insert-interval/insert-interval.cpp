class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //Approach 1 - brute force

        // intervals.push_back(newInterval);

        // sort(intervals.begin() , intervals.end());
        // vector<vector<int>> merged;

        // for(int i = 0 ; i < intervals.size() ; i++){
        //     if(merged.empty() || merged.back()[1] < intervals[i][0]){
        //         merged.push_back(intervals[i]);
        //     }
        //     else{
        //         merged.back()[1] = max(merged.back()[1] , intervals[i][1]);
        //     }
        // }

        // return merged;

        //Approach 2 - Optimal 
        int n = intervals.size();

        vector<vector<int>> merged;

        int i = 0;
        while(i < n && intervals[i][1] < newInterval[0]){
            merged.push_back(intervals[i]);
            i++;
        }

        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0] , intervals[i][0]);
            newInterval[1] = max(newInterval[1] , intervals[i][1]);
            i++;
        }

        merged.push_back(newInterval);

        while(i < n){
            merged.push_back(intervals[i]);
            i++;
        }


        return merged;
    }
};