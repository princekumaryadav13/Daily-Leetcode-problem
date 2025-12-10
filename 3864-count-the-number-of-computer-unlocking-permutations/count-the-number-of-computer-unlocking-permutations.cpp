class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        long long result =1;
        for(int i=1;i<complexity.size();i++){
            if(complexity[i]<=complexity[0]){
                return 0;
            }
            result = result*i;
            result= result % 1000000007;
        }
        return result ;
    }
};