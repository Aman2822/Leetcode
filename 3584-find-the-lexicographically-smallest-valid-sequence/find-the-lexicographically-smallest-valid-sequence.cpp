class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // we are creating a vector because we have to check if we can change the character
        vector<int> rightHandSideMatchLength(n, 0);

        int i = n - 1, j = m - 1;
        int rightMatched = 0;

        // Traverse through word1
        while (i >= 0 ) {
            if ( j >= 0 && word1[i] == word2[j]) {
                rightMatched++;
                j--;
            }
            rightHandSideMatchLength[i] = rightMatched;
            i--;
        }

        bool canChange = true;
        vector<int> seq;

        int k = 0 , l = 0;

       // Now check through the sequence and we can evaluate the condition from rightHandSideMatchLength
       // that we have to take the index or we have to move further 
        while(k < n && l < m){
            if(word1[k] == word2[l]){
                seq.push_back(k);
                l++;
            }
            else if(canChange == true &&  k+1 < n && rightHandSideMatchLength[k+1] >= m-l-1){
                seq.push_back(k);
                l++;
                canChange = false;
            }
            k++;
        }

        if(l == m) return seq;
        else return {};

    }
};