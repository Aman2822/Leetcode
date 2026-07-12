class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int,int> mpp;

        if(n == 0) return {};

        int m = temp.size();
        int rank  = 1;
        
        mpp[temp[0]] = rank;
  
        for(int i = 1 ; i < m ; i++){
            if(temp[i-1]!= temp[i]){
             rank++;
           }
           mpp[temp[i]] = rank; 
        }

        for(int i = 0 ; i < n ;i++){
            arr[i] = mpp[arr[i]];
        }
        return arr;
       


        
        
    }
};