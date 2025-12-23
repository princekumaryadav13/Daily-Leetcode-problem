class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int binarysearch(vector<vector<int>>&events,int endtime){
        int l=0;
        int r=n-1;
        int result =n;

        while(l<=r){
            int mid = l+(r-l)/2;

            if(events[mid][0]>endtime){
                result = mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>>& events, int i, int count) {
        if (i == n || count == 2)
            return 0;

        if (dp[i][count] != -1 ) {
            return dp[i][count];
        }
        
        int nextvalidbinary = binarysearch(events,events[i][1]);
        int take = events[i][2] + solve(events,nextvalidbinary,count+1);
       
        

        int notTake = solve(events, i + 1, count);
       return dp[i][count]= max(take, notTake);

        
    }
    int maxTwoEvents(vector<vector<int>>& events) {
         sort(events.begin(), events.end()); // sort by start time
        n = events.size();
        dp.assign(n, vector<int>(3, -1));
        return solve(events, 0, 0);
    }
};