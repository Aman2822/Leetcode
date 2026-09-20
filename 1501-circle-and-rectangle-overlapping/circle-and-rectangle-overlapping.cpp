class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        
        //Nearest pointer to the circle find and then calculate the distance between the points and centre of the circle is if its less than equal to radius then its overlapping

        int xi , yi;

        //for x-coordinate
        if(x1 > xCenter) xi = x1;
        else if(x2 < xCenter) xi = x2;
        else xi = xCenter;

        //for y cordinates
        if(y1 > yCenter) yi = y1;
        else if(y2 < yCenter) yi = y2;
        else yi = yCenter;

        //Calculate distance 
        return sqrt((xi - xCenter) * (xi - xCenter) + (yi - yCenter) * ( yi - yCenter)) <= radius;
    }
};