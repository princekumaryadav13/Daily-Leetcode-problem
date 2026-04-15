class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int count =INT_MAX;
        vector<string>st=words;
        int n=words.size();
        for(int i=0;i<n;i++){
            if(words[i]==target){
                int coou = abs(i-startIndex);
               int  cou = min(coou , n-coou);
                count = min(count,cou);
            }
        }
        
      return count == INT_MAX ? -1:count;
    }
};