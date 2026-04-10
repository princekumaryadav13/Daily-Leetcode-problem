class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long>freq(26,0);
        int mod = 1000000007;

        for(char c : s){
            freq[c-'a']++;
        }
        while(t--){
           vector<long long>newfreq(26,0);

           for(int i=0;i<25;i++){
            newfreq[i+1] = freq[i];
           }
           newfreq[0]+= freq[25];
           newfreq[1]= (newfreq[1]+freq[25])%mod;

           freq = newfreq;
        }
        long long ans =0;
        for(int i=0;i<26;i++){
            ans=(ans+freq[i])%mod;
        }
        return ans;
    }
};