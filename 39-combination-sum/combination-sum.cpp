class Solution {
public:
    /*
    agar array 
    */
    vector<vector<int>> res;

    bool freq(vector<int>& temp){
        int n = temp.size();
        unordered_map<int , int> mp;

        for(int &num : temp){
            mp[num]++;
        }

        if(mp.size() == 1) return true;
        vector<int> fre;
        
        for(auto it : mp){
           fre.push_back(it.second);
        }

        for(int i = 1 ; i < fre.size() ; i++){
           if(fre[i] != fre[i-1]) return true;
        }

        return true;
    }

    void solve(vector<int>& candidates , int i , int sum ,  vector<int>& temp , int target){
        int n = candidates.size();

        if(i >= n || sum > target){
            return;
        }
        else if(sum == target){
            bool check = freq(temp);
            if(check){
                res.push_back(temp);
            }
            return;
        }


        //recursion
        temp.push_back(candidates[i]);
        solve(candidates , i , sum + candidates[i] , temp , target);
        temp.pop_back();


        solve(candidates , i+1 , sum , temp , target);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;

        solve(candidates , 0 , 0 ,  temp , target);
        return res;
    }
};