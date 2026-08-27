class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {

        vector<vector<int>> aggregrate;
        int m = series1.size();
        int n = series2.size();

        int i = 0, j = 0;

        while (i < m && j < n) {
            if (series1[i][0] == series2[j][0]) {
                int val = series1[i][1] + series2[j][1];
                vector<int> timestamp = {series1[i][0], val};
                aggregrate.push_back(timestamp);
                i++;
                j++;
            } 
            else if (series1[i][0] <= series2[j][0]) {
                int val = series1[i][1] + series2[j][1];
                vector<int> timestamp = {series1[i][0], val};
                aggregrate.push_back(timestamp);
                i++;
            } 
            else if (series1[i][0] >= series2[j][0]) {
                int val = series1[i][1] + series2[j][1];
                vector<int> timestamp = {series2[j][0], val};
                aggregrate.push_back(timestamp);
                j++;
            }
        }

        while (i < m && aggregrate.back()[0] < series1[i][0]) {
            int val = series1[i][1] ;
            vector<int> timestamp = {series1[i][0], val};
            aggregrate.push_back(timestamp);
            i++;
        }

        while (j < n  && aggregrate.back()[0] < series2[j][0]) {
            int val = series2[j][1];
            vector<int> timestamp = {series2[j][0], val};
            aggregrate.push_back(timestamp);
            j++;
        }
        
        return aggregrate;
    }
};