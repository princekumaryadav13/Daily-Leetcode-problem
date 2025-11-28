class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
         int x=0;
        for(int i=0;derived.size()>i;i++)
        {
            x=x^derived[i];
        }
        return x==0;
    }
};