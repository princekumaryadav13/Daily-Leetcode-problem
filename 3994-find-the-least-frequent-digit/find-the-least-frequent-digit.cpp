class Solution {
public:
    int getLeastFrequentDigit(int n) {
        map<int,int>mp;
        while(n>0){
        int a = n%10;
        n =n/10;
        mp[a]++;
        }
        int ans = 0;;
        int freq = INT_MAX;
        for(auto b : mp){
            int c = b.second;
            int digit = b.first;
            if(c < freq){
                freq =c;
                ans = digit;
            }
        }
        return ans;
    }
};