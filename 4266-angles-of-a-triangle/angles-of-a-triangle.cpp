class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(), sides.end());
        
        int a = sides[0], b = sides[1], c = sides[2];
        
        // Triangle validity check
        if (a + b <= c) return {};
        
        vector<double> ans;
        
        // Law of Cosines
        double A = acos((b*b + c*c - a*a) / (2.0 * b * c));
        double B = acos((a*a + c*c - b*b) / (2.0 * a * c));
        double C = acos((a*a + b*b - c*c) / (2.0 * a * b));
        
        // Convert radians to degrees
        double pi = acos(-1);
        A = A * 180.0 / pi;
        B = B * 180.0 / pi;
        C = C * 180.0 / pi;
        
        ans = {A, B, C};
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};