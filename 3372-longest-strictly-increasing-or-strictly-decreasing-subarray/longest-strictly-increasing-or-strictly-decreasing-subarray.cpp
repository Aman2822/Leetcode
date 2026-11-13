class Solution {
public:
    int incr(vector<int> temp){
        int n = temp.size();

        for(int i = 1 ; i < n ; i++){
            if(temp[i] <= temp[i-1]) return false;
        }

        return true;
    }

    int decr(vector<int> temp){
        int n = temp.size();

        for(int i = 1 ; i < n ; i++){
            if(temp[i] >= temp[i-1]) return false;
        }

        return true;
    }

    
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> arr;
        int res = 1;

        for(int i = 0 ; i < n ; i++){
            vector<int> temp;
            for(int j = i ; j < n ; j++){
                temp.push_back(nums[j]);
                if(temp.size() > 1){
                    arr.push_back(temp);
                }
            }
        }

        for(int i = 0 ; i < arr.size() ; i++){
            bool flag = incr(arr[i]);
            if(flag){
                int m = arr[i].size();
                res = max(res , m);
            }

            flag = decr(arr[i]);
            if(flag){
                int m = arr[i].size();
                res =max(res , m);
            }
        }

        return res;
    }
};