class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int,int> mpp;

        if(n == 0) return {};

        int m = temp.size();
        int assign  = 1;
        
        int org_temp = temp[0] ;
  
        for(int i = 0 ; i < m ; i++){
            if(i == 0){
               temp[0] = 1;
            }
           else if(org_temp!= temp[i]){
             assign++;
             org_temp = temp[i];
             temp[i] = assign;
           }
           else{
            temp[i] = assign;
           }    
           mpp[org_temp] = assign; 
        }

        for(int i = 0 ; i < n ;i++){
            arr[i] = mpp[arr[i]];
        }
        return arr;
       


        
        
    }
};