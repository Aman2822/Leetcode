class Solution {
public:
    int countOverlaps(vector<vector<int>>& img1, vector<vector<int>>& img2 , int rowOff , int colOff){
        int n = img1.size();

        /* Now we have to know the indices for it :
        A[i][j] = B[i+rowOff][j+colOff] if it is valid index then we can check it is overlapped 1 on both matrices
        */

        int count = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){

                int B_i = i+rowOff;
                int B_j = j + colOff;

                if(B_i < 0 || B_i > n-1 || B_j < 0 || B_j > n-1){
                    continue;
                }

                if(img1[i][j] == 1 && img2[B_i][B_j] == 1){
                    count++;
                }
            }
        }

        return count;

    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        /* For n = 2 -> the overlaps are for rowoffset = -1 , 0 , 1 and then for each there are coloffset = -1,0,1
        So we generalize -n+1 to n+1
        */

        int maxOverlap = 0;

        for(int rowOff = -n+1 ; rowOff <= n + 1  ; rowOff++){
            for(int colOff = -n+1 ; colOff <= n + 1 ; colOff++){
                
                int count = countOverlaps(img1 , img2 , rowOff , colOff);

                maxOverlap = max(maxOverlap , count);
            }
        }

        return maxOverlap;
    }
};