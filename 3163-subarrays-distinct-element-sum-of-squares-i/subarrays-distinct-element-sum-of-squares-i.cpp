class Solution {
public:
    int dist(vector<int>& temp){
        unordered_map<int , int> mp;

        for(int &num : temp){
            mp[num]++;
        }

        return mp.size();
    }
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sq = n;


        for(int i = 0 ; i < n ; i++){
            vector<int> temp;
            temp.push_back(nums[i]);
            for(int j =  i +  1 ; j < n ; j++){
               temp.push_back(nums[j]);
               int curr = dist(temp);
               sq += (curr * curr);
            }
        }

        return sq;

    }
};