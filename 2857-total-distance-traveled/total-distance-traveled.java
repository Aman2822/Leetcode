class Solution {
    public int distanceTraveled(int mainTank, int additionalTank) {
        int distance = 0;
        for( int i = 1; i<= mainTank;i++){
            distance += 10;
            if( i % 5 == 0 && additionalTank>0){
                mainTank++;
                additionalTank--;
            }
        }
        return distance;
    }
}