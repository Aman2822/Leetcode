class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = n-1;
        set<float> average_distinct;

        while( i < j){
        float average_no = (nums[i]+nums[j])/2.0;
        average_distinct.insert(average_no);
        i++;
        j--;
        }
        int p = average_distinct.size();
        return p;


    }
};