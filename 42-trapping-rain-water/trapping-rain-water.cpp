class Solution {
public:
    int trap(vector<int>& height) {
       int n = height.size();
       int water =0;
       int leftmax =0, rightmax=0,maxheight = height[0], idx =0;

       for(int i=1;i<n;i++){
        if(maxheight < height[i]){
            maxheight = height[i];
            idx = i;
        }
       }
       for(int i=0;i<idx;i++){
        if(leftmax >height[i]){
            water+= leftmax-height[i];

        }else{
            leftmax = height[i];
        }
       }
       for(int i= n-1;i>idx;i--){
        if(rightmax>height[i]){
            water += rightmax-height[i];
        }
        else{
            rightmax = height[i];
        }
       }
       return water;
    }
};