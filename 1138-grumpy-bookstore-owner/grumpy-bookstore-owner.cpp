class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
       int n = customers.size();

       int maxUnsatCust =0;
       int currUnsat = 0;

       for(int i=0;i<minutes;i++){
        currUnsat += customers[i]*grumpy[i];
       } 
       maxUnsatCust = currUnsat;

       int i=0;
       int j=minutes;

       while(j<n){
        currUnsat += customers[j]*grumpy[j];
        currUnsat -= customers[i]*grumpy[i];

        maxUnsatCust = max(maxUnsatCust , currUnsat);
        i++;
        j++;
       }
       int totalsat =  maxUnsatCust ;
       for(int i=0;i<n;i++ ){
        if(grumpy[i]==0){
            totalsat += customers[i];
        }
       }
       return totalsat;
    }
};