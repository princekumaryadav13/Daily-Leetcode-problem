class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hm = (double)(hour) + (double)((double)minutes/60);
        double hangle = hm*30;

        double mangle = minutes*6;
        double ans = abs(hangle - mangle);

        return min(ans , 360-ans);
    }
};