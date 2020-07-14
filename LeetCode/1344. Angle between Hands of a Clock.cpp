/*

Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.

*/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double MA = 6 * minutes;
        double HA = (hour % 12 + minutes / 60.0) * 30;

        double diff = abs(HA - MA);
        return min(diff, 360 - diff);
        
    }
};
