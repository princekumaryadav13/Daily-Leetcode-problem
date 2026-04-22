class Solution {
public:
    int strStr(string haystack, string needle) {
        int n= needle.size();
        int i=0,j=0;

        while(i<haystack.size()){
            if(needle == haystack.substr(i,n)){
                return i;
            }
            i++;
        }
        return -1;
    }
};