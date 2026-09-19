class Solution {
public:
    /*
    Sliding window when the array is equal to target push it the size of array and  if its greater than increment i 

    */
    int minSumOfLengths(vector<int>& arr, int target) { 
        int n = arr.size();
        

        int i = 0;
        int j = 0;
        int currsum = 0;

        int result = INT_MAX;
        int bestMin = INT_MAX;

        //keep a track for indices before i
        vector<int> minIdxtill(n , INT_MAX);

        while(j < n){
           currsum += arr[j];

           while(i < j && currsum > target){
            currsum -= arr[i++];
           }

           if(currsum == target){
            int len = j - i + 1;
            if(i > 0 && minIdxtill[i-1] != INT_MAX){
                result = min(result , len + minIdxtill[i-1]);
            }

            bestMin = min(bestMin , len);
           }

           minIdxtill[j] = bestMin;
           j++;
        }

        return result == INT_MAX ? -1 : result;

        
    }
};