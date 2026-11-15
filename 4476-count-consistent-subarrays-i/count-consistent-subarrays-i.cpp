class Solution {
public:
    bool solve(vector<int> temp){
        int n = temp.size();

        int mini = *min_element(temp.begin() , temp.end());

        int an = -1; //-1 because it is 1111111 and -1 is 000001

        for(int i = 0 ; i < n ; i++){
            an = an & temp[i];
        }

        return an == mini;
    }
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int res = n;

        vector<vector<int>> arr;

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
            bool flag = solve(arr[i]);
            if(flag) res++;
        }

        return res;
    }
};