class Solution {
public:
   
    int minPartitions(string s) {
        char a = *max_element(s.begin(),s.end());
        return a -'0';
    }
};