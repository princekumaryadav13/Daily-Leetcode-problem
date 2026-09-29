class Solution {
public:
    double getSlope(vector<int>& p1, vector<int>& p2) {
        if (p1[0] == p2[0]) {
            return INFINITY;
        }
        return (double)(p2[1] - p1[1]) / (p2[0] - p1[0]);
    }  
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=2){
            return n;

        }
        int res =1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double slope = getSlope(points[i],points[j]);
                int count =2;
                for(int k=j+1;k<n;k++){
                    if(slope == getSlope(points[i], points[k])){
                        count++;
                    }
                }
                res = max(res , count);
            }
        }
        return res;
    }
};