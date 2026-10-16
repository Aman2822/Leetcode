class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        //Approach 1 - Brute force : make a vector to store end times and search the next start time in that vector end time 
        // int n = intervals.size();
        // vector<int> groups;

        // sort(intervals.begin() , intervals.end());

        // groups.push_back(intervals[0][1]);

        // for(int i = 1 ; i < n ; i++){
        //     bool flag = false;
        //     for(int j = 0; j < groups.size() ; j++){
        //         if(groups[j] < intervals[i][0]){
        //             flag = true;
        //             groups[j] = intervals[i][1];
        //             break;
        //         }
        //     }
        //     if(flag == false){
        //         groups.push_back(intervals[i][1]);
        //     }
        // }

        // int m = groups.size();

        // return m;


        //Approach 2 - Using min heap instead of array because min heap always keep smaller value on top

        sort(intervals.begin() , intervals.end());

        priority_queue<int , vector<int> , greater<int>> groups;

        for(vector<int>& interval : intervals){
            int start = interval[0];
            int end = interval[1];

            if(!groups.empty() && start > groups.top()){
                groups.pop();
            }

            groups.push(interval[1]);
        }

        return groups.size();
    }
};