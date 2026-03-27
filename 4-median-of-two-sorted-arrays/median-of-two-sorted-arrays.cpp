class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       vector<int>arr=nums1;
       for(int i=0;i<nums2.size();i++){
          arr.push_back(nums2[i]);
       } 
       sort(arr.begin(),arr.end());
       int n = arr.size();
       double ans;
       if(n%2==0){
        ans = (arr[n/2]+arr[(n/2)-1])/2;
        if((arr[n/2]+arr[(n/2)-1])%2 !=0){
        ans +=0.5;
        }
       }
       else{
        ans = arr[(n/2)];
       }
       return ans;
    }
};