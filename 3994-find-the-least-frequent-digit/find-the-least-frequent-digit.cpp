class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> mp(10, -1);

        // count frequency
        while(n > 0){
            int d = n % 10;
            if(mp[d] == -1) mp[d] = 1;
            else mp[d]++;
            n /= 10;
        }

        int ans = 0;
        int mn = INT_MAX;

        // find least frequent digit
        for(int i = 0; i < 10; i++){
            if(mp[i] != -1 && mp[i] < mn){
                mn = mp[i];
                ans = i;
            }
        }

        return ans;
    }
};