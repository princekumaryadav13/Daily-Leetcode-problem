class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int ,int>events;

        for(vector<int> interval : intervals){
            events[interval[0]]++;
            events[interval[1]+1]--;

        }
        int curr=0;
        int maxcon =0;

        for( auto p : events){
            curr +=p.second;

            maxcon = max(maxcon,curr);
        }
        return maxcon;
    }
};